@echo off
setlocal enabledelayedexpansion

echo Enter numbers. To stop enter "-".

set "max="
set "min="

:input_loop
set /p num=Enter yout number: 
if "%num%"=="-" goto end

if not defined max (
set max=%num%
set min=%num%
) else (
if %num% gtr !max! set max=%num%
if %num% lss !min! set min=%num%
)
goto input_loop

:end
echo Max: !max!
echo Min: !min!
pause