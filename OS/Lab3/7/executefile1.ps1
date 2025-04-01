$cmdlets = "Get-ChildItem", "Get-Process"
$results = @()

foreach ($cmdlet in $cmdlets) {
    $times = @()
    for ($i = 1; $i -le 10; $i++) {
        $startTime = Get-Date
        $null = Invoke-Expression $cmdlet
        $endTime = Get-Date
        $elapsedTime = New-TimeSpan -Start $startTime -End $endTime
        $times += $elapsedTime.TotalMilliseconds
    }
    $stats = $times | Measure-Object -Minimum -Maximum -Average

    $result = [PSCustomObject]@{
        Cmdlet = $cmdlet
        Minimum = $stats.Minimum
        Maximum = $stats.Maximum
        Average = $stats.Average
    }
    $results += $result
}
$results | Format-Table -AutoSize