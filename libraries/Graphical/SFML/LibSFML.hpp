/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSFML.hpp
*/

#pragma once

#include "IGraphicLib.hpp"
#include "SFML/Graphics.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "IObject.hpp"

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
        {sf::Keyboard::Q, InputKey::INTERACT},
        {sf::Keyboard::Enter, InputKey::PAUSE},
        {sf::Keyboard::Escape, InputKey::ESCAPE},
        {sf::Keyboard::A, InputKey::SWITCH_LIB},
        {sf::Keyboard::E, InputKey::SWITCH_GAME},
        {sf::Keyboard::A, InputKey::KEY_A},
        {sf::Keyboard::B, InputKey::KEY_B},
        {sf::Keyboard::C, InputKey::KEY_C},
        {sf::Keyboard::D, InputKey::KEY_D},
        {sf::Keyboard::E, InputKey::KEY_E},
        {sf::Keyboard::F, InputKey::KEY_F},
        {sf::Keyboard::G, InputKey::KEY_G},
        {sf::Keyboard::H, InputKey::KEY_H},
        {sf::Keyboard::I, InputKey::KEY_I},
        {sf::Keyboard::J, InputKey::KEY_J},
        {sf::Keyboard::K, InputKey::KEY_K},
        {sf::Keyboard::L, InputKey::KEY_L},
        {sf::Keyboard::M, InputKey::KEY_M},
        {sf::Keyboard::N, InputKey::KEY_N},
        {sf::Keyboard::O, InputKey::KEY_O},
        {sf::Keyboard::P, InputKey::KEY_P},
        {sf::Keyboard::Q, InputKey::KEY_Q},
        {sf::Keyboard::R, InputKey::KEY_R},
        {sf::Keyboard::S, InputKey::KEY_S},
        {sf::Keyboard::T, InputKey::KEY_T},
        {sf::Keyboard::U, InputKey::KEY_U},
        {sf::Keyboard::V, InputKey::KEY_V},
        {sf::Keyboard::W, InputKey::KEY_W},
        {sf::Keyboard::X, InputKey::KEY_X},
        {sf::Keyboard::Y, InputKey::KEY_Y},
        {sf::Keyboard::Z, InputKey::KEY_Z},
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
            void eventListener();
            void initText(const IObjectPtr& object);
            void initSprite(const IObjectPtr& object);

        protected:
            windowsParameter_t _windowsParameter{};
            sfml::IObjectVectorPtr _objects;
        private:
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;
            sf::Event _event{};
            InputKey _key;
    };

    typedef struct {
        ObjectType type;
        void (LibSFML::*init)(const IObjectPtr& object);
    } initType_t;
}
