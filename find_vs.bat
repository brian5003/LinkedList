@echo off
echo Searching for Visual Studio installations...
echo ========================================

REM Search for Visual Studio in common locations
set VS_FOUND=0

REM Check Program Files (64-bit)
if exist "C:\Program Files\Microsoft Visual Studio" (
    echo Found Visual Studio in: C:\Program Files\Microsoft Visual Studio
    dir "C:\Program Files\Microsoft Visual Studio" /b
    echo.
)

REM Check Program Files (x86)
if exist "C:\Program Files (x86)\Microsoft Visual Studio" (
    echo Found Visual Studio in: C:\Program Files (x86)\Microsoft Visual Studio
    dir "C:\Program Files (x86)\Microsoft Visual Studio" /b
    echo.
)

REM Check for specific versions
set VS_VERSIONS=2022 2019 2017 2015 2013

for %%v in (%VS_VERSIONS%) do (
    if exist "C:\Program Files\Microsoft Visual Studio\%%v" (
        echo Found VS %%v in: C:\Program Files\Microsoft Visual Studio\%%v
        dir "C:\Program Files\Microsoft Visual Studio\%%v" /b
        echo.
    )
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\%%v" (
        echo Found VS %%v in: C:\Program Files (x86)\Microsoft Visual Studio\%%v
        dir "C:\Program Files (x86)\Microsoft Visual Studio\%%v" /b
        echo.
    )
)

REM Try to find and run vcvarsall.bat
echo.
echo Searching for vcvarsall.bat...
echo.

for %%v in (%VS_VERSIONS%) do (
    if exist "C:\Program Files\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvarsall.bat" (
        echo Found vcvarsall.bat: C:\Program Files\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvarsall.bat
        echo Setting up environment...
        call "C:\Program Files\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
        set VS_FOUND=1
        goto :found
    )
    if exist "C:\Program Files\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvarsall.bat" (
        echo Found vcvarsall.bat: C:\Program Files\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvarsall.bat
        echo Setting up environment...
        call "C:\Program Files\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64
        set VS_FOUND=1
        goto :found
    )
    if exist "C:\Program Files\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" (
        echo Found vcvarsall.bat: C:\Program Files\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvarsall.bat
        echo Setting up environment...
        call "C:\Program Files\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64
        set VS_FOUND=1
        goto :found
    )
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvarsall.bat" (
        echo Found vcvarsall.bat: C:\Program Files (x86)\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvarsall.bat
        echo Setting up environment...
        call "C:\Program Files (x86)\Microsoft Visual Studio\%%v\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
        set VS_FOUND=1
        goto :found
    )
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvarsall.bat" (
        echo Found vcvarsall.bat: C:\Program Files (x86)\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvarsall.bat
        echo Setting up environment...
        call "C:\Program Files (x86)\Microsoft Visual Studio\%%v\Professional\VC\Auxiliary\Build\vcvarsall.bat" x64
        set VS_FOUND=1
        goto :found
    )
    if exist "C:\Program Files (x86)\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" (
        echo Found vcvarsall.bat: C:\Program Files (x86)\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvarsall.bat
        echo Setting up environment...
        call "C:\Program Files (x86)\Microsoft Visual Studio\%%v\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64
        set VS_FOUND=1
        goto :found
    )
)

:found
if %VS_FOUND% == 1 (
    echo.
    echo Visual Studio environment set up successfully!
    echo.
    echo Testing compilation...
    cl /std:c++17 /EHsc /W4 /Fe:LinkedList.exe main.cpp
    if %errorlevel% == 0 (
        echo.
        echo Build successful! You can now run: LinkedList.exe
    ) else (
        echo.
        echo Build failed. Please check the error messages above.
    )
) else (
    echo.
    echo No Visual Studio environment found!
    echo.
    echo Please do one of the following:
    echo.
    echo 1. Open "Developer Command Prompt for VS" from Start Menu
    echo    - Search for "Developer Command Prompt for VS"
    echo    - Navigate to your project directory
    echo    - Run: cl /std:c++17 /EHsc /W4 /Fe:LinkedList.exe main.cpp
    echo.
    echo 2. Or use the online compiler as a quick alternative:
    echo    - Visit: https://www.onlinegdb.com/online_c++_compiler
    echo    - Copy main.cpp and LinkedList.h content
    echo    - Paste and run online
)

echo.
pause
