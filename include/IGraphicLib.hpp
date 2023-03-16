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

    typedef struct {
        int width;
        int height;
        bool fullScreen;
    } windowsParameter_t;

    class IGraphicLib {
        public:
            virtual ~IGraphicLib() = default;

            virtual void loadObjects(IObjectVector gameObjects) = 0;
            virtual InputKey getCurrentKey() = 0;
            virtual void display() = 0;
            virtual windowsParameter_t getWindow() = 0;
            virtual void setWindow(windowsParameter_t windows_parameter) = 0;
            virtual void openWindow() = 0;
            virtual void closeWindow() = 0;
    };
}

#endif //BS_ARCADE_ILIB_HPP