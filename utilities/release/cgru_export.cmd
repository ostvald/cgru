set "DEST=F:\cgru-data\exports\cgru-windows"

if exist "%DEST%" rd /s /q "%DEST%"

call export.cmd "%DEST%"

pause
