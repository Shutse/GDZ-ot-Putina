@echo off

set count=0

for /d /r "%1" %%a in (.) do (
  set /a count+=1
)

echo Count folders in The Dir "%1": %count%

pause