@echo off
echo Setting up Visual Studio Environment...
echo =====================================

REM Try to find and run the Visual Studio environment setup
set VS_FOUND=0

REM Common Visual Studio installation paths
set VS_PATHS=^
"C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat" ^
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat"

for %%i in (%VS_PATHS%) do (
    if exist "%%i" (
        echo Found Visual Studio at: %%i
        echo Setting up environment...
        call "%%i"
        set VS_FOUND=1
        goto :found
    )
)

:found
if %VS_FOUND% == 1 (
    echo.
    echo Visual Studio environment set up successfully!
    echo.
    echo Now you can build the project:
    echo cl /std:c++17 /EHsc /W4 /Fe:LinkedList.exe main.cpp
    echo.
    echo Or run the build script again:
    echo simple_build.bat
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
    echo Visual Studio environment setup not found!
    echo.
    echo Please do one of the following:
    echo.
    echo 1. Open "Developer Command Prompt for VS" from Start Menu
    echo    - Search for "Developer Command Prompt for VS"
    echo    - Navigate to your project directory
    echo    - Run: cl /std:c++17 /EHsc /W4 /Fe:LinkedList.exe main.cpp
    echo.
    echo 2. Or manually set up the environment:
    echo    - Find your Visual Studio installation
    echo    - Run: "C:\Path\To\VS\Common7\Tools\VsDevCmd.bat"
    echo    - Then build your project
    echo.
    echo 3. Or use the online compiler as a quick alternative:
    echo    - Visit: https://www.onlinegdb.com/online_c++_compiler
    echo    - Copy main.cpp and LinkedList.h content
    echo    - Paste and run online
)

echo.
pause
