@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
echo Enter first directory.
exit /b
)
if "%~2"=="" (
echo Enter seccond directory.
exit /b
)

for %%f in ("%~1\*.*") do (
if exist "%~2\%%~nxf" echo %%~nxf
)