@echo off
setlocal

call config.bat

echo BUILD_DIR exists at %BUILD_DIR%

if exist "%BUILD_DIR%" (
    rmdir /s /q "%BUILD_DIR%"
)
