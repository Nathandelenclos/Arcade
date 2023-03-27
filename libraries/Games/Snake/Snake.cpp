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
        snakkel_up = SNAKE_UP;
        snakkel_down = SNAKE_DOWN;
        snakkel_left = SNAKE_LEFT;
        snakkel_right = SNAKE_RIGHT;
        apple = APPLE;
        map = MAP;
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{0, 0}, map, rect_t{0, 30, 1920, 1080}));
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{300, 200}, apple, rect_t{0, 0, 29, 28}));
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{400, 500}, snakkel_down, rect_t{0, 0, 56, 45}));
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{400, 548}, snakkel_down, rect_t{0, 120, 56, 65}));
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{700, 500}, snakkel_left, rect_t{0, 0, 65, 56}));
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{770, 500}, snakkel_left, rect_t{150, 0, 65, 56}));
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{700, 600}, snakkel_right, rect_t{0, 0, 40, 56}));
        _gameObjects->push_back(std::make_shared<Entity>(pos_t{745, 600}, snakkel_right, rect_t{120, 0, 65, 56}));
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
        moveSnake();
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

    void Snake::moveSnake()
    {
        if (_currentKey == InputKey::UP) {
            _gameObjects->push_back(std::make_shared<Entity>(pos_t{300, 500}, snakkel_up, rect_t{0, 0, 56, 65}));
            _gameObjects->push_back(std::make_shared<Entity>(pos_t{300, 568}, snakkel_up, rect_t{0, 140, 56, 65}));
        }
    }

    extern "C" IGameLib *constructor_game()
    {
        return new Snake();
    }
}
