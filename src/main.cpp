/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** main.cpp
*/

#include "IGraphicLib.hpp"
#include "IGameLib.hpp"
#include "DlLoader.hpp"

int main()
{
    std::vector<Arcade::IGraphicLib> *libs;
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSFML("./lib/arcade_sfml.so");
    std::shared_ptr<Arcade::IGraphicLib> libSFML = loaderSFML.getInstance();
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSDL("./lib/arcade_sdl2.so");
    std::shared_ptr<Arcade::IGraphicLib> libSDL = loaderSDL.getInstance();
    Arcade::DlLoader<Arcade::IGraphicLib> loaderNCURSES("./lib/arcade_ncurses.so");
    std::shared_ptr<Arcade::IGraphicLib> libNCURSES = loaderNCURSES.getInstance();
    return (0);
}
