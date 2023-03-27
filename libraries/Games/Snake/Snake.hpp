/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once

#include "IGameLib.hpp"
#include "Entity.hpp"

#define SNAKE_UP "./assets/sprites/snake_game/snakkel_UP.png"
#define SNAKE_DOWN "./assets/sprites/snake_game/snakkel_DOWN.png"
#define SNAKE_LEFT "./assets/sprites/snake_game/snakkel_LEFT.png"
#define SNAKE_RIGHT "./assets/sprites/snake_game/snakkel_RIGHT.png"
#define APPLE "./assets/sprites/snake_game/apple.png"
#define MAP "./assets/sprites/snake_game/map.png"

namespace Arcade {
    class Snake : public IGameLib {
        public:
            Snake();
            ~Snake() override;

            void setGameObjects() override;
            IObjectVector getGameObjects() override;
            void updateGameObjects() override;
            bool isEnded() override;
            void setCurrentInputKey(InputKey key) override;
            int getScore() override;

            void moveSnake();
            void setPosSnake();
        protected:
            IObjectVector _gameObjects;
            int _isEnded;
            InputKey _currentKey;
            int _score;
        private:
            std::string snakkel_up;
            std::string snakkel_down;
            std::string snakkel_left;
            std::string snakkel_right;
            std::string apple;
            std::string map;
    };
}