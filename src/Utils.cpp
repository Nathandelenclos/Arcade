/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Utils.cpp
*/

#include "Utils.hpp"
#include "DlLoader.hpp"

/**
 * @brief Check if the file is a lib file
 *
 * @param file {std::string} - file to check
 * @return true - if the file is a lib file
 * @return false - if the file is not a lib file
 */
Arcade::ErrorHandling::ErrorHandling() {
    this->_games = std::make_shared<std::vector<std::string>>();
    this->_libs = std::make_shared<std::vector<std::string>>();
/*    this->_graphicLibsLoader = std::make_shared<std::vector<Arcade::DlLoaderGraphicPtr>>();
    this->_gameLibsLoader = std::make_shared<std::vector<Arcade::DlLoaderGamePtr>>();*/
}

/**
 * @brief Get the Libs object
 *
 * @return std::shared_ptr<std::vector<std::string>> - the libs
 */
void Arcade::ErrorHandling::checkForValidArg(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "./arcade ./lib/arcade_[NAME_OF_THE_LIB].so" << std::endl;
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

/**
 * @brief Get the Libs object
 *
 * @return std::shared_ptr<std::vector<std::string>> - the libs
 */
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
            if (std::string(entry->d_name).substr(0, 7) != "arcade_") {
                std::cerr << "Invalid " << entry->d_name << " in lib folder" << std::endl;
                exit(84);
            }
            Arcade::Utils::getLibs(this->_libs, entry->d_name, directoryPath);
            Arcade::Utils::getGames(this->_games, entry->d_name, directoryPath);
        }
    }
    closedir(dir);
}

/**
 * @brief Get the Libs object
 *
 * @return std::shared_ptr<std::vector<std::string>> - the libs
 */
Arcade::ErrorHandling::~ErrorHandling() = default;

bool Arcade::Utils::checkIfLibFile(const std::string &libName) {
    if (libName.length() > 7 && libName.substr(libName.length() - 3) == ".so"
        && libName.substr(7) != "arcade_")
        return true;
    return false;
}

void Arcade::Utils::getLibs(std::shared_ptr<std::vector<std::string>> &libs,
                           const std::string &name, const std::string &path) {
    std::string allowLibs[] = {"arcade_ncurses.so", "arcade_sdl2.so", "arcade_ndk++.so",
                               "arcade_aalib.so", "arcade_libcaca.so", "arcade_allegro5.so",
                               "arcade_xlib.so", "arcade_gtk+.so", "arcade_sfml.so",
                               "arcade_irrlicht.so", "arcade_opengl.so", "arcade_vulkan.so",
                               "arcade_qt5.so"};
    for (int i = 0; allowLibs[i] != "arcade_qt5.so"; ++i) {
        if (allowLibs[i] == name) {
            libs->push_back(path + name);
            return;
        }
    }
}

void Arcade::Utils::getGames(std::shared_ptr<std::vector<std::string>> &games,
                             const std::string &name, const std::string &path) {
    std::string allowLibs[] = {"arcade_snake.so", "arcade_nibbler.so", "arcade_pacman.so",
                               "arcade_qix.so", "arcade_centipede.so", "arcade_solarfox.so"};
    for (int i = 0; allowLibs[i] != "arcade_solarfox.so"; ++i) {
        if (allowLibs[i] == name) {
            games->push_back(path + name);
            return;
        }
    }
}

std::shared_ptr<std::vector<std::string>>
Arcade::ErrorHandling::getGames() const
{
    return _games;
}

std::shared_ptr<std::vector<std::string>> Arcade::ErrorHandling::getLibs() const
{
    return _libs;
}
