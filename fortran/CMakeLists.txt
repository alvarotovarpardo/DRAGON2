# Compilador esperado: Intel ifx/ifort
add_library(dragon2_fortran STATIC
    dragon2_f_api.f90
)

# Exportae modulo Fortran
# set_target_properties(dragon2_fortran PROPERTIES Fortran_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/mod)

target_include_directories(dragon2_fortran
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    # $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/mod>  # para .mod
)

if (MSVC)
  target_compile_options(dragon2_fortran PRIVATE /warn:all)
endif()

# Enlazar el core con la lib Fortran (hacerlo en src/CMakeLists.txt)
