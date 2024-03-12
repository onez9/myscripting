@echo off



gpupdate.exe # средство обновления политики безопасности
net share # просмотр общих ресурсов
net share DOC4=C:\DOC4 /USERS:2 /REMARK:"общий ресурс" # создать общий ресурс