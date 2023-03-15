/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IGraphicLib
*/

#include "IObject.hpp"

#pragma once

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
    };
}
