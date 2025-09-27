@echo off
setlocal

REM --------------------------------------
REM Load configuration
REM --------------------------------------
call config.bat %1
if errorlevel 1 (
    echo Failed to load configuration.
    exit /b 1
)

REM --------------------------------------
REM Run Doxygen
REM --------------------------------------
doxygen "%BUILD_DIR%\Doxyfile"
if errorlevel 1 (
    echo Doxygen generation failed.
    exit /b 1
)

endlocal
