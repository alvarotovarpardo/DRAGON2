add_executable(dragon2_minimal main.cpp)
# Flags MSVC útiles
if (MSVC)
  target_compile_options(dragon2_minimal PRIVATE /W4 /permissive- /Zc:__cplusplus)
endif()