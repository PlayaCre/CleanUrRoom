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

using namespace std;
namespace fs = filesystem;

class FileHandler {
private:
    vector<string> files;  // Vector to store file names
    string directory_path;  // Path to the directory
    string template_path;  // Path to the directory

public:
    // Constructor that initializes the path
    FileHandler(const string &n);

    // Function to count all files in the directory
    unsigned int countAllFiles();
};


#endif //CLEANURROOM_FILEHANDLER_H
