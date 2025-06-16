@echo off
setlocal

set PRG=%1
set PRG=%PRG:.c=%
:: don't show notice, debug info, msvcrt debug version, disable microsoft extensions, all warnings, warnings as errors, ignore scanf
set CFLAGS=/nologo /Zi /MDd /Za /W4 /WX /wd4996
call :ex cl %CFLAGS% /Fe%PRG% %* || exit /b errorlevel
call :ex .\%PRG% || exit /b errorlevel
exit /b

:ex
echo %*
%* || exit /b errorlevel
goto :eof