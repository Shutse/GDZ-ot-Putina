@echo off
setlocal enabledelayedexpansion

if not exist "%~1" (
echo Cant find "%~1".
exit /b
)

if "%~2"=="" (
echo Enter string num for first file.
exit /b
)
if "%~3"=="" (
echo Enter string num for second file.
exit /b
)
if "%~4"=="" (
echo Enter string num for third file.
exit /b
)

echo %~2|findstr /r "^[0-9]*$" >nul
if errorlevel 1 (
echo Entera number.
exit /b
)
echo %~3|findstr /r "^[0-9]*$" >nul
if errorlevel 1 (
echo Enter a number.
exit /b
)
echo %~4|findstr /r "^[0-9]*$" >nul
if errorlevel 1 (
echo Enter a number.
exit /b
)

set line_count=0
set file_num=1

for /f "tokens=*" %%l in (%~1) do (
set /a line_count+=1

if !line_count! leq %~2 (
echo %%l >>1.txt
) else if !line_count! leq %~2+%~3 (
echo %%l >>2.txt
) else (
echo %%l >>3.txt
)
)

echo Success! 1.txt, 2.txt and 3.txt were created.
pause