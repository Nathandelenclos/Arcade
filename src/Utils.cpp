/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Utils.cpp
*/

#include "Utils.hpp"
#include "DlLoader.hpp"

Arcade::ErrorHandling::ErrorHandling() {
    std::cout << "Entering Error Handling" << std::endl;
    this->_games = std::make_shared<std::vector<std::string>>();
    this->_libs = std::make_shared<std::vector<std::string>>();
    this->_graphicLibsLoader = std::make_shared<std::vector<Arcade::DlLoaderGraphicPtr>>();
    this->_gameLibsLoader = std::make_shared<std::vector<Arcade::DlLoaderGamePtr>>();
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
            Arcade::Utils::getLibs(this->_libs, entry->d_name, directoryPath);
            Arcade::Utils::getGames(this->_games, entry->d_name, directoryPath);
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

void Arcade::Utils::getLibs(std::shared_ptr<std::vector<std::string>> &libs,
                           const std::string &name, const std::string &path) {
    if (name == "arcade_ncurses.so" || name == "arcade_sdl2.so" || name == "arcade_ndk++.so" ||
        name == "arcade_aalib.so" || name == "arcade_libcaca.so" || name == "arcade_allegro5.so" ||
        name == "arcade_xlib.so" || name == "arcade_gtk+.so" || name == "arcade_sfml.so" ||
        name == "arcade_irrlicht.so" || name == "arcade_opengl.so" || name == "arcade_vulkan.so" ||
        name == "arcade_qt5.so") {
        libs->push_back(path + name);
        std::cout << "Lib name is " << name << std::endl;
    }
}

void Arcade::Utils::getGames(std::shared_ptr<std::vector<std::string>> &games,
                             const std::string &name, const std::string &path) {
    if (name == "arcade_snake.so" || name == "arcade_nibbler.so" || name == "arcade_pacman.so" ||
        name == "arcade_qix.so" || name == "arcade_centipede.so" || name == "arcade_solarfox.so") {
        games->push_back(path + name);
        std::cout << "Lib name is " << name << std::endl;
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

void Arcade::ErrorHandling::loadLibs()
{
    for (std::string &lib: *_libs) {
        _graphicLibsLoader->push_back(std::make_shared<Arcade::DlLoaderGraphic>(lib));
    }
}

void Arcade::ErrorHandling::loadGames()
{
    for (std::string &game: *_games) {
        _gameLibsLoader->push_back(std::make_shared<Arcade::DlLoaderGame>(game));
    }
}

std::shared_ptr<std::vector<Arcade::DlLoaderGraphicPtr>>
Arcade::ErrorHandling::getGraphicLibsLoader() const
{
    return _graphicLibsLoader;
}

std::shared_ptr<std::vector<Arcade::DlLoaderGamePtr>>
Arcade::ErrorHandling::getGameLibsLoader() const
{
    return _gameLibsLoader;
}
