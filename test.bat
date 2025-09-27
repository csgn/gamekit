@echo off
setlocal

REM --------------------------------------
REM Build the project
REM --------------------------------------
call build.bat %1
if errorlevel 1 (
    echo Build failed, aborting.
    exit /b 1
)

REM --------------------------------------
REM Run C++ tests
REM --------------------------------------
cd /d "%TESTS_OUTPUT_DIR%"
ctest
if errorlevel 1 (
    echo C++ tests failed.
    exit /b 1
)

REM --------------------------------------
REM Run C# tests
REM --------------------------------------
set "OLD_LD_LIBRARY_PATH=%LD_LIBRARY_PATH%"
set "LD_LIBRARY_PATH=%CSHARP_OUTPUT_DIR%\bin;%LD_LIBRARY_PATH%"

dotnet test "%CSHARP_TEST_CSPROJ_PATH%" -o "%CSHARP_TEST_OUTPUT_DIR%"
if errorlevel 1 (
    echo C# tests failed.
    exit /b 1
)

REM --------------------------------------
REM Restore LD_LIBRARY_PATH
REM --------------------------------------
set "LD_LIBRARY_PATH=%OLD_LD_LIBRARY_PATH%"

endlocal
