#include "FileError.hpp"

FileError::FileError(const std::string& message) : _message(message) {}

FileError::~FileError() throw() {}

FileError::FileError(const FileError& other)
    : std::exception(other), _message(other._message) {}

FileError& FileError::operator=(const FileError& other) {
    if (this != &other) {
        std::exception::operator=(other);
        _message = other._message;
    }
    return *this;
}

const char* FileError::what() const throw() { return _message.c_str(); }
