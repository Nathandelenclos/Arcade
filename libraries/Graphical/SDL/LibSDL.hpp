/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSDL.hpp
*/

#pragma once

#include "IGraphicLib.hpp"

namespace Arcade {

    class LibSDL : public IGraphicLib {
        public:
            LibSDL();
            ~LibSDL() override;

            void loadObjects(IObjectVector gameObjects) override;
            InputKey getCurrentKey() override;
            void display() override;
            windowsParameter_t getWindow() override;
            void setWindow(windowsParameter_t windows_parameter) override;
            void openWindow() override;
            void closeWindow() override;

        protected:
            windowsParameter_t _windowsParameter;
        private:
    };
}