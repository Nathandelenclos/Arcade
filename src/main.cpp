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
    std::shared_ptr<Arcade::Core> core(new Arcade::Core(error->getGraphicLibsLoader(), error->getGameLibsLoader()));
    core->setCurrentGraphicLib(1);
    core->startGraphic();
    while (core->isRunning()) {
        core->getCurrentGraphicLib()->display();
        if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::ESCAPE)
            core->setRunning(false);
        if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::SWITCH_LIB)
            core->switchGraphicLib();
        if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::SWITCH_GAME)
            core->switchGameLib();
        //core->getCurrentGameLib()->setCurrentInputKey(core->getCurrentGraphicLib()->getCurrentKey());
        //core->getCurrentGameLib()->updateGameObjects();
    }
    core->stopGraphic();
    return (0);
}
