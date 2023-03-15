/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IGameLib
*/

#include "IObject.hpp"

#pragma once

namespace Arcade {
    class IGameLib {
        public:
            virtual ~IGameLib() = default;

            virtual void setGameObjects() = 0;
            virtual IObjectVector getGameObjects() = 0;
            virtual void updateGameObjects() = 0;
            virtual bool isEnded() = 0;
            virtual void setCurrentInputKey(InputKey key) = 0;
            virtual int getScore() = 0;
    };
}
