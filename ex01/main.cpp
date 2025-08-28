#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N;
    {
        N = 10;
        Zombie* horde = zombieHorde(N, std::string("Zombie"));
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }
        delete[] horde;
    }
    {
        N = 0;
        Zombie* horde = zombieHorde(N, std::string("Zombie2"));
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }
        delete[] horde;
    }
    {
        N = -1;
        Zombie* horde = zombieHorde(N, std::string("Zombie3"));
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }
        delete[] horde;
    }

    return 0;
}
