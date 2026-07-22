add_library(cparamlib STATIC
    antinumu.c
    elec.c
    nue.c
    posi.c
    antinue.c
    gamma_param.c
    numu.c
    sigma.c
)

target_include_directories(cparamlib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(cparamlib PRIVATE 
    m               # Standard ath library (libm)
    GSL::gsl        # GNU Scientific Library
    OpenMP::OpenMP_C 
)