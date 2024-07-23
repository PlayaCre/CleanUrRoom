//
// Created by Canel on 23.07.2024.
//

#include "../Header/FileFinder.h"
using namespace std;

FileFinder::FileFinder(const string &n) : path(n){}

vector<string> FileFinder::pushAllFiles() {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(path)) {
            if (fs::is_regular_file(entry.status())) {
                this->files.push_back(entry.path().string());
            }
        }
    }
    catch (fs::filesystem_error& e) {
        std::cerr << "Error accessing directory: " << e.what() << std::endl;
    }
    return this->files;
}

void FileFinder::printAll() {
    for (const auto& file : files) {
        std::cout << file << std::endl;
    }
}

unsigned int FileFinder::countAllFiles() {
    int count = 0;

    try{
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry.status())) {
                ++count;
            }
        }
    }
    catch(fs::filesystem_error& e){
        cerr << "Error accessing directory: " << e.what() << std::endl;
    }
    return count;
}
