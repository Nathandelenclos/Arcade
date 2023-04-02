/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame.hpp
*/

#pragma once

#include "IGameLib.hpp"
#include "Entity.hpp"
#include "Snake.hpp"
#include <random>
#include "thread"

#define MAP "./assets/sprites/snake_game/map.png"

namespace Arcade {
    typedef struct {
        InputKey key;
        EDirection direction;
    } key_direction_t;

    static const key_direction_t key_directions[] = {
            {InputKey::UP, EDirection::UP},
            {InputKey::DOWN, EDirection::DOWN},
            {InputKey::LEFT, EDirection::LEFT},
            {InputKey::RIGHT, EDirection::RIGHT}
    };

    class SnakeGame : public IGameLib {
        public:
            SnakeGame();
            ~SnakeGame() override;

            void setGameObjects() override;
            IObjectVector getGameObjects() override;
            void updateGameObjects() override;
            bool isEnded() override;
            void setCurrentInputKey(InputKey key) override;
            int getScore() override;
            void moveSnake();
        protected:
            IObjectVector _gameObjects;
            int _isEnded;
            InputKey _currentKey;
            int _score;
        private:
            std::string apple;
            std::string map;
            SnakePtr _snake;

    };
}