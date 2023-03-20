/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** main.cpp
*/

#include "IGraphicLib.hpp"
#include "IGameLib.hpp"
#include "DlLoader.hpp"
#include "Types.hpp"

int main()
{
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSFML("./lib/arcade_sfml.so");
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSDL("./lib/arcade_sdl2.so");
    Arcade::DlLoader<Arcade::IGraphicLib> loaderNCURSES("./lib/arcade_ncurses.so");
    Arcade::DlLoader<Arcade::IGameLib> loaderPACMAN("./lib/arcade_pacman.so");
    Arcade::DlLoader<Arcade::IGameLib> loaderSNAKE("./lib/arcade_snake.so");
    std::vector<Arcade::IGraphicLibPtr> libVector;
    std::vector<Arcade::IGameLibPtr> gameVector;
    libVector.push_back(loaderSFML.getGraphInstance());
    libVector.push_back(loaderSDL.getGraphInstance());
    libVector.push_back(loaderNCURSES.getGraphInstance());

    gameVector.push_back(loaderPACMAN.getGameInstance());
    gameVector.push_back(loaderSNAKE.getGameInstance());


    bool isRunning = true;
    int currentLib = 0;
    int currentGame = 0;
    Arcade::windowsParameter_t windowsParameter = {800, 600, false};
    Arcade::IObjectVector gameObjects;

    libVector[currentLib]->setWindow(windowsParameter);
    libVector[currentLib]->loadObjects(gameObjects);
    libVector[currentLib]->openWindow();
    while (isRunning) {
        libVector[currentLib]->display();
        if (libVector[currentLib]->getCurrentKey() == Arcade::InputKey::QUIT)
            isRunning = false;
        if (libVector[currentLib]->getCurrentKey() == Arcade::InputKey::SWITCH_LIB)
            libVector[currentLib] = libVector[++currentLib % libVector.size()];
        if (libVector[currentLib]->getCurrentKey() == Arcade::InputKey::SWITCH_GAME)
            gameVector[currentGame] = gameVector[++currentGame % gameVector.size()];
    }
    libVector[currentLib]->closeWindow();
    std::cout << "end of program" << std::endl;
    return (0);
}
