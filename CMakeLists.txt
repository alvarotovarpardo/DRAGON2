cmake_minimum_required(VERSION 3.25)
project(DRAGON2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Salidas ordenadas
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# MSVC flags útiles
if (MSVC)
  add_compile_options(/W4 /permissive- /Zc:__cplusplus)
endif()

add_subdirectory(src)
add_subdirectory(app/cli)
