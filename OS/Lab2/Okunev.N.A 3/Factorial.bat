@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
echo Enter a number.
exit /b
)

echo %~1|findstr /r "^[0-9]*$" >nul
if errorlevel 1 (
echo Enter an int number.
exit /b
)

if %~1 lss 0 (
echo Factorial is undefined.
exit /b
)

if %~1 gtr 20 (
echo Number is too big for batch.
exit /b
)

set fact=1
for /l %%i in (1,1,%~1) do (
set /a fact*=%%i
)

echo Factorial %~1: !fact!
pause