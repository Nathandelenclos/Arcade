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
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _currentKey = InputKey::NONE;
        _isEnded = false;
        _score = 0;
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
        return _gameObjects;
    }

    void Snake::updateGameObjects()
    {

    }

    bool Snake::isEnded()
    {
        return _isEnded;
    }

    void Snake::setCurrentInputKey(InputKey key)
    {
        _currentKey = key;
    }

    int Snake::getScore()
    {
        return _score;
    }

    extern "C" IGameLib *constructor_game()
    {
        return new Snake();
    }
}
