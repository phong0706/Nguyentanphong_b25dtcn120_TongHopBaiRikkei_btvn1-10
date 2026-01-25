@echo off
chcp 65001 >nul
echo ========================================
echo    QUIZ GAME - Bien dich va chay
echo ========================================
echo.
echo Dang bien dich chuong trinh...
gcc -o quiz_game.exe quiz_game.c -Wall 2>nul
if %errorlevel% equ 0 (
    echo [OK] Bien dich thanh cong!
    echo.
    echo Dang chay chuong trinh...
    echo.
    quiz_game.exe
) else (
    echo.
    echo [LOI] Bien dich that bai!
    echo.
    echo Nguyen nhan co the:
    echo - File quiz_game.exe dang duoc su dung (dang chay)
    echo - Khong co quyen ghi file
    echo - File quiz_game.c khong ton tai
    echo.
    echo Giai phap:
    echo 1. Dong chuong trinh quiz_game.exe neu dang chay
    echo 2. Chay Command Prompt voi quyen Administrator
    echo 3. Xoa file quiz_game.exe cu va thu lai
    echo 4. Kiem tra file quiz_game.c co trong thu muc khong
    echo.
    pause
)

