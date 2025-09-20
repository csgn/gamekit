@echo off

call config.bat %1

setlocal

REM Find and prepare Visual Studio environment if exist
for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set VS_PATH=%%i

if defined VS_PATH (
    echo Found Visual Studio at %VS_PATH%
    call "%VS_PATH%\VC\Auxiliary\Build\vcvars64.bat"
    set GENERATOR=Ninja
) else (
    echo Visual Studio not found, trying MinGW...
    set GENERATOR=MinGW Makefiles
)

REM Build
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

REM CMake configure
if defined VS_PATH (
    cmake -S . -B %BUILD_DIR% -G "%GENERATOR%" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
) else (
    cmake -S . -B %BUILD_DIR% -G "%GENERATOR%" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
)

REM Build
cmake --build %BUILD_DIR%

endlocal