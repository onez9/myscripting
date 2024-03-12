


Function BlockSiteHosts ( [Parameter(Mandatory=$true)]$Url) {
	$hosts = 'C:\Windows\System32\drivers\etc\hosts'
	$is_blocked = Get-Content -Path $hosts |
	Select-String -Pattern ([regex]::Escape($Url))
	If(-not $is_blocked) {
	$hoststr="127.0.0.1 " + $Url
	Add-Content -Path $hosts -Value $hoststr
	}
}

Function UnBlockSiteHosts ( [Parameter(Mandatory=$true)]$Url) {
	$hosts = 'C:\Windows\System32\drivers\etc\hosts'
	$is_blocked = Get-Content -Path $hosts |
	Select-String -Pattern ([regex]::Escape($Url))
	If($is_blocked) {
	$newhosts = Get-Content -Path $hosts |
	Where-Object {
	$_ -notmatch ([regex]::Escape($Url))
	}
	Set-Content -Path $hosts -Value $newhosts
	}
}






