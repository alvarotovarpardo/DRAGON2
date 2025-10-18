#include "dragon2/core/hello.hpp"
#include <cstdio>

extern "C" {
    double dragon2_f_add(double a, double b); // nombre exacto del bind(C)
}

namespace dragon2::core {
    double add_from_fortran(double a, double b) {
        return dragon2_f_add(a, b);
    }
}
