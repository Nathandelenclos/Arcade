/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Utils.cpp
*/

#include "Utils.hpp"

Arcade::ErrorHandling::ErrorHandling() {
    std::cout << "Entering Error Handling" << std::endl;
}

void Arcade::ErrorHandling::checkForValidArg(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "./arcade ./lib_arcade_[NAME_OF_THE_LIB].so" << std::endl;
        std::cerr << "  arcade_sfml.so" << std::endl;
        std::cerr << "  arcade_sdl2.so" << std::endl;
        std::cerr << "  arcade_ncurses.so" << std::endl;
        exit(84);
    }
    std::ifstream file(av[1]);
    if (Arcade::Utils::checkIfLibFile(av[1]) && file.good())
        return;
    std::cerr << "Lib file is not a valid file." << std::endl;
    exit(84);
}

void Arcade::ErrorHandling::getLibFiles() {
    std::string directoryPath = "./lib/";
    dirent* entry;
    DIR* dir = opendir(directoryPath.c_str());

    if (dir == nullptr) {
        std::cerr << "Error opening directory" << std::endl;
        return;
    }
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_REG) {
            std::cout << entry->d_name << std::endl;
            if (std::string(entry->d_name).substr(0, 7) != "arcade_") {
                std::cerr << "Invalid " << entry->d_name << " in lib folder" << std::endl;
                exit(84);
            }
        }
    }

    closedir(dir);
}

Arcade::ErrorHandling::~ErrorHandling() = default;

bool Arcade::Utils::checkIfLibFile(const std::string &libName) {
    if (libName.length() > 7 && libName.substr(libName.length() - 3) == ".so"
        && libName.substr(7) != "arcade_")
        return true;
    return false;
}
