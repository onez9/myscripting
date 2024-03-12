New-NetFirewallRule -DisplayName "block dzen.ru" -Direction Outbound –LocalPort Any -Protocol Any -Action Block -RemoteAddress 62.217.160.2
Remove-NetFirewallRule -DisplayName "block dzen.ru"
Disable-NetFirewallRule -DisplayName "block dzen.ru"

New-NetFirewallRule -DisplayName "block nsn.fm" -Direction Outbound -LocalPort Any -RemoteAddress 92.53.72.164 -Protocol Any -Action Block

New-NetFirewallRule -DisplayName "ALLOW TCP PORT 80" -Direction inbound -Profile Any -Action Allow -LocalPort 80 -Protocol TCP




New-NetFirewallRule -DisplayName "DISABLE TCP PORT 2" -Direction outbound -Profile Any -Action Allow -LocalPort 22 -Protocol TCP

New-NetFirewallRule -DisplayName "DISABLE TCP PORT 22 right" -Direction inbound -Profile Any -Action Allow -LocalPort 22 -Protocol TCP

New-NetFirewallRule -DisplayName "Block 22 port" -Direction inbound -Profile Any -Action Block -LocalPort 22 -Protocol TCP

New-NetFirewallRule -DisplayName "disable outbound aimp" -Program "C:\Program Files (x86)\AIMP3\AIMP3.exe" -Description "block aimp" -Profile Any -Direction Outbound -Action Block
Get-Command -Module NetSecurity

Get-NetFirewallRule -Name SSHD # просмотр правил firewall

Start-Process -Verb RunAs powershell # запуск приложения в новом окне от имени администратора

Get-Service -name vm*|Select-Object * # получить свойства выбранных сервисов


# Следующая команда выводит службы, которые зависят от службы Spooler:
Get-Service -name Spooler -DependentServices

# Приведенная ниже команда выводит службы, необходимые для запуска службе Spooler:
Get-Service -name Spooler -RequiredServices


# получить список запущенных служб (сервисов)
Get-Service|Where-Object {$_.status -eq 'running'}

Get-Service|Where-Object {$_.starttype -eq 'manual'}


# The PrivateData property has all the color properties we are looking for.
$host.PrivateData


# список всех приложений на моём пк
Get-WmiObject -Class Win32_Product | Select-Object -Property Name


# суббота 22 8:30 сетевое администрирование # прошло
# напомнить про 21 слайд	# прошло

(Get-WmiObject Win32_Product -filter "Name='SecurityKISS VPN'").Uninstall()

netsh advfirewall set allprofiles state off # отключить брандмауер windows


netsh wlan show profile # "Список всех сетей к которым подключался"
netsh wlan delete profile name=* # забыть сеть

net share DOC4=C:\DOC4 /USERS:2 /REMARK:"общийресурс" # создать общий ресурс
#В большинстве случаев администраторы Window для управления NFTS разрешениями на файлы и 
#папки используют графический интерфейс File Explorer (свойства папки/файла -> вкладка Security/Безопасность) или 
#консольную утилиту icacls.