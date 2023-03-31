/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSDL.hpp
*/

#pragma once

#include "IGraphicLib.hpp"
#include "SDL.hpp"
#include "SDL2/SDL_events.h"
#include "EKey.hpp"
#include "IObject.hpp"

namespace Arcade {
    typedef struct {
        SDL_KeyCode key;
        InputKey inputKey;
    } keyMatching;

    static keyMatching matching[] {
            {SDLK_UP, InputKey::UP},
            {SDLK_DOWN, InputKey::DOWN},
            {SDLK_LEFT, InputKey::LEFT},
            {SDLK_RIGHT, InputKey::RIGHT},
            {SDLK_q, InputKey::INTERACT},
            {SDLK_RETURN, InputKey::PAUSE},
            {SDLK_ESCAPE, InputKey::ESCAPE},
            {SDLK_a, InputKey::SWITCH_LIB},
            {SDLK_e, InputKey::SWITCH_GAME},
            {SDLK_b, InputKey::KEY_B},
            {SDLK_c, InputKey::KEY_C},
            {SDLK_d, InputKey::KEY_D},
            {SDLK_f, InputKey::KEY_F},
            {SDLK_g, InputKey::KEY_G},
            {SDLK_h, InputKey::KEY_H},
            {SDLK_i, InputKey::KEY_I},
            {SDLK_j, InputKey::KEY_J},
            {SDLK_k, InputKey::KEY_K},
            {SDLK_l, InputKey::KEY_L},
            {SDLK_m, InputKey::KEY_M},
            {SDLK_n, InputKey::KEY_N},
            {SDLK_o, InputKey::KEY_O},
            {SDLK_p, InputKey::KEY_P},
            {SDLK_r, InputKey::KEY_R},
            {SDLK_s, InputKey::KEY_S},
            {SDLK_t, InputKey::KEY_T},
            {SDLK_u, InputKey::KEY_U},
            {SDLK_v, InputKey::KEY_V},
            {SDLK_w, InputKey::KEY_W},
            {SDLK_x, InputKey::KEY_X},
            {SDLK_y, InputKey::KEY_Y},
            {SDLK_z, InputKey::KEY_Z},
            {SDLK_UNKNOWN, InputKey::NONE}
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
            sdl::TextureVectorPtr _rectTextures;
            sdl::TextureVectorPtr _textures;
        private:
            InputKey _key;
            sdl::WindowPtr _window;
            sdl::RendererPtr _renderer;
            sdl::EventPtr _event;
    };

    typedef struct {
        ObjectType type;
        void (LibSDL::*init)(const IObjectPtr &object);
    } initType_t;
}
