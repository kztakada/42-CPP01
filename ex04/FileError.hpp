#ifndef FILEERROR_HPP
#define FILEERROR_HPP

#include <exception>
#include <string>

class FileError : public std::exception {
   public:
    FileError(const std::string& message);
    virtual ~FileError() throw();
    FileError(const FileError& other);
    FileError& operator=(const FileError& other);

    virtual const char* what() const throw();

   private:
    std::string _message;
};

#endif /* FILEERROR_HPP */