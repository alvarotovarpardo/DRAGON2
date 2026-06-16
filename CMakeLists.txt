cmake_minimum_required(VERSION 3.20)

project(DRAGON2 VERSION 3.1.0 LANGUAGES C CXX Fortran)

include(GNUInstallDirs)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_compile_definitions(_USE_MATH_DEFINES)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(GSL CONFIG REQUIRED)
find_package(cfitsio CONFIG REQUIRED)

add_subdirectory(cparamlib)

add_library(tinyxml STATIC
    tinystr.cc
    tinyxml.cc
    tinyxmlerror.cc
    tinyxmlparser.cc
)

target_include_directories(tinyxml
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(tinyxml
    PUBLIC
        TIXML_USE_STL
)

add_library(dragon_core STATIC
    dragon.cc
    galaxy.cc
    geometry.cc
    xsec.cc
    particle.cc
    crevolutor.cc
    eloss.cc
    bfield.cc
    diffusion.cc
    gas.cc
    grid.cc
    nucleilist.cc
    utilities.cc
    kamae.cc
    sources.cc
    spectrum.cc
    input.cc
    dmspec.F
    WNEWTR_FUNC_aws.f
    YIELDX_011000_imos.f
    crn6.f
)

target_include_directories(dragon_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/cparamlib
)

target_compile_definitions(dragon_core
    PUBLIC
        TIXML_USE_STL
)

target_link_libraries(dragon_core
    PUBLIC
        tinyxml
        cparamlib
        GSL::gsl
        cfitsio::cfitsio
)

add_executable(DRAGON main.cc)

target_include_directories(DRAGON
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(DRAGON
    PRIVATE
        dragon_core
)

install(TARGETS DRAGON dragon_core tinyxml cparamlib
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)