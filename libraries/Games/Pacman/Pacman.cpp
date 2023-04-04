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
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _currentKey = InputKey::NONE;
        _isEnded = false;
        _score = 0;
    }

    Pacman::~Pacman()
    {
    }

    void Pacman::setGameObjects()
    {

    }

    IObjectVector Pacman::getGameObjects()
    {
        return _gameObjects;
    }

    void Pacman::updateGameObjects()
    {

    }

    bool Pacman::isEnded()
    {
        return _isEnded;
    }

    void Pacman::setCurrentInputKey(InputKey key)
    {
        _currentKey = key;
    }

    int Pacman::getScore()
    {
        return _score;
    }

    extern "C" IGameLib *constructor_game()
    {
        return new Pacman();
    }
}
