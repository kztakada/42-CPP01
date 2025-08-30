#include <cstdlib>

#include "Display.hpp"
#include "FileManipulator.hpp"
#include "StringWrapper.hpp"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        Display::error(
            "Error: Invalid number of arguments.\nUsage: ./replace <file_path> "
            "<string_to_replace> <replacement_string>");
        return EXIT_FAILURE;
    }
    const std::string file_path(argv[1]);
    const std::string from_str(argv[2]);
    const std::string to_str(argv[3]);

    try {
        FileManipulator input_file(file_path, READ_MODE);
        FileManipulator output_file(file_path + ".replace", WRITE_MODE);
        output_file.closeRead();

        std::string line;
        StringWrapper converter("");

        while (true) {
            if (!input_file.readLine(line)) {
                break;
            }

            converter = line;
            output_file.appendLine(converter.replace(from_str, to_str));

            line.clear();
            converter.clear();
        }
    } catch (const std::exception &e) {
        Display::error(e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
