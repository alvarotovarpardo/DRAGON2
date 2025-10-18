# Librería central en C++
add_library(dragon2_core STATIC
    core/hello.cpp
    ../src/core/fwrap.cpp 
)

target_include_directories(dragon2_core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(dragon2_core PUBLIC dragon2_fortran)
