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

#pragma once

namespace Arcade {
    class ErrorHandling {
        public:
            ErrorHandling();
            ~ErrorHandling();
            void checkForValidArg(int ac, char **av);
            void getLibFiles();
        private:
            std::shared_ptr<std::vector<std::string>> _games;
            std::shared_ptr<std::vector<std::string>> _libs;
    };

    class Utils {
        public:
            static bool checkIfLibFile(const std::string& libName);
    };
}
