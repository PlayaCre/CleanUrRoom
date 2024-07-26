//
// Created by Canel on 26.07.2024.
//

#include "../Header/FileHandler.h"

FileHandler::FileHandler(const std::string &n) : directory_path(n) {}

unsigned int FileHandler::countAllFiles() {
    unsigned int counter = 0;
    for (const auto& entry : fs::directory_iterator(directory_path)) {
        if (entry.path().extension() == ".ini") {
            std::cout << entry.path() << std::endl;
            counter++;
        }
    }
    std::cout << counter << " files were found." << std::endl;
    return counter;
}