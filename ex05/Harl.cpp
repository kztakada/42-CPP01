#include "Harl.hpp"

#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

const HarlLevel Harl::levels[] = {{"DEBUG", &Harl::debug},
    {"INFO", &Harl::info}, {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error}};

const int Harl::num_levels = sizeof(levels) / sizeof(levels[0]);

void Harl::complain(std::string level) {
    for (int i = 0; i < num_levels; i++) {
        if (level == levels[i].title) {
            (this->*levels[i].method)();
            return;
        }
    }
    std::cout << "[ NOT FOUND ]\n"
              << "That level is not registered." << std::endl;
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger.\nI "
                 "really do!\n"
              << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money.\nYou "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!\n"
              << std::endl;
}

void Harl::warning(void) {
    std::cout
        << "[ WARNING ]\n"
        << "I think I deserve to have some extra bacon for free.\nI’ve been "
           "coming for years, whereas you started working here just last "
           "month.\n"
        << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
}
