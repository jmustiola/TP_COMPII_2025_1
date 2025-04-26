@echo off

REM Este script de Windows Batch compila un proyecto C++ utilizando CMake y MSBuild.
REM Asegúrate de que CMake y MSBuild estén en tu PATH antes de ejecutar este script.
REM Puedes ejecutar este script desde la línea de comandos de Windows o desde un archivo por lotes.

REM Eliminar el directorio de construcción si existe
if exist build rmdir /s /q build

REM Crear el directorio de construcción si no existe
if not exist build mkdir build

REM Entrar en el directorio de construcción
cd build

REM Generar los archivos de construcción con CMake
cmake ..

REM Compilar el proyecto
cmake --build .

REM Ejecutar el proyecto compilado (opcional)
REM .\build\Debug\NombreDelEjecutable.exe
REM Puedes descomentar la línea anterior y reemplazar "NombreDelEjecutable.exe" con el nombre de tu ejecutable.

REM Salir del directorio de construcción
cd ..

echo Compilacion completada.

REM Verificar si el flag --run está presente
if "%1"=="--run" (
    echo Ejecutando el proyecto...
    start build\Debug\tp_computacion_II.exe
) else (
    echo ""
    echo Para ejecutar el proyecto, usa el flag --run.
    echo Ejemplo: build.bat --run
)

REM Salir del script
exit /b 0