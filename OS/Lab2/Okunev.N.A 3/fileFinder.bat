@echo off
if "%~1"=="" (
echo Enter a path.
exit /b
)
if "%~2"=="" (
echo Enter an extension.
exit /b
)

set "directory=%~1"
set "extension=%~2"

echo File %extension% in %directory%:
for /r "%directory%" %%f in (*%extension%) do (
echo %%f
)

pause