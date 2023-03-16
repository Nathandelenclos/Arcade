/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibNCURSES.hpp
*/

#pragma once

#include "IGraphicLib.hpp"

namespace Arcade {

    class LibNCURSES : public IGraphicLib {
        public:
            LibNCURSES();
            ~LibNCURSES() override;

            void loadObjects(IObjectVector gameObjects) override;
            InputKey getCurrentKey() override;
            void display() override;
            windowsParameter_t getWindow() override;
            void setWindow(windowsParameter_t windows_parameter) override;
            void openWindow() override;
            void closeWindow() override;
            bool isOpen() override;

        protected:
            windowsParameter_t _windowsParameter;
        private:
    };
}
