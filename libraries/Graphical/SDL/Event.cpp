/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Event.cpp
*/

#include "SDL.hpp"

namespace Arcade {
    namespace sdl {

        /**
         * @brief Create the Event object :: Event object
         */
        Event::Event() = default;

        /**
         * @brief Destroy the Event object :: Destroy the event
         */
        Event::~Event() = default;

        /**
         * @brief Set the poll event :: Set the poll eventl
         */
        bool Event::pollEvent() {
            return SDL_PollEvent(&_event);
        }

        /**
         * @brief Check if a key is pressed :: Check if a key is pressed
         * @param key Key
         * @return true Key is pressed
         * @return false Key is not pressed
         */
        bool Event::isKeyPressed(SDL_Keycode key) {
            return this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == key;
        }

        /**
         * @brief Check if a key is released :: Check if a key is released
         * @param key Key
         * @return true Key is released
         * @return false Key is not released
         */
        bool Event::isKeyReleased(SDL_Keycode key) {
            return this->_event.type == SDL_KEYUP && this->_event.key.keysym.sym == key;
        }

        /**
         * @brief get the current event :: Get the current event
         * @return
         */
        SDL_Event Event::getEvent() {
            return this->_event;
        }
    }
}