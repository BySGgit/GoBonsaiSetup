$ErrorActionPreference = "Stop"

$root = Split-Path -Parent $PSScriptRoot
$guidesDir = Join-Path $root "GUIDES"
$decompiledDir = Join-Path $root "decompiled"
$mapPath = Join-Path $guidesDir "sub_to_ts_coverage_map.md"
$csvOut = Join-Path $guidesDir "decomp_master_manifest.csv"
$summaryOut = Join-Path $guidesDir "decomp_master_manifest_summary.md"

if (!(Test-Path $decompiledDir)) {
    throw "Missing directory: $decompiledDir"
}
if (!(Test-Path $mapPath)) {
    throw "Missing file: $mapPath"
}

$decompFiles = Get-ChildItem -Recurse -File (Join-Path $decompiledDir "sub_*.c")
$decompRows = $decompFiles | ForEach-Object {
    [PSCustomObject]@{
        Sub = [System.IO.Path]::GetFileNameWithoutExtension($_.Name).ToLower()
        DecompiledPath = $_.FullName
    }
}

$mapText = Get-Content -Encoding UTF8 $mapPath -Raw
$mappedAnySet = New-Object 'System.Collections.Generic.HashSet[string]'
[regex]::Matches($mapText, 'sub_[0-9A-Fa-f]{6}') | ForEach-Object {
    [void]$mappedAnySet.Add($_.Value.ToLower())
}

$statusMap = @{}
$mapLines = Get-Content -Encoding UTF8 $mapPath
foreach ($line in $mapLines) {
    if ($line -notmatch '^\|\s*`sub_[0-9A-Fa-f]{6}`') { continue }
    $parts = $line -split '\|'
    if ($parts.Count -lt 4) { continue }
    $subCell = $parts[1].Trim().Trim('`').ToLower()
    $tsCell = $parts[2].Trim().Trim('`')
    $statusCell = $parts[3].Trim()
    if ($subCell -notmatch '^sub_[0-9a-f]{6}$') { continue }
    if (-not $statusMap.ContainsKey($subCell)) {
        $statusMap[$subCell] = [PSCustomObject]@{
            Ts = $tsCell
            Status = $statusCell
        }
    }
}

$rows = foreach ($d in $decompRows) {
    $mappedAny = $mappedAnySet.Contains($d.Sub)
    $hasStatus = $statusMap.ContainsKey($d.Sub)
    $s = if ($hasStatus) { $statusMap[$d.Sub] } else { $null }
    [PSCustomObject]@{
        sub = $d.Sub
        mapped_any = if ($mappedAny) { "yes" } else { "no" }
        status_known = if ($hasStatus) { "yes" } else { "no" }
        status = if ($hasStatus) { $s.Status } else { "" }
        ts = if ($hasStatus) { $s.Ts } else { "" }
        decompiled_path = $d.DecompiledPath
    }
}

$rows | Sort-Object sub | Export-Csv -NoTypeInformation -Encoding UTF8 $csvOut

$total = $rows.Count
$mappedAnyCount = ($rows | Where-Object mapped_any -eq "yes").Count
$notMentionedCount = ($rows | Where-Object mapped_any -eq "no").Count
$statusKnownCount = ($rows | Where-Object status_known -eq "yes").Count
$mentionedNoStatusCount = $mappedAnyCount - $statusKnownCount

$summary = @()
$summary += "# Decomp Master Manifest (seed)"
$summary += ""
$summary += "- Total decompiled sub_*: $total"
$summary += "- Mentioned in sub_to_ts_coverage_map (any context): $mappedAnyCount"
$summary += "- Not mentioned in map: $notMentionedCount"
$summary += "- With explicit status row in map: $statusKnownCount"
$summary += "- Mentioned without explicit status row: $mentionedNoStatusCount"
$summary += ""
$summary += "## Status breakdown (explicit rows only)"
$summary += ""
$summary += "| Status | Count |"
$summary += "|---|---:|"
($rows | Where-Object status_known -eq "yes" | Group-Object status | Sort-Object Name) | ForEach-Object {
    $summary += "| $($_.Name) | $($_.Count) |"
}
$summary += ""
$summary += "## Notes"
$summary += ""
$summary += "- This is an initial inventory snapshot for parity planning."
$summary += "- Source mapping: GUIDES/sub_to_ts_coverage_map.md."
$summary += "- mapped_any=yes means function name appears in map text; not equal to verified parity."

$summary | Set-Content -Encoding UTF8 $summaryOut

Write-Output "Wrote $csvOut"
Write-Output "Wrote $summaryOut"
