@echo off

set num=%1

if %num% LSS 0 (
  echo Error
  goto :eof
)

if %num% GTR 17 (
  echo Number too big
  goto :eof
)

set factorial=1
set i=1

:loop
if %i% GTR %num% goto :end

set /a factorial=%factorial% * %i%
set /a i+=1

goto :loop

:end

echo Factoryal number %num% is %factorial%

pause