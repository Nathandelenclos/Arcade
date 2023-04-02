/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Pacman.hpp
*/

#pragma once

#include "IGameLib.hpp"
#include "Grid.hpp"

namespace Arcade {

    typedef struct {
        InputKey key;
        EDirection direction;
    } key_direction_t;

    static const key_direction_t key_direction[] = {
        {InputKey::UP, EDirection::UP},
        {InputKey::DOWN, EDirection::DOWN},
        {InputKey::LEFT, EDirection::LEFT},
        {InputKey::RIGHT, EDirection::RIGHT},
        {InputKey::NONE, EDirection::NONE}
    };

    class Pacman : public IGameLib {
        public:
            Pacman();
            ~Pacman() override;

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
            GridPtr _grid;
    };
}
