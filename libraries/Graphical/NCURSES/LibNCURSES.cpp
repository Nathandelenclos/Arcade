/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibNCURSES.cpp
*/

#include "LibNCURSES.hpp"

namespace Arcade {

    LibNCURSES::LibNCURSES()
    {
        std::cout << "constructor LibNCURSES" << std::endl;
    }

    LibNCURSES::~LibNCURSES()
    {
        std::cout << "destructor LibNCURSES" << std::endl;
    }

    void LibNCURSES::loadObjects(IObjectVector gameObjects)
    {

    }

    InputKey LibNCURSES::getCurrentKey()
    {
        return InputKey::PAUSE;
    }

    void LibNCURSES::display()
    {

    }

    windowsParameter_t LibNCURSES::getWindow()
    {
        return (_windowsParameter);
    }

    void LibNCURSES::setWindow(windowsParameter_t windows_parameter)
    {

    }

    void LibNCURSES::openWindow()
    {

    }

    void LibNCURSES::closeWindow()
    {

    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibNCURSES();
    }
}
