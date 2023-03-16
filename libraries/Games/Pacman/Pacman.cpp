/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"

namespace Arcade {

    Pacman::Pacman()
    {
        std::cout << "Pacman constructor" << std::endl;
    }

    Pacman::~Pacman()
    {
        std::cout << "Pacman destructor" << std::endl;
    }

    void Pacman::setGameObjects()
    {

    }

    IObjectVector Pacman::getGameObjects()
    {
        return Arcade::IObjectVector();
    }

    void Pacman::updateGameObjects()
    {

    }

    bool Pacman::isEnded()
    {
        return false;
    }

    void Pacman::setCurrentInputKey(InputKey key)
    {

    }

    int Pacman::getScore()
    {
        return 0;
    }

    extern "C" IGameLib *constructor_game()
    {
        return new Pacman();
    }
}
