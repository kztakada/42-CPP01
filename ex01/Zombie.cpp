#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() : name("") { std::cout << name << " is born!" << std::endl; }

Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << " is born!" << std::endl;
}

Zombie::~Zombie() { std::cout << name << " is dead!" << std::endl; }

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->name = name; }
