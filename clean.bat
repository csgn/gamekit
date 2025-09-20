@echo off
setlocal

call config.bat %1

echo BUILD_DIR exists at %BUILD_DIR%

if exist "%BUILD_DIR%" (
    rmdir /s /q "%BUILD_DIR%"
)

if exist "%DOCS_DIR%\html" (
    rmdir /s /q "%DOCS_DIR%\html"
)