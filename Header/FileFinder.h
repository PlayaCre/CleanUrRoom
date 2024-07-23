//
// Created by Canel on 23.07.2024.
//

#ifndef CLEANURROOM_FILEFINDER_H
#define CLEANURROOM_FILEFINDER_H

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = filesystem;

class FileFinder {
private:
    vector<string> files;  // Vector to store file names
    string path;  // Path to the directory

public:
    // Constructor that initializes the path
    FileFinder(const string &n);

    // Function to count all files in the directory
    unsigned int countAllFiles();

    // Function to get all files into the vector
    vector<string> pushAllFiles();

    // Function to print all files
    virtual void printAll();
};

#endif //CLEANURROOM_FILEFINDER_H