/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSDL.cpp
*/

#include "LibSDL.hpp"

namespace Arcade {

    /**
     * @brief Construct a new LibSDL:: LibSDL object
     */
    LibSDL::LibSDL()
    {
        std::cout << "constructor LibSDL" << std::endl;
    }

    /**
     * @brief Destroy the LibSDL:: LibSDL object
     */
    LibSDL::~LibSDL()
    {
        std::cout << "destructor LibSDL" << std::endl;
    }

    /**
     * @brief Init the window
     * @param gameObjects IObjectVector - The game objects
     */
    void LibSDL::loadObjects(IObjectVector gameObjects)
    {

    }

    InputKey LibSDL::getCurrentKey()
    {
        return InputKey::PAUSE;
    }

    void LibSDL::display()
    {

    }

    /**
     * @brief Get the current window
     * @return windowsParameter_t - The current window
     */
    windowsParameter_t LibSDL::getWindow()
    {
        return (_windowsParameter);
    }

    void LibSDL::setWindow(windowsParameter_t windows_parameter)
    {

    }

    void LibSDL::openWindow()
    {

    }

    void LibSDL::closeWindow()
    {

    }

    bool LibSDL::isOpen()
    {
        return false;
    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSDL();
    }
}
