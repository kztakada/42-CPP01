#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <string>

class Display {
   public:
    static void show(const std::string& message);
    static void show(const char* message);
    static void prompt(const std::string& message);
    static void error(const std::string& message);

   private:
    Display();
};

#endif /* DISPLAY_HPP */