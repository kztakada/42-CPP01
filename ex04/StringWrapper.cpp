#include "StringWrapper.hpp"

StringWrapper::StringWrapper(const std::string &str) : _str(str) {}

StringWrapper::~StringWrapper() {}

StringWrapper::StringWrapper(StringWrapper const &other) : _str(other._str) {}

StringWrapper &StringWrapper::operator=(const std::string &str) {
    _str = str;
    return *this;
}

StringWrapper::operator const std::string &() const { return _str; }

std::string StringWrapper::replace(
    const std::string &fromStr, const std::string &toStr) const {
    std::string result = _str;
    size_t pos = 0;
    while ((pos = result.find(fromStr, pos)) != std::string::npos) {
        result.erase(pos, fromStr.length());
        result.insert(pos, toStr);
        pos += toStr.length();
    }
    return result;
}

void StringWrapper::clear() { _str.clear(); }