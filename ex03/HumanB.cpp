#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::attack(void) const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType()
                  << std::endl;
    else
        std::cout << name << " is unarmed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
