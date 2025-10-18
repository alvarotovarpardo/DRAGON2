#include <iostream>
#include "dragon2/core/hello.hpp"
int main() {
    std::cout << "DRAGON2 core v" << dragon2::core::version() << "\n";
    std::cout << dragon2::core::hello("DRAGON2") << "\n";
    std::cout << "2.5 + 3.75 = " << dragon2::core::add_from_fortran(2.5, 3.75) << "\n";
    return 0;
}
