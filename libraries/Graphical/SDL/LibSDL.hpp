/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSDL.hpp
*/

#pragma once

#include "IGraphicLib.hpp"
#include "SDL.hpp"
#include "EKey.hpp"
#include "IObject.hpp"

namespace Arcade {
    typedef struct {
        SDL_KeyboardEvent key;
        InputKey inputKey;
    } keyMatching;

    static keyMatching matching[] {
            {SDLK_UP,       static_cast<Uint32>(InputKey::UP)},
            {SDLK_DOWN,     static_cast<Uint32>(InputKey::DOWN)},
            {SDLK_LEFT,     static_cast<Uint32>(InputKey::LEFT)},
            {SDLK_RIGHT,    static_cast<Uint32>(InputKey::RIGHT)},
            {SDLK_e,        static_cast<Uint32>(InputKey::INTERACT)},
            {SDLK_KP_ENTER, static_cast<Uint32>(InputKey::PAUSE)},
            {SDLK_ESCAPE,   static_cast<Uint32>(InputKey::QUIT)},
            {SDLK_a,        static_cast<Uint32>(InputKey::SWITCH_LIB)},
            {SDLK_e,        static_cast<Uint32>(InputKey::SWITCH_GAME)},
    };

    class LibSDL : public IGraphicLib {
        public:
            LibSDL();
            ~LibSDL() override;

            void loadObjects(IObjectVector gameObjects) override;
            InputKey getCurrentKey() override;
            void display() override;
            windowsParameter_t getWindow() override;
            void setWindow(windowsParameter_t windows_parameter) override;
            void openWindow() override;
            void closeWindow() override;
            bool isOpen() override;
            void initText(const IObjectPtr& object);
            void initSprite(const IObjectPtr& object);
            void eventListener();

        protected:
            windowsParameter_t _windowsParameter;
            IObjectVector _objects;
        private:
            InputKey _key;
    };

    typedef struct {
        ObjectType type;
        void (LibSDL::*init)(const IObjectPtr &object);
    } initType_t;
}
