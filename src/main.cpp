/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** main.cpp
*/

#include "Types.hpp"
#include "Core.hpp"
#include "Utils.hpp"

/**
 * @brief Main function
 *
 * @param ac {int} - number of arguments
 * @param av {char**} - arguments
 * @return int - EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    std::shared_ptr<Arcade::ErrorHandling> error(new Arcade::ErrorHandling());
    error->checkForValidArg(ac, av);
    error->getLibFiles();
    error->loadLibs();
    error->loadGames();
    std::shared_ptr<Arcade::Core> core(new Arcade::Core(error->getGraphicLibsLoader(), error->getGameLibsLoader(),
                                                        error->getLibs(), error->getGames()));
    core->setCurrentGraphicLib(1);
    core->createMainMenu(error->getLibs(), error->getGames());
    core->startGraphic();
    while (core->isRunning()) {
        core->getCurrentGraphicLib()->display();
        core->logicalMenu();
        if (core->getState() == Arcade::CoreState::GAME) {
            if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::ESCAPE)
                core->setState(Arcade::CoreState::MENU);
            if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::SWITCH_LIB)
                core->switchGraphicLib();
            if (core->getCurrentGraphicLib()->getCurrentKey() == Arcade::InputKey::SWITCH_GAME)
                core->switchGameLib();
            core->getCurrentGameLib()->setCurrentInputKey(core->getCurrentGraphicLib()->getCurrentKey());
            core->getCurrentGameLib()->updateGameObjects();
        }
        core->getCurrentGraphicLib()->loadObjects(core->getGameObjects());
    }
    core->stopGraphic();
    return EXIT_SUCCESS;
}
