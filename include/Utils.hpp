/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Utils.hpp
*/

#include "vector"
#include "memory"
#include "iostream"
#include "fstream"
#include "filesystem"
#include <cstring>
#include <string>
#include <dirent.h>
#include "DlLoader.hpp"
#include "IGraphicLib.hpp"
#include "IGameLib.hpp"

#pragma once

namespace Arcade {
    class ErrorHandling {
        public:
            ErrorHandling();
            ~ErrorHandling();
            void checkForValidArg(int ac, char **av);
            void getLibFiles();
            void loadLibs();
            void loadGames();
            std::shared_ptr<std::vector<Arcade::DlLoaderGraphicPtr>> getGraphicLibsLoader() const;
            std::shared_ptr<std::vector<Arcade::DlLoaderGamePtr>> getGameLibsLoader() const;
            std::shared_ptr<std::vector<std::string>> getLibs() const;
            std::shared_ptr<std::vector<std::string>> getGames() const;
        private:
            std::shared_ptr<std::vector<std::string>> _games;
            std::shared_ptr<std::vector<std::string>> _libs;
            std::shared_ptr<std::vector<Arcade::DlLoaderGraphicPtr>> _graphicLibsLoader;
            std::shared_ptr<std::vector<Arcade::DlLoaderGamePtr>> _gameLibsLoader;
    };

    class Utils {
        public:
            static bool checkIfLibFile(const std::string& libName);
            static void getLibs(std::shared_ptr<std::vector<std::string>> &libs,
                               const std::string &name, const std::string &path = "./lib/");
            static void getGames(std::shared_ptr<std::vector<std::string>> &games,
                               const std::string &name, const std::string &path = "./lib/");
    };
}
