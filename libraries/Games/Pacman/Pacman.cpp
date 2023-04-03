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
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _currentKey = InputKey::NONE;
        _isEnded = false;
        _score = 0;
        _grid = std::make_shared<Grid>();
        _gameObjects->push_back(_grid->getPacman());
        _mapEntities = _grid->getMap();
        for (const EntityPtr& entity : _mapEntities) {
            _gameObjects->push_back(entity);
        }
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
        return _gameObjects;
    }

    void Pacman::updateGameObjects()
    {
        runPacman();
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

    void Pacman::runPacman()
    {
        for (key_direction_t keyDirection : key_direction) {
            if (keyDirection.key == _currentKey) {
                _grid->changeDirection(keyDirection.direction);
                break;
            }
        }
        _grid->movePacman();
    }

    extern "C" IGameLib *constructor_game()
    {
        return new Pacman();
    }
}
