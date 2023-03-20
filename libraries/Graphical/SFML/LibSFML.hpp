/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSFML.hpp
*/

#pragma once

#include "IGraphicLib.hpp"
#include "SFML/Graphics.hpp"

namespace Arcade {
    typedef struct {
        sf::Keyboard::Key key;
        InputKey inputKey;
    } keyMatching;

    static keyMatching matching[] {
        {sf::Keyboard::Up, InputKey::UP},
        {sf::Keyboard::Down, InputKey::DOWN},
        {sf::Keyboard::Left, InputKey::LEFT},
        {sf::Keyboard::Right, InputKey::RIGHT},
        {sf::Keyboard::E, InputKey::INTERACT},
        {sf::Keyboard::Enter, InputKey::PAUSE},
        {sf::Keyboard::Escape, InputKey::QUIT},
        {sf::Keyboard::A, InputKey::SWITCH_LIB},
        {sf::Keyboard::E, InputKey::SWITCH_GAME},
    };

    class LibSFML : public IGraphicLib {
        public:
            LibSFML();
            ~LibSFML() override;

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
            IObjectVector _objects;
        private:
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;
            sf::Event _event;
            InputKey _key;

    };
}
