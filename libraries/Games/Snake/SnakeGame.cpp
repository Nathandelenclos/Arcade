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
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _currentKey = InputKey::NONE;
        _isEnded = false;
        _score = 0;

        _snake = std::make_shared<Snake>();
        _snake->createWalls();
        for (int i = 0; i < 4; i++) {
            _snake->addBody(_gameObjects);
            _gameObjects->push_back(_snake->getBodyPart(i));
        }
        _gameObjects->push_back(_snake->getApple());
        for (int i = 0; i < 4; i++) {
            _gameObjects->push_back(_snake->getWalls(i));
        }
    }

    SnakeGame::~SnakeGame()
    {
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
        if (isEnded())
            return;
        if (_snake->checkWallCollision()) {
            _isEnded = true;
            return;
        }
        if (_snake->checkCollision()) {
            _score += 1;
            _snake->addBody(_gameObjects);
            _snake->placeApple();
        }
        for (int i = 1; i < _snake->getBody()->size(); i++) {
            if (_snake->comparePos(_snake->getBodyPart(0), _snake->getBodyPart(i))) {
                _isEnded = true;
                return;
            }
        }
        _snake->movement();
    }

    extern "C" IGameLib *constructor_game()
    {
        return new SnakeGame();
    }
}
