/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

namespace Arcade {

    Snake::Snake()
    {
        std::cout << "Snake constructor" << std::endl;
    }

    Snake::~Snake()
    {
        std::cout << "Snake destructor" << std::endl;
    }

    void Snake::setGameObjects()
    {

    }

    IObjectVector Snake::getGameObjects()
    {
        return Arcade::IObjectVector();
    }

    void Snake::updateGameObjects()
    {

    }

    bool Snake::isEnded()
    {
        return false;
    }

    void Snake::setCurrentInputKey(InputKey key)
    {

    }

    int Snake::getScore()
    {
        return 0;
    }

    extern "C" IGameLib *constructor_game()
    {
        return new Snake();
    }
}
