/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IGraphicLib.hpp
*/

#ifndef BS_ARCADE_ILIB_HPP
#define BS_ARCADE_ILIB_HPP

#include <iostream>
#include "IObject.hpp"
#include "Types.hpp"
#include "EKey.hpp"

#define GRAPHICSYM "constructor_graphic"

namespace Arcade {
    /**
     * @brief The windows parameters
     */
    typedef struct {
        unsigned int width;
        unsigned int height;
        bool fullScreen;
    } windowsParameter_t;

    class IGraphicLib {
        public:
            /**
             * @brief Destroy the IGraphicLib object
             */
            virtual ~IGraphicLib() = default;
            /**
             * @brief Load the objects
             * @param gameObjects The vector of objects to load
             */
            virtual void loadObjects(IObjectVector gameObjects) = 0;
            /**
             * @brief Get the current key
             * @return The currently pressed key
             */
            virtual InputKey getCurrentKey() = 0;
            /**
             * @brief Display the objects
             */
            virtual void display() = 0;
            /**
             * @brief Get the window
             * @return The window parameters
             */
            virtual windowsParameter_t getWindow() = 0;
            /**
             * @brief Set the window
             * @param windows_parameter The window parameters
             */
            virtual void setWindow(windowsParameter_t windows_parameter) = 0;
            /**
             * @brief Open the window
             */
            virtual void openWindow() = 0;
            /**
             * @brief Close the window
             */
            virtual void closeWindow() = 0;
            /**
             * @brief Check if the window is open
             * @return True if the window is open, false otherwise
             */
            virtual bool isOpen() = 0;
    };
}

#endif //BS_ARCADE_ILIB_HPP