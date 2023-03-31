/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame.cpp
*/

#include "SnakeGame.hpp"

namespace Arcade {

    SnakeGame::SnakeGame()
    {
        std::cout << "SnakeGame constructor" << std::endl;
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _currentKey = InputKey::NONE;
        _isEnded = false;
        _score = 0;

        _snake = std::make_shared<Snake>();
        _snake->addBody(_gameObjects);
        _snake->addBody(_gameObjects);
        _snake->addBody(_gameObjects);
        _snake->addBody(_gameObjects);
        _gameObjects->push_back(_snake->getBodyPart(0));
        _gameObjects->push_back(_snake->getBodyPart(1));
        _gameObjects->push_back(_snake->getBodyPart(2));
        _gameObjects->push_back(_snake->getBodyPart(3));
    }

    SnakeGame::~SnakeGame()
    {
        std::cout << "SnakeGame destructor" << std::endl;
    }

    void SnakeGame::setGameObjects()
    {

    }

    IObjectVector SnakeGame::getGameObjects()
    {
        return _gameObjects;
    }

    void SnakeGame::updateGameObjects()
    {
        moveSnake();
    }

    bool SnakeGame::isEnded()
    {
        return _isEnded;
    }

    void SnakeGame::setCurrentInputKey(InputKey key)
    {
        _currentKey = key;
    }

    int SnakeGame::getScore()
    {
        return _score;
    }

    void SnakeGame::moveSnake()
    {
        for (key_direction_t key_direction: key_directions) {
            if (key_direction.key == _currentKey) {
                _snake->changeDirection(key_direction.direction);
                break;
            }
        }
        _snake->movement();
    }

    extern "C" IGameLib *constructor_game()
    {
        return new SnakeGame();
    }
}
