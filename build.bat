@echo off
echo ==========================================
echo      Starting Build Process...
echo ==========================================

if not exist build mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Build failed! Fix errors and try again.
    pause
    exit /b %errorlevel%
)

echo.
echo [SUCCESS] Build complete!
echo ==========================================
echo.

pause