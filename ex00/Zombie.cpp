#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << name << " is born!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is dead!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
