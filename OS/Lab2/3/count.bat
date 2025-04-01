@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
echo Enter a path.
exit /b
)

set count=0


for /d /r "%~1" %%d in (*) do (
set /a count+=1
)

echo %count%