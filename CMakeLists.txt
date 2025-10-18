cmake_minimum_required(VERSION 3.25)
project(DRAGON2 LANGUAGES CXX Fortran)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Autos for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Salidas ordenadas
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# MSVC flags útiles
if (MSVC)
  add_compile_options(
    $<$<COMPILE_LANGUAGE:CXX>:/W4>
    $<$<COMPILE_LANGUAGE:CXX>:/permissive->
    $<$<COMPILE_LANGUAGE:CXX>:/Zc:__cplusplus>
  )
endif()

add_subdirectory(src)
add_subdirectory(app/cli)
add_subdirectory(fortran)
add_subdirectory(app/gui)

include(GNUInstallDirs)

# Instalar librería core (SHARED -> quedará en lib/bin)
install(TARGETS dragon2_core
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Instalar GUI
install(TARGETS dragon2_gui
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# (Opcional) Instalar CLI
# install(TARGETS dragon2_cli RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})