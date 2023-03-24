/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once

#include "IGameLib.hpp"

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
        protected:
            IObjectVector _gameObjects;
            int _isEnded;
            InputKey _currentKey;
            int _score;
        private:
    };
}