@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
echo Enter a directory.
exit /b
)
if "%~2"=="" (
echo Enter an extension.
exit /b
)

set total_size=0

for /r "%~1" %%f in (*%~2) do (
set /a total_size+=%%~zf
)

echo Size of all %~2: %total_size% byte.
pause