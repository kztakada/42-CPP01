#include <sstream>
#include <string>

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

// std::string intToString(int value) {
//     std::stringstream ss;
//     ss << value;
//     return ss.str();
// }

const int NUM_ZOMBIES = 10000;

int main() {
    std::string z_name;

    z_name = "heap_zombie";
    // for heap allocation
    Zombie *zombie1 = newZombie(z_name);
    zombie1->announce();
    delete zombie1;

    // Zombie *zombie[NUM_ZOMBIES];

    // for (int i = 0; i < NUM_ZOMBIES; i++)
    //     zombie[i] = newZombie(z_name + intToString(i));
    // for (int i = 0; i < NUM_ZOMBIES; i++)
    //     zombie[i]->announce();
    // delete[] zombie;

    z_name = "stack_zombie";
    // for stack allocation
    randomChump(z_name);

    return 0;
}
