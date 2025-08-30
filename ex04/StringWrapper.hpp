#ifndef STRINGWRAPPER_HPP
#define STRINGWRAPPER_HPP

#include <string>

class StringWrapper {
   public:
    StringWrapper(const std::string &str);
    ~StringWrapper();
    StringWrapper(StringWrapper const &other);
    StringWrapper &operator=(const std::string &str);
    operator const std::string &() const;

    std::string replace(
        const std::string &from_str, const std::string &to_str) const;
    void clear();

   private:
    std::string _str;
};

#endif /* STRINGWRAPPER_HPP */