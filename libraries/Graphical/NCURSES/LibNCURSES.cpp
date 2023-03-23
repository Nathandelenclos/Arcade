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
        _window = std::make_shared<ncurses::Window>();
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
        return _currentKey;
    }

    void LibNCURSES::display()
    {
        _window->display(_map);
    }

    windowsParameter_t LibNCURSES::getWindow()
    {
        return (_windowsParameter);
    }

    void LibNCURSES::setWindow(windowsParameter_t windowsParameter)
    {
        _windowsParameter = windowsParameter;
    }

    void LibNCURSES::openWindow()
    {
        _window->open();
    }

    void LibNCURSES::closeWindow()
    {

    }

    bool LibNCURSES::isOpen()
    {
        return false;
    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibNCURSES();
    }
}
