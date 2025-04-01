@echo off
setlocal enabledelayedexpansion

set target_date=20221130

echo DLL files, created before December 2022, with size under 12000 bytes:

for /r %%a in (*.dll) do (
  for /f "delims=" %%b in ("%%~ta") do (
    set full_date=%%b
    set "file_size=%%~za"

    set file_date=!full_date:~6,4!!full_date:~3,2!!full_date:~0,2!

    :: !file_date!-%%a
    if !file_date! LSS %target_date% (
      if !file_size! LSS 12000 (
        echo   %%a ^(Size: !file_size! bytes, Create date: %%~ta^)
      )
    )
  )
)

endlocal
pause