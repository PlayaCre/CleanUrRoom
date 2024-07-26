//
// Created by Canel on 26.07.2024.
//

#ifndef CLEANURROOM_FILEHANDLER_H
#define CLEANURROOM_FILEHANDLER_H

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

class FileHandler {
private:
    std::vector<std::string> files;  // Vector to store file names
    std::string directory_path;  // Path to the directory
    std::string template_path;  // Path to the template

public:
    // Constructor that initializes the path
    explicit FileHandler(const std::string &n);

    // Function to count all files in the directory
    unsigned int countAllFiles();
};

#endif //CLEANURROOM_FILEHANDLER_H
