#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
   public:
    ~Zombie();
    Zombie(std::string name);
    void announce(void);

   private:
    std::string name;
};

#endif /* ZOMBIE_HPP */