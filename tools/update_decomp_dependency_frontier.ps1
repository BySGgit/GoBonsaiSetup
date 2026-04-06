param(
    [string]$RepoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$decompDir = Join-Path $RepoRoot "decompiled"
$guidesDir = Join-Path $RepoRoot "GUIDES"
$manifestPath = Join-Path $guidesDir "decomp_master_manifest.csv"
$outCsv = Join-Path $guidesDir "decomp_dependency_frontier.csv"
$outMd = Join-Path $guidesDir "decomp_dependency_frontier.md"

if (-not (Test-Path -LiteralPath $manifestPath)) {
    throw "Manifest not found: $manifestPath. Run tools/update_decomp_manifest.ps1 first."
}

if (-not (Test-Path -LiteralPath $decompDir)) {
    throw "Decompiled directory not found: $decompDir"
}

$manifest = Import-Csv -LiteralPath $manifestPath
$mappedAny = [System.Collections.Generic.HashSet[string]]::new()
foreach ($row in $manifest) {
    $subRaw = if ($null -ne $row.sub) { [string]$row.sub } else { "" }
    $mappedRaw = if ($null -ne $row.mapped_any) { [string]$row.mapped_any } else { "" }
    $sub = $subRaw.ToLowerInvariant()
    $isMapped = $mappedRaw.ToLowerInvariant() -eq "yes"
    if ($sub -ne "" -and $isMapped) {
        [void]$mappedAny.Add($sub)
    }
}

$rx = [regex]'sub_[0-9A-Fa-f]{6}'
$files = Get-ChildItem -LiteralPath $decompDir -File -Filter "sub_*.c"

# callee -> {callSites, callers(set)}
$stats = @{}

foreach ($f in $files) {
    $source = [System.IO.Path]::GetFileNameWithoutExtension($f.Name).ToLowerInvariant()
    if (-not $mappedAny.Contains($source)) { continue }

    $text = Get-Content -LiteralPath $f.FullName -Raw
    $matches = $rx.Matches($text)
    if ($matches.Count -eq 0) { continue }

    foreach ($m in $matches) {
        $callee = $m.Value.ToLowerInvariant()
        if ($callee -eq $source) { continue }
        if ($mappedAny.Contains($callee)) { continue }

        if (-not $stats.ContainsKey($callee)) {
            $stats[$callee] = [pscustomobject]@{
                callee = $callee
                call_sites = 0
                callers = [System.Collections.Generic.HashSet[string]]::new()
            }
        }

        $entry = $stats[$callee]
        $entry.call_sites = [int]$entry.call_sites + 1
        [void]$entry.callers.Add($source)
    }
}

$rows = foreach ($kv in $stats.GetEnumerator()) {
    $e = $kv.Value
    [pscustomobject]@{
        callee = $e.callee
        mapped_callers = $e.callers.Count
        call_sites = $e.call_sites
        caller_list = (@($e.callers) | Sort-Object) -join ", "
    }
}

$sorted = $rows | Sort-Object -Property @{Expression="mapped_callers";Descending=$true}, @{Expression="call_sites";Descending=$true}, @{Expression="callee";Descending=$false}

$sorted | Export-Csv -LiteralPath $outCsv -NoTypeInformation -Encoding UTF8

$totalRows = @($sorted).Count
$top = @($sorted | Select-Object -First 100)

$md = @()
$md += "# Decomp Dependency Frontier (mapped -> unmapped)"
$md += ""
$md += "Generated: $(Get-Date -Format s)"
$md += ""
$md += '- Manifest: `GUIDES/decomp_master_manifest.csv`'
$md += "- Rows in frontier: $totalRows"
$md += ""
$md += "## Top 100 By Impact"
$md += ""
$md += "| callee | mapped callers | call sites | callers (sample) |"
$md += "| --- | ---: | ---: | --- |"

foreach ($r in $top) {
    $callerSample = ($r.caller_list -split ", " | Select-Object -First 8) -join ", "
    $md += "| $($r.callee) | $($r.mapped_callers) | $($r.call_sites) | $callerSample |"
}

$md += ""
$md += 'Full machine-readable table: `GUIDES/decomp_dependency_frontier.csv`.'

$md -join "`n" | Set-Content -LiteralPath $outMd -Encoding UTF8

Write-Host "Wrote:"
Write-Host " - $outCsv"
Write-Host " - $outMd"
