@echo off
setlocal

call build.bat %1

set TEST_EXE=%BUILD_DIR%\gamekit-tests\gamekit-tests.exe

if not exist "%TEST_EXE%" (
    echo Error: Test executable not found: %TEST_EXE%
    exit /b 1
)

"%TEST_EXE%"