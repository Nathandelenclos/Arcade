/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSFML.cpp
*/

#include "LibSFML.hpp"

namespace Arcade {

    LibSFML::LibSFML()
    {
        std::cout << "constructor LibSFML" << std::endl;
    }

    LibSFML::~LibSFML()
    {
        std::cout << "destructor LibSFML" << std::endl;
    }

    void LibSFML::loadObjects(IObjectVector gameObjects)
    {

    }

    InputKey LibSFML::getCurrentKey()
    {
        return InputKey::PAUSE;
    }

    void LibSFML::display()
    {

    }

    windowsParameter_t LibSFML::getWindow()
    {
        return (_windowsParameter);
    }

    void LibSFML::setWindow(windowsParameter_t windows_parameter)
    {

    }

    void LibSFML::openWindow()
    {

    }

    void LibSFML::closeWindow()
    {

    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSFML();
    }
}
