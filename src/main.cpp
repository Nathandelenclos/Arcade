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
#include "Utils.hpp"

int main(int ac, char **av)
{
    std::shared_ptr<Arcade::ErrorHandling> error(new Arcade::ErrorHandling());
    error->checkForValidArg(ac, av);
    error->getLibFiles();
    error->loadLibs();
    error->loadGames();
    std::shared_ptr<Arcade::Core> core(new Arcade::Core());
    core->getGraphicalInstances(error->getGraphicLibsLoader());
    core->getGameInstances(error->getGameLibsLoader());
    core->setCurrentGraphicLib(1);
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
