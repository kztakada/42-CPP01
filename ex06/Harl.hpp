#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl;

struct HarlLevel {
    const int number;
    const char *title;
    void (Harl::*method)(void);
};

class Harl {
   public:
    Harl();
    ~Harl();
    void filter(std::string level);

   private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    static const HarlLevel levels[];
    static const int num_levels;
};

#endif /* HARL_HPP */