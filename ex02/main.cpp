#include <iostream>
#include <string>

int main(void) {
    std::string string("HI THIS IS BRAIN");
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "The memory address of the string variable\n"
              << static_cast<void *>(&string) << "\n"
              << "The memory address held by stringPTR\n"
              << static_cast<void *>(stringPTR) << "\n"
              << "The memory address held by stringREF\n"
              << static_cast<void *>(&stringREF) << "\n\n"

              << "The value of the string variable\n"
              << string << "\n"
              << "The value pointed to by stringPTR\n"
              << *stringPTR << "\n"
              << "The value pointed to by stringREF\n"
              << stringREF << std::endl;
}
