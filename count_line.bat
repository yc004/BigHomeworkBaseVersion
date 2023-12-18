@echo off
setlocal enabledelayedexpansion

set "totalLines=0"

for /r %%i in (*.c *.cpp *.h) do (
    set /a "lines=0"
    for /f %%j in ('type "%%i" ^| find /c /v ""') do set /a "lines+=%%j"
    set /a "totalLines+=lines"
    echo Lines in %%i: !lines!
)

echo Total lines: !totalLines!

endlocal
