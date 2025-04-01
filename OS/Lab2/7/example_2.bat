@echo off

set max=
set min=
set input=

:loop
set /p "input=Write numbers (or - for end): "
if "%input%"=="-" goto :end

if "%max%"=="" (
  set max=%input%
  set min=%input%
  goto :loop
)

if %input% GTR %max% set max=%input%
if %input% LSS %min% set min=%input%

goto :loop

:end

echo Max Number: %max%
echo Min Number: %min%

pause