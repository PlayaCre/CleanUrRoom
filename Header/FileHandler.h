// Created by Canel on 26.07.2024.
//

#ifndef CLEANURROOM_FILEHANDLER_H
#define CLEANURROOM_FILEHANDLER_H

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

namespace fs = std::filesystem;

class FileHandler {
private:
    std::vector<fs::directory_entry> files;  // Vector to store file entries
    std::vector<std::vector<std::string>> template_2d_vec; // Vector to store template file by their delimiters
    std::vector<std::vector<fs::directory_entry>> files_2d_vec; // Vector to store and sort all files by their extensions
    std::string directory_path;  // Path to the directory
    std::string template_path;  // Path to the template

public:
    // Constructor that initializes the directory path and template path
    explicit FileHandler(const std::string &dir_path, const std::string &temp_path);

    // Function to count all files in the directory
    unsigned int countAllFiles();

    // Function to put all files into a single vector
    std::vector<fs::directory_entry> extract_files_into_vector();

    //Function to sort the files by their Extensions in vector
    std::vector<fs::directory_entry> sort_files_by_extensions();

    // Function to print all Files from vector for test
    virtual void print_all_files();

    // Function to print 2d vector
    virtual void print_2d_vector();

    // Initialise 2D vector from Template file
    virtual void create_2d_vector_from_template();

    // Initialise 2D vector to store and sort all files by their extensions
    virtual void create_2d_vector_from_files();
};

#endif //CLEANURROOM_FILEHANDLER_H
