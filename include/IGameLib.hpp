/*
** EPITECH PROJECT, 2023
** bs_arcade
** File description:
** IGraphicLib.hpp
*/

#ifndef ARCADE_GAMELIB_HPP
#define ARCADE_GAMELIB_HPP

#include <iostream>
#include "IObject.hpp"
#include "EKey.hpp"
#include "Types.hpp"

#define GAMESYM "constructor_game"

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
#endif // ARCADE_GAMELIB_HPP
