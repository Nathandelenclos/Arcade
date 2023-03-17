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
#include "Utils.hpp"

int main(int ac, char **av)
{
    std::shared_ptr<Arcade::ErrorHandling> error;
    error->checkForValidArg(ac, av);
    error->getLibFiles();
    std::vector<Arcade::IGraphicLibPtr> libVector;
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSFML("./lib/arcade_sfml.so");
    std::shared_ptr<Arcade::IGraphicLib> libSFML = loaderSFML.getGraphInstance();
    libVector.push_back(libSFML);
    Arcade::DlLoader<Arcade::IGraphicLib> loaderSDL("./lib/arcade_sdl2.so");
    std::shared_ptr<Arcade::IGraphicLib> libSDL = loaderSDL.getGraphInstance();
    libVector.push_back(libSDL);
    Arcade::DlLoader<Arcade::IGraphicLib> loaderNCURSES("./lib/arcade_ncurses.so");
    std::shared_ptr<Arcade::IGraphicLib> libNCURSES = loaderNCURSES.getGraphInstance();
    libVector.push_back(libNCURSES);

    std::vector<Arcade::IGameLibPtr> gameVector;
    Arcade::DlLoader<Arcade::IGameLib> loaderPACMAN("./lib/arcade_pacman.so");
    std::shared_ptr<Arcade::IGameLib> libPACMAN = loaderPACMAN.getGameInstance();
    gameVector.push_back(libPACMAN);
    Arcade::DlLoader<Arcade::IGameLib> loaderSNAKE("./lib/arcade_snake.so");
    std::shared_ptr<Arcade::IGameLib> libSNAKE = loaderSNAKE.getGameInstance();
    gameVector.push_back(libSNAKE);


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
