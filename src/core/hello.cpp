#include "dragon2/core/hello.hpp"

namespace dragon2::core {
    std::string version() { return "0.1.0"; }
    std::string hello(std::string who) { return "Hello, " + who + "!"; }
}
