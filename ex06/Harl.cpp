#include "Harl.hpp"

#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

const HarlLevel Harl::levels[] = {{0, "DEBUG", &Harl::debug},
    {1, "INFO", &Harl::info}, {2, "WARNING", &Harl::warning},
    {3, "ERROR", &Harl::error}};

const int Harl::num_levels = sizeof(levels) / sizeof(levels[0]);

void Harl::filter(std::string level) {
    int numberOfLevel = -1;
    for (int i = 0; i < num_levels; i++) {
        if (level == levels[i].title) {
            numberOfLevel = levels[i].number;
            break;
        }
    }
    switch (numberOfLevel) {
        case 0:
            (this->*levels[0].method)();
        case 1:
            (this->*levels[1].method)();
        case 2:
            (this->*levels[2].method)();
        case 3:
            (this->*levels[3].method)();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break;
    }
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
