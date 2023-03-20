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
#include "Core.hpp"

int main()
{

    Arcade::DlLoaderGraphicPtr loaderSFML(new Arcade::DlLoaderGraphic("./lib/arcade_sfml.so"));
    Arcade::DlLoaderGraphicPtr loaderSDL(new Arcade::DlLoaderGraphic("./lib/arcade_sdl2.so"));
    Arcade::DlLoaderGraphicPtr loaderNCURSES(new Arcade::DlLoaderGraphic("./lib/arcade_ncurses.so"));
    Arcade::DlLoaderGamePtr loaderPACMAN(new Arcade::DlLoaderGame ("./lib/arcade_pacman.so"));
    Arcade::DlLoaderGamePtr loaderSNAKE(new Arcade::DlLoaderGame("./lib/arcade_snake.so"));
    std::shared_ptr<Arcade::Core> core(new Arcade::Core());
    core->addGraphicLib(loaderSFML->getGraphInstance());
    core->addGraphicLib(loaderSDL->getGraphInstance());
    core->addGraphicLib(loaderNCURSES->getGraphInstance());
    core->addGameLib(loaderPACMAN->getGameInstance());
    core->addGameLib(loaderSNAKE->getGameInstance());

    core->startGraphic();
    while (core->isRunning()) {
        core->getCurrentGraphicLib()->display();
        if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::QUIT)
            core->setRunning(false);
        if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::SWITCH_LIB)
            core->switchGraphicLib();
        if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::SWITCH_GAME)
            core->switchGameLib();
    }
    core->stopGraphic();
    std::cout << "end of program" << std::endl;
    return (0);
}
