//
// Created by Canel on 26.07.2024.
//

#include "../Header/FileHandler.h"

FileHandler::FileHandler(const std::string &dir_path, const std::string &temp_path) {
    this->directory_path = dir_path;
    this->template_path = temp_path;
}


unsigned int FileHandler::countAllFiles() {
    unsigned int counter = 0;
    try {
        for (const auto& entry : fs::directory_iterator(directory_path)) {
            if (entry.path().extension() != ".ini") {
                counter++;
            }
        }
        std::cout << counter << " files were found." << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return counter;
}

std::vector<fs::directory_entry> FileHandler::extract_files_into_vector() {
    try {
        for (const auto& entry : fs::directory_iterator(directory_path)) {
            if (entry.path().extension() != ".ini") {
                files.push_back(entry);
            }
        }
        if (!files.empty()) {
            std::cout << "All " << files.size() << " files were extracted." << std::endl;
            return files;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return files;
}

std::vector<fs::directory_entry> FileHandler::sort_files_by_extensions() {
    try{
        std::multimap<fs::path, fs::directory_entry> sorted_files;
        for (const auto& entry : this->files) {
            sorted_files.insert(std::make_pair(entry.path().extension(), entry));
        }
        files.clear();

        for (const auto& pair : sorted_files) {
            files.push_back(pair.second);
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
    return files;
}

void FileHandler::print_all_files() {
    try{
        for (const auto& entry : files) {
            std::cout << "Filename: " << entry.path().filename() << ", Extension: " << entry.path().extension().string() << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
}

void FileHandler::create_2d_vector_from_template() {
    try {
        std::string line;
        std::ifstream file(this->template_path);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << template_path << std::endl;
            return;
        }

        while (std::getline(file, line)) {
            std::vector<std::string> row;
            size_t pos = line.find(':');
            if (pos != std::string::npos) {
                // Kategorie hinzufügen
                row.push_back(line.substr(0, pos));

                // Erweiterungen extrahieren
                std::string extensions_part = line.substr(pos + 1);
                std::stringstream ss(extensions_part);
                std::string item;

                while (std::getline(ss, item, ';')) {
                    // Entfernen von Leerzeichen am Anfang und Ende des Strings
                    item.erase(item.begin(), std::find_if(item.begin(), item.end(), [](unsigned char ch) {
                        return !std::isspace(ch);
                    }));
                    item.erase(std::find_if(item.rbegin(), item.rend(), [](unsigned char ch) {
                        return !std::isspace(ch);
                    }).base(), item.end());

                    row.push_back(item);
                }
                // Die verarbeitete Zeile dem 2D-Vektor hinzufügen
                this->template_2d_vec.push_back(row);
            }
        }
        file.close();

    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
}

void FileHandler::print_2d_vector() {
    for (const auto &row: this->template_2d_vec) {
        for (const auto &col: row) {
            std::cout << col << " | ";
        }
        std::cout << std::endl;
    }
    /*
    // Beispielausgabe einer bestimmten Zelle
    if (!template_2d_vec.empty() && template_2d_vec[0].size() > 1) {
        std::cout << template_2d_vec[5][0] << std::endl;
    }*/
}

void FileHandler::create_2d_vector_from_files() {

}
