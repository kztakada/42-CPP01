#include "FileManipulator.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "FileError.hpp"

FileManipulator::FileManipulator(const std::string &filePath, FileMode mode)
    : _filePath(filePath), _isEof(false) {
    if (mode == WRITE_MODE || mode == APPEND_MODE) {
        _openWrite();
    }
    _openRead();
}

FileManipulator::~FileManipulator() {
    if (_ifs.is_open()) {
        _ifs.close();
    }
    if (_ofs.is_open()) {
        _ofs.close();
    }
}

bool FileManipulator::isEof() const { return _isEof; }

bool FileManipulator::readLine(std::string &line) {
    if (!_isFileExist()) {
        throw FileError("File does not exist: " + _filePath);
    }
    if (!_ifs.is_open()) {
        throw FileError("File not open for reading: " + _filePath);
    }
    return _readLineWithBuffer(line);
}

void FileManipulator::appendLine(const std::string &line) {
    if (!_ofs.is_open()) {
        throw FileError("File not open for writing: " + _filePath);
    }
    _ofs << line << std::flush;
    if (_ofs.fail()) {
        throw FileError("Error writing to file: " + _filePath);
    }
}

void FileManipulator::closeRead() {
    if (_ifs.is_open()) {
        _ifs.close();
    }
}

void FileManipulator::closeWrite() {
    if (_ofs.is_open()) {
        _ofs.close();
    }
}

void FileManipulator::_openRead() {
    if (_ifs.is_open()) {
        return;
    }

    if (!_isFileExist())
        throw FileError("File does not exist: " + _filePath);

    _ifs.open(_filePath.c_str(), std::ios::in);
    if (!_ifs.is_open()) {
        throw FileError("Failed to open file for reading: " + _filePath);
    }
    _isEof = false;
}

void FileManipulator::_openWrite() {
    if (_ofs.is_open())
        throw FileError("File already open for writing: " + _filePath);

    _ofs.open(_filePath.c_str(), std::ios::out);
    if (!_ofs.is_open()) {
        throw FileError("Failed to open file for writing: " + _filePath);
    }
}

// void FileManipulator::_openAppend() {
//     if (_ofs.is_open()) {
//         return;
//     }
//     _ofs.open(_filePath.c_str(), std::ios::app);
//     if (!_ofs.is_open()) {
//         throw FileError("Failed to open file for appending: " + _filePath);
//     }
// }

bool FileManipulator::_isFileExist() {
    std::ifstream file(_filePath.c_str());
    return file.good();
}

bool FileManipulator::_readLineWithBuffer(std::string &line) {
    static std::string s_buffer;
    static size_t s_bufferPos = 0;
    static bool s_hasData = false;

    line.clear();

    if (_isEof) {
        return false;
    }

    while (true) {
        // バッファに十分なデータがない場合、新しいデータを読み込む
        if (s_bufferPos >= s_buffer.length()) {
            char readBuffer[BUFFER_SIZE];
            _ifs.read(readBuffer, BUFFER_SIZE);
            std::streamsize bytesRead = _ifs.gcount();

            if (bytesRead == 0) {
                // ファイル終端またはエラー
                if (_ifs.eof()) {
                    _isEof = true;
                    // バッファに残りのデータがある場合は最後の行として返す
                    if (s_hasData && !s_buffer.empty() &&
                        s_bufferPos < s_buffer.length()) {
                        line = s_buffer.substr(s_bufferPos);
                        s_bufferPos = s_buffer.length();
                        return true;
                    }
                    return false;
                } else {
                    throw FileError("Error reading from file: " + _filePath);
                }
            }

            // 新しく読み込んだデータをバッファに追加
            s_buffer = s_buffer.substr(s_bufferPos) +
                       std::string(readBuffer, bytesRead);
            s_bufferPos = 0;
            s_hasData = true;
        }

        // バッファ内で改行文字を検索
        size_t newlinePos = s_buffer.find('\n', s_bufferPos);

        if (newlinePos != std::string::npos) {
            // 改行文字が見つかった場合
            line = s_buffer.substr(s_bufferPos, newlinePos - s_bufferPos + 1);
            s_bufferPos = newlinePos + 1;
            return true;
        }

        // 改行文字が見つからない場合、さらにデータを読み込む
        // ただし、ファイル終端の場合は残りのデータを返す
        if (_ifs.eof()) {
            if (s_bufferPos < s_buffer.length()) {
                line = s_buffer.substr(s_bufferPos);
                s_bufferPos = s_buffer.length();
                _isEof = true;
                return true;
            } else {
                _isEof = true;
                return false;
            }
        }
    }
}
