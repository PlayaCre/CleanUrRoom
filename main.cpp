#include <iostream>
#include <string>
#include <filesystem>
#include "Header/FileHandler.h"

using namespace std;

int main() {
    FileHandler directory1("C:/Users/Canel/Desktop");
    directory1.countAllFiles();
    return 0;
}
