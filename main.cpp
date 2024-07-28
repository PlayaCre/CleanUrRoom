#include <iostream>
#include <string>
#include <filesystem>
#include "Header/FileHandler.h"

using namespace std;

int main() {
    FileHandler directory1("C:/Users/Canel/Desktop", "C:/Users/Canel/Desktop/CleanUrRoom/Templates/FileFormatTemplates.txt");
    directory1.countAllFiles();
    directory1.extract_files_into_vector();
    //directory1.print_all_files();
    directory1.sort_files_by_extensions();
    std::cout << endl << endl;
    // directory1.print_all_files();
    directory1.create_2d_vector_from_template();

    return 0;
}
