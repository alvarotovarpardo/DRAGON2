cmake_minimum_required(VERSION 3.15)

project(DRAGON2 VERSION 3.0.0 LANGUAGES CXX Fortran)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenMP REQUIRED)
find_package(GSL REQUIRED)
find_package(CFITSIO REQUIRED)

add_library(tinyxml STATIC
    tinystr.cc
    tinyxml.cc
    tinyxmlerror.cc
    tinyxmlparser.cc
)

target_include_directories(tinyxml PUBLIC include)
target_compile_definitions(tinyxml PRIVATE TIXML_USE_STL)

add_subdirectory(cparamlib)

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

target_include_directories(dragon_core PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(dragon_core PUBLIC
    tinyxml
    cparamlib
    OpenMP::OpenMP_CXX
    GSL::gsl
    CFITSIO::CFITSIO 
)

add_executable(dragon_cli main.cc)
target_link_libraries(dragon_cli PRIVATE dragon_core)
set_target_properties(dragon_cli PROPERTIES OUTPUT_NAME "DRAGON")