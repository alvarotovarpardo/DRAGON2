mkdir build; cd build; 
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH="C:\Qt\5.14.2\msvc2017_64" ..
cmake --build . --config Release