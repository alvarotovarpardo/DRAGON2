#pragma once
#include <string>
namespace dragon2::core {
    std::string version();
    std::string hello(std::string who = "world");
    double add_from_fortran(double a, double b); // NUEVO
}
