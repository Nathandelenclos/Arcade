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
            InputKey _key;
            IObjectVector _objects;
        private:
    };
}