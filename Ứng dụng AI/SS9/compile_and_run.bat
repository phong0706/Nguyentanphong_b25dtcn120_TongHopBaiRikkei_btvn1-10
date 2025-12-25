@echo off
chcp 65001 >nul
cd /d "%~dp0"
echo Compiling quiz_game.c...
gcc -o quiz_game.exe quiz_game.c
if errorlevel 1 (
    echo.
    echo [ERROR] Compilation failed!
    pause
    exit /b 1
)
echo Compilation successful!
echo.
echo Starting Quiz Game...
echo.
start "" quiz_game.exe

