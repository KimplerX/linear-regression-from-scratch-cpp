@echo off
echo ==========================================
echo      "Starting Build&Test Process..."
echo ==========================================

cd ..
if not exist build mkdir build
cd build
if not exist tests mkdir tests
cd tests
cmake ../../tests -G "MinGW Makefiles"
cmake --build .

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Build failed! Fix errors and try again.
    pause
    exit /b %errorlevel%
)

call DataLoader_unittest.exe

echo.
echo "[SUCCESS] Build&Test complete. Running program..."
echo ==========================================
echo.

pause