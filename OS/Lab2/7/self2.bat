@echo off
setlocal enabledelayedexpansion

SET "spaces=          "

set "name=numbers.txt"
set "itog=itog.txt"
set "dir=%1"

set "dir=%dir:~1,-1%"
set "dir=%dir%\%name%"


echo %dir%
echo %name%

set count=

if not exist "%dir%" goto :err

for /f "TOKENS=1,2* DELIMS= " %%a in ('findstr /v "^[0-9]*$" "%dir%"') do (
set /a first=%%a
set /a second=%%b
call :tabs !first! !second! 10
)
goto :eof

:err
echo Error: File not found!

:tabs
set /a "count=%1+%2"
CALL SET f=%1%spaces%
CALL SET f=%%f:~0,10%%
CALL SET s=%2%spaces%
CALL SET s=%%s:~0,10%%
echo %f%+%s%=%count% >> itog.txt

endlocal