#include "Harl.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return EXIT_FAILURE;
    }

    harl.complain(argv[1]);
    return EXIT_SUCCESS;
}
