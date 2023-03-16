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
