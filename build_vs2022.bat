@echo off
echo Setting up Visual Studio 2022 Environment...
echo ===========================================

REM Set up Visual Studio 2022 environment
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

echo.
echo Environment set up. Testing compilation...
echo.

REM Compile the project
cl /std:c++17 /EHsc /W4 /Fe:LinkedList.exe main.cpp

if %errorlevel% == 0 (
    echo.
    echo Build successful! Executable: LinkedList.exe
    echo.
    echo To run the program, type: LinkedList.exe
) else (
    echo.
    echo Build failed. Please check the error messages above.
)

echo.
pause
