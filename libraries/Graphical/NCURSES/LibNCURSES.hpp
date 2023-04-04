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
        {10, InputKey::INTERACT},
        {27 , InputKey::ESCAPE},
        {'&', InputKey::SWITCH_LIB},
        {'"', InputKey::SWITCH_GAME},
        {KEY_BACKSPACE, InputKey::BackSpace},
        {32, InputKey::SPACE},
        {'a', InputKey::KEY_A},
        {'b', InputKey::KEY_B},
        {'c', InputKey::KEY_C},
        {'d', InputKey::KEY_D},
        {'e', InputKey::KEY_E},
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
        {'q', InputKey::KEY_Q},
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
            void eventListener();
            void initEntity(const IObjectPtr& object);
            void initText(const IObjectPtr &object);
            static ncurses::charPtr searchChar(const ncurses::charVectorPtr &v,pos_t pos);
        protected:
            windowsParameter_t _windowsParameter;
            ncurses::WindowPtr _window;
            InputKey _currentKey;
            ncurses::charVectorPtr _map;
            ncurses::textVectorPtr _texts;
            ncurses::ColorVectorPtr _colors;
            ncurses::ColorPairVectorPtr _pairs;
        private:
    };

    typedef struct {
        ObjectType type;
        void (LibNCURSES::*init)(const IObjectPtr& object);
    } initType_t;


}
