param(
    [string]$RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$decompDir = Join-Path $RepoRoot "decompiled"
$guidesDir = Join-Path $RepoRoot "GUIDES"
$manifestPath = Join-Path $guidesDir "decomp_master_manifest.csv"
$outCsv = Join-Path $guidesDir "decomp_runtime_parity_queue.csv"
$outMd = Join-Path $guidesDir "decomp_runtime_parity_queue.md"

if (-not (Test-Path -LiteralPath $decompDir)) {
    throw "Missing decompiled directory: $decompDir"
}
if (-not (Test-Path -LiteralPath $manifestPath)) {
    throw "Missing manifest: $manifestPath. Run tools/update_decomp_manifest.ps1 first."
}

$runtimeRoots = @(
    "sub_40dc90",
    "sub_4143e0",
    "sub_416510",
    "sub_417c90",
    "sub_417ff0",
    "sub_4188e0",
    "sub_40e0a0",
    "sub_40e230",
    "sub_40e460",
    "sub_40eee0",
    "sub_40f140",
    "sub_414ce0",
    "sub_414e10",
    "sub_408a30",
    "sub_408d60"
) | ForEach-Object { $_.ToLowerInvariant() }

$manifest = Import-Csv -LiteralPath $manifestPath
$manifestBySub = @{}
$mappedSet = [System.Collections.Generic.HashSet[string]]::new()
foreach ($row in $manifest) {
    $sub = ([string]$row.sub).ToLowerInvariant()
    if ($sub -eq "") { continue }
    $manifestBySub[$sub] = $row
    if (([string]$row.mapped_any).ToLowerInvariant() -eq "yes") {
        [void]$mappedSet.Add($sub)
    }
}

$files = Get-ChildItem -LiteralPath $decompDir -File -Filter "sub_*.c"
$allSubs = [System.Collections.Generic.HashSet[string]]::new()
$outEdges = @{}               # sub -> HashSet[callee]
$callersByCallee = @{}        # callee -> HashSet[caller]
$pairCallSites = @{}          # "caller->callee" -> int
$calleeCallSites = @{}        # callee -> int
$calleeMappedCallSites = @{}  # callee -> int (where caller is mapped_any=yes)

$rx = [regex]'sub_[0-9A-Fa-f]{6}'

foreach ($f in $files) {
    $caller = [System.IO.Path]::GetFileNameWithoutExtension($f.Name).ToLowerInvariant()
    [void]$allSubs.Add($caller)

    if (-not $outEdges.ContainsKey($caller)) {
        $outEdges[$caller] = [System.Collections.Generic.HashSet[string]]::new()
    }

    $text = Get-Content -LiteralPath $f.FullName -Raw
    $matches = $rx.Matches($text)
    foreach ($m in $matches) {
        $callee = $m.Value.ToLowerInvariant()
        if ($callee -eq $caller) { continue }

        [void]$allSubs.Add($callee)
        [void]$outEdges[$caller].Add($callee)

        if (-not $callersByCallee.ContainsKey($callee)) {
            $callersByCallee[$callee] = [System.Collections.Generic.HashSet[string]]::new()
        }
        [void]$callersByCallee[$callee].Add($caller)

        $pairKey = "$caller->$callee"
        if (-not $pairCallSites.ContainsKey($pairKey)) { $pairCallSites[$pairKey] = 0 }
        $pairCallSites[$pairKey] = [int]$pairCallSites[$pairKey] + 1

        if (-not $calleeCallSites.ContainsKey($callee)) { $calleeCallSites[$callee] = 0 }
        $calleeCallSites[$callee] = [int]$calleeCallSites[$callee] + 1

        if ($mappedSet.Contains($caller)) {
            if (-not $calleeMappedCallSites.ContainsKey($callee)) { $calleeMappedCallSites[$callee] = 0 }
            $calleeMappedCallSites[$callee] = [int]$calleeMappedCallSites[$callee] + 1
        }
    }
}

# Reachability from runtime-critical roots over callgraph.
$distance = @{}
$queue = New-Object System.Collections.Queue
foreach ($root in $runtimeRoots) {
    if (-not $allSubs.Contains($root)) { continue }
    if (-not $distance.ContainsKey($root)) {
        $distance[$root] = 0
        [void]$queue.Enqueue($root)
    }
}

while ($queue.Count -gt 0) {
    $cur = [string]$queue.Dequeue()
    $curDepth = [int]$distance[$cur]
    if (-not $outEdges.ContainsKey($cur)) { continue }
    foreach ($next in $outEdges[$cur]) {
        if (-not $distance.ContainsKey($next)) {
            $distance[$next] = $curDepth + 1
            [void]$queue.Enqueue($next)
        }
    }
}

function Get-IntOrZero {
    param([hashtable]$Map, [string]$Key)
    if ($Map.ContainsKey($Key)) { return [int]$Map[$Key] }
    return 0
}

function Compute-Phase {
    param(
        [bool]$MappedAny,
        [bool]$Reachable,
        [int]$Depth,
        [int]$MappedCallers
    )
    if ($MappedAny) { return "mapped" }
    if (-not $Reachable) { return "P3-unreached" }
    if ($Depth -eq 1 -and $MappedCallers -ge 3) { return "P0-A" }
    if ($Depth -le 2 -and $MappedCallers -ge 2) { return "P0-B" }
    if ($Depth -le 2) { return "P1" }
    return "P2"
}

function Compute-Priority {
    param(
        [bool]$MappedAny,
        [bool]$Reachable,
        [int]$Depth,
        [int]$MappedCallers,
        [int]$MappedCallSites,
        [int]$RuntimeCallers,
        [int]$TotalCallSites,
        [string]$Sub
    )
    if ($MappedAny) { return 0.0 }
    $score = 0.0
    if ($Reachable) {
        if ($Depth -eq 1) { $score += 1000.0 }
        elseif ($Depth -eq 2) { $score += 600.0 }
        elseif ($Depth -eq 3) { $score += 300.0 }
        else { $score += 100.0 / ([double]($Depth + 1)) }
    }
    $score += [double]$MappedCallers * 40.0
    $score += [double]$MappedCallSites * 5.0
    $score += [double]$RuntimeCallers * 20.0
    $score += [double]$TotalCallSites

    if ($Sub -like "sub_472*") {
        $score -= 400.0
    }
    return [math]::Round($score, 2)
}

$rows = foreach ($sub in (@($allSubs) | Sort-Object)) {
    $mappedAny = $mappedSet.Contains($sub)
    $reachable = $distance.ContainsKey($sub)
    $depth = if ($reachable) { [int]$distance[$sub] } else { -1 }

    $callerList = if ($callersByCallee.ContainsKey($sub)) { @($callersByCallee[$sub]) } else { @() }
    $directCallers = @($callerList).Count
    $mappedCallers = @(@($callerList) | Where-Object { $mappedSet.Contains($_) }).Count
    $runtimeCallers = @(@($callerList) | Where-Object { $distance.ContainsKey($_) }).Count

    $totalCallSites = Get-IntOrZero -Map $calleeCallSites -Key $sub
    $mappedCallSites = Get-IntOrZero -Map $calleeMappedCallSites -Key $sub

    $phase = Compute-Phase -MappedAny $mappedAny -Reachable $reachable -Depth $depth -MappedCallers $mappedCallers
    $priority = Compute-Priority -MappedAny $mappedAny -Reachable $reachable -Depth $depth -MappedCallers $mappedCallers -MappedCallSites $mappedCallSites -RuntimeCallers $runtimeCallers -TotalCallSites $totalCallSites -Sub $sub

    $statusKnown = ""
    $status = ""
    $ts = ""
    if ($manifestBySub.ContainsKey($sub)) {
        $row = $manifestBySub[$sub]
        $statusKnown = [string]$row.status_known
        $status = [string]$row.status
        $ts = [string]$row.ts
    }

    $sampleCallers = (@($callerList) | Sort-Object | Select-Object -First 8) -join ", "

    [pscustomobject]@{
        sub = $sub
        mapped_any = if ($mappedAny) { "yes" } else { "no" }
        status_known = $statusKnown
        status = $status
        ts = $ts
        reachable_from_runtime = if ($reachable) { "yes" } else { "no" }
        runtime_depth = if ($reachable) { $depth } else { "" }
        phase = $phase
        priority_score = $priority
        direct_callers = $directCallers
        direct_mapped_callers = $mappedCallers
        direct_runtime_callers = $runtimeCallers
        total_call_sites = $totalCallSites
        mapped_call_sites = $mappedCallSites
        caller_sample = $sampleCallers
    }
}

$sorted = $rows | Sort-Object -Property @{Expression="priority_score";Descending=$true}, @{Expression="direct_mapped_callers";Descending=$true}, @{Expression="total_call_sites";Descending=$true}, @{Expression="sub";Descending=$false}
$sorted | Export-Csv -LiteralPath $outCsv -NoTypeInformation -Encoding UTF8

$unmapped = @($sorted | Where-Object { $_.mapped_any -eq "no" })
$top = @($unmapped | Select-Object -First 60)
$phaseCounts = $unmapped | Group-Object phase | Sort-Object Name

$md = @()
$md += "# Runtime Parity Queue (full decomp audit)"
$md += ""
$md += "Generated: $(Get-Date -Format s)"
$md += ""
$md += '- Inputs: `decompiled/sub_*.c`, `GUIDES/decomp_master_manifest.csv`'
$md += "- Total sub_* discovered: $(@($sorted).Count)"
$md += "- Unmapped: $(@($unmapped).Count)"
$md += "- Runtime roots used: $((@($runtimeRoots) -join ", "))"
$md += ""
$md += "## Unmapped by phase"
$md += ""
$md += "| phase | count |"
$md += "| --- | ---: |"
foreach ($g in $phaseCounts) {
    $md += "| $($g.Name) | $($g.Count) |"
}
$md += ""
$md += "## Top 60 execution queue"
$md += ""
$md += "| sub | phase | score | depth | mapped callers | mapped call sites | total call sites | sample callers |"
$md += "| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |"
foreach ($r in $top) {
    $md += "| $($r.sub) | $($r.phase) | $($r.priority_score) | $($r.runtime_depth) | $($r.direct_mapped_callers) | $($r.mapped_call_sites) | $($r.total_call_sites) | $($r.caller_sample) |"
}
$md += ""
$md += 'Machine-readable queue: `GUIDES/decomp_runtime_parity_queue.csv`.'
$md += ""
$md += 'Recommendation: execute in strict order by `phase` then `priority_score`.'

$md -join "`n" | Set-Content -LiteralPath $outMd -Encoding UTF8

Write-Host "Wrote:"
Write-Host " - $outCsv"
Write-Host " - $outMd"
