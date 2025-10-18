Desde la carpeta raiz de proyecto

# 1) Configurar
-- Instalar Fortran. Para Windows, Intel oneAPI Base Toolkit (sólo lo que incluye Fortran). Luego Intel oneAPI HPC Toolkit
 & "C:\Program Files (x86)\Intel\oneAPI\setvars.bat"
 cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH="C:/Qt/5.14.2/msvc2017_64" -DCMAKE_Fortran_COMPILER="C:/Program Files (x86)/Intel/oneAPI/compiler/latest/bin/ifx.exe"

# 2) Compilar (elige la config que vayas a instalar)
cmake --build build --config Release --target dragon2_cli


Ejecutar --> .\build\bin\Release\dragon2_cli.exe

Para generar ejecutable
# 3) Instalar a dist/
cmake --install build --config Release --prefix dist/DRAGON2

# 4) Generar el ejecutable portable con windeployqt
& "C:\Qt\Qt5.14.2\5.14.2\msvc2017_64\bin\windeployqt.exe" --release --compiler-runtime  --dir "dist\DRAGON2\bin" "dist\DRAGON2\bin\dragon2_gui.exe"
