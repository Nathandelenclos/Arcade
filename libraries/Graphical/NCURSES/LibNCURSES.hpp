/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibNCURSES.hpp
*/

#pragma once

#include "IGraphicLib.hpp"
#include "ncurses.hpp"

namespace Arcade {

    typedef struct {
        int c;
        InputKey inputKey;
    } keyMatching;

    static keyMatching mapping[] {
        {KEY_UP, InputKey::UP},
        {KEY_DOWN, InputKey::DOWN},
        {KEY_LEFT, InputKey::LEFT},
        {KEY_RIGHT, InputKey::RIGHT},
        {'q', InputKey::INTERACT},
        {KEY_ENTER, InputKey::PAUSE},
        {KEY_CANCEL, InputKey::ESCAPE},
        {'a', InputKey::SWITCH_LIB},
        {'e', InputKey::SWITCH_GAME},
        {'b', InputKey::KEY_B},
        {'c', InputKey::KEY_C},
        {'d', InputKey::KEY_D},
        {'f', InputKey::KEY_F},
        {'g', InputKey::KEY_G},
        {'h', InputKey::KEY_H},
        {'i', InputKey::KEY_I},
        {'j', InputKey::KEY_J},
        {'k', InputKey::KEY_K},
        {'l', InputKey::KEY_L},
        {'m', InputKey::KEY_M},
        {'n', InputKey::KEY_N},
        {'o', InputKey::KEY_O},
        {'p', InputKey::KEY_P},
        {'r', InputKey::KEY_R},
        {'s', InputKey::KEY_S},
        {'t', InputKey::KEY_T},
        {'u', InputKey::KEY_U},
        {'v', InputKey::KEY_V},
        {'w', InputKey::KEY_W},
        {'x', InputKey::KEY_X},
        {'y', InputKey::KEY_Y},
        {'z', InputKey::KEY_Z},
        {0, InputKey::NONE}
    };

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
            ncurses::WindowPtr _window;
            InputKey _currentKey;
            std::shared_ptr<std::vector<std::string>> _map;
        private:
    };
}
