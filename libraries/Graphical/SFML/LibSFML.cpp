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
        if (_window.isOpen())
            _window.close();
        std::cout << "destructor LibSFML" << std::endl;
    }

    void LibSFML::loadObjects(IObjectVector gameObjects)
    {
        _objects = gameObjects;
    }

    InputKey LibSFML::getCurrentKey()
    {
       return (_key);
    }

    void LibSFML::display()
    {
        _key = InputKey::NONE;

        if (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                _key = InputKey::UP;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                _key = InputKey::DOWN;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                _key = InputKey::LEFT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                _key = InputKey::RIGHT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                _key = InputKey::INTERACT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                _key = InputKey::PAUSE;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _key = InputKey::QUIT;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                _key = InputKey::SWITCH_LIB;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                _key = InputKey::SWITCH_GAME;

        }
    }

    windowsParameter_t LibSFML::getWindow()
    {
        return (_windowsParameter);
    }

    void LibSFML::setWindow(windowsParameter_t windows_parameter)
    {
        _videoMode = {windows_parameter.width, windows_parameter.height, 32};
    }

    void LibSFML::openWindow()
    {
        _window.create(_videoMode, "Arcade", sf::Style::Close | sf::Style::Resize);
    }

    void LibSFML::closeWindow()
    {
        _window.close();
    }

    bool LibSFML::isOpen()
    {
        return (_window.isOpen());
    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSFML();
    }
}
