@echo off

set PROJECT_NAME=gamekit

set BUILD_DEBUG_DIR=build/windows/debug
set BUILD_RELEASE_DIR=build/windows/release
set BUILD_DIR=
set DOCS_DIR=docs

if "%1"=="" (
    set BUILD_DIR=%BUILD_DEBUG_DIR%
) else if "%1"=="release" (
    set BUILD_DIR=%BUILD_RELEASE_DIR%
) else (
    echo Unrecognized parameter: %1
    exit /b 1
)

echo PROJECT_NAME=%PROJECT_NAME%
echo BUILD_DIR=%BUILD_DIR%