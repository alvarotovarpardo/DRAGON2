# Librería central en C++
add_library(dragon2_core STATIC
    core/hello.cpp
)

target_include_directories(dragon2_core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

# Aquí, en el futuro, añadiremos más fuentes C++ del proyecto.
# De momento, EXCLUIMOS Fortran/Autotools por portabilidad en Windows.
