#ifndef FILEMANIPULATOR_HPP
#define FILEMANIPULATOR_HPP

#include <fstream>
#include <string>

#include "FileError.hpp"

enum FileMode { READ_MODE, WRITE_MODE, APPEND_MODE };

class FileManipulator {
   public:
    FileManipulator(const std::string &filePath, FileMode mode = READ_MODE);
    ~FileManipulator();

    bool isEof() const;
    bool readLine(std::string &line);

    void appendLine(const std::string &line);

    void closeRead();
    void closeWrite();

   private:
    static const size_t BUFFER_SIZE = 4096;
    std::string _filePath;
    std::ifstream _ifs;
    std::ofstream _ofs;
    bool _isEof;

    void _openRead();
    void _openWrite();
    bool _isFileExist();
    // void _openAppend();
    bool _readLineWithBuffer(std::string &line);
};

#endif /* FILEMANIPULATOR_HPP */