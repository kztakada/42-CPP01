#include "Display.hpp"

void Display::show(const std::string& message) {
    std::cout << message << std::endl;
}

void Display::show(const char* message) {
    if (message != NULL) {
        std::cout << message << std::endl;
    }
}

void Display::prompt(const std::string& message) {
    std::cout << message << std::flush;
}

void Display::error(const std::string& message) {
    std::cerr << message << std::endl;
}
