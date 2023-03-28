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
        map = MAP;

        EntityPtr mapEntity = std::make_shared<Entity>(pos_t{0, 0}, map, "map", color_t {255, 255, 255, 255},rect_t{0, 30, 1920, 1080},true);
        _snake = std::make_shared<Snake>();
        _gameObjects->push_back(mapEntity);
        _gameObjects->push_back(_snake->getApple());
        _gameObjects->push_back(_snake->getHead());
        _gameObjects->push_back(_snake->getTail());
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
        _snake->mapBorder();
        if (_snake->checkCollision()) {
            _snake->addBody(_gameObjects);
            _snake->placeApple();
        }
    }

    extern "C" IGameLib *constructor_game()
    {
        return new SnakeGame();
    }
}
