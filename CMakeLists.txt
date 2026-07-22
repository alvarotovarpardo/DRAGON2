cmake_minimum_required(VERSION 3.15)

project(DRAGON2 VERSION 3.0.0 LANGUAGES C CXX Fortran)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenMP REQUIRED)
find_package(GSL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CFITSIO REQUIRED IMPORTED_TARGET cfitsio)

set(PACKAGE_NAME "${PROJECT_NAME}")
set(PACKAGE_VERSION "${PROJECT_VERSION}")
set(PACKAGE_STRING "${PROJECT_NAME} ${PROJECT_VERSION}")
set(VERSION "${PROJECT_VERSION}")

set(TIXML_USE_STL 1)

set(HAVE_LIBCFITSIO 1)
set(HAVE_GSL_GSL_ERRNO_H 1)
set(HAVE_GSL_GSL_LINALG_H 1)
set(HAVE_GSL_GSL_SPLINE_H 1)
set(HAVE_GSL_GSL_VECTOR_H 1)

set(NUMTHREADS "4" CACHE STRING "Maximum number of CPUs to be used")
set(OMP_NUM_THREADS ${NUMTHREADS})

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in 
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_library(tinyxml STATIC
    tinystr.cc
    tinyxml.cc
    tinyxmlerror.cc
    tinyxmlparser.cc
)

target_include_directories(tinyxml PUBLIC include)
target_compile_definitions(tinyxml PUBLIC TIXML_USE_STL)

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
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_link_libraries(dragon_core PUBLIC
    tinyxml
    cparamlib
    OpenMP::OpenMP_CXX
    GSL::gsl
    PkgConfig::CFITSIO 
)

target_compile_definitions(dragon_core PUBLIC 
    NUMTHREADS=${NUMTHREADS}
    OMP_NUM_THREADS=${NUMTHREADS}
    HAVE_LIBCFITSIO=1
    HAVE_GSL_GSL_ERRNO_H=1
    HAVE_GSL_GSL_LINALG_H=1
    HAVE_GSL_GSL_SPLINE_H=1
    HAVE_GSL_GSL_VECTOR_H=1
)

add_executable(dragon_cli main.cc)
target_link_libraries(dragon_cli PRIVATE dragon_core)
set_target_properties(dragon_cli PROPERTIES OUTPUT_NAME "DRAGON")