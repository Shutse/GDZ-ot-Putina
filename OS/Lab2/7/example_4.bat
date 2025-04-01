@echo off

echo Common files in dirs "%1" and "%2":

for %%a in ("%1\*") do (
  if exist "%2\%%~nxa" (
    echo %%~nxa
  )
)

pause