#include <iostream>
#include "dragon2/core/hello.hpp"

int main() {
    std::cout << "DRAGON2 core v" << dragon2::core::version() << "\n";
    std::cout << dragon2::core::hello("DRAGON2") << "\n";
    return 0;
}
