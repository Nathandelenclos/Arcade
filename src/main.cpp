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
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSFML("./lib/arcade_sfml.so");
    std::shared_ptr<Arcade::IGraphicLib> libSFML = loaderSFML.getGraphInstance();
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSDL("./lib/arcade_sdl2.so");
    std::shared_ptr<Arcade::IGraphicLib> libSDL = loaderSDL.getGraphInstance();
    Arcade::DlLoader<Arcade::IGraphicLib> loaderNCURSES("./lib/arcade_ncurses.so");
    std::shared_ptr<Arcade::IGraphicLib> libNCURSES = loaderNCURSES.getGraphInstance();

    Arcade::DlLoader<Arcade::IGameLib> loaderPACMAN("./lib/arcade_pacman.so");
    std::shared_ptr<Arcade::IGameLib> libPACMAN = loaderPACMAN.getGameInstance();
    Arcade::DlLoader<Arcade::IGameLib> loaderSNAKE("./lib/arcade_snake.so");
    std::shared_ptr<Arcade::IGameLib> libSNAKE = loaderSNAKE.getGameInstance();
    return (0);
}
