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
            /**
             * @brief Destroy the IGameLib object
             */
            virtual ~IGameLib() = default;
            /**
             * @brief Set the game objects
             */
            virtual void setGameObjects() = 0;
            /**
             * @brief Get the game objects
             * @return The vector of game objects
             */
            virtual IObjectVector getGameObjects() = 0;
            /**
             * @brief Update the game objects
             */
            virtual void updateGameObjects() = 0;
            /**
             * @brief Check if game is ended or not
             * @return True if game is ended, false otherwise
             */
            virtual bool isEnded() = 0;
            /**
             * @brief Set the current input key
             * @param key The input key
             */
            virtual void setCurrentInputKey(InputKey key) = 0;
            /**
             * @brief Get the score
             * @return The score
             */
            virtual int getScore() = 0;
    };
}
#endif // ARCADE_GAMELIB_HPP
