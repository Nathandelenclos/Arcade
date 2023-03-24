/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** SDL.hpp
*/

#pragma once

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include "IObject.hpp"
#include <SDL2/SDL_ttf.h>

namespace Arcade {
    namespace sdl {
        typedef struct {
            pos_t pos;
            size_t width;
            size_t height;
        } rect_t;

        class Window {
            public:
                Window();
                ~Window();
                Window(std::string &title, int width, int height, bool fullscreen);
                void create(std::string &title, int width, int height, bool fullscreen);
                void create();
                void setTitle(std::string &title);
                void setFullScreen(bool fullscreen);
                void setIcon(std::string &filename);
                void destroy();
                bool isOpened() const;
                void setOpened(bool isOpened);
                SDL_Window *getWindow() const;
            protected:
                SDL_Window *_window;
                std::string _title;
                int _width;
                int _height;
                bool _fullscreen;
                SDL_Surface *_icon;
                bool _isOpened;
            private:
        };

        class Surface;
        typedef std::shared_ptr<sdl::Surface> SurfacePtr;
        typedef std::vector<SurfacePtr> SurfaceVector;
        typedef std::shared_ptr<SurfaceVector> SurfaceVectorPtr;

        class Surface {
            public:
                Surface();
                ~Surface();
                void destroy();
                static SurfacePtr loadFromFile(std::string &filename);
                static SurfacePtr loadFromFont(const std::string &filename, const std::string &str);
                SDL_Surface *getSurface() const;
            protected:
                SDL_Surface *_surface;
            private:
        };
        class Texture;
        typedef std::shared_ptr<sdl::Texture> TexturePtr;
        typedef std::vector<TexturePtr> TextureVector;
        typedef std::shared_ptr<TextureVector> TextureVectorPtr;
        class Texture {
            public:
                Texture();
                ~Texture();
                void destroy();
                static TexturePtr loadFromFile(std::string &filename, SDL_Renderer *renderer);
                static TexturePtr loadFromSurface(Surface *surface, SDL_Renderer *renderer);
                static TexturePtr loadFromText(const std::string &text, const std::string &filename, color_t color, SDL_Renderer *renderer);
                static TexturePtr loadFromText(std::string &text, std::string &filename, color_t color, int size, SDL_Renderer *renderer);
                static TexturePtr loadFromText(std::string &text, std::string &filename, color_t color, int size, int style, SDL_Renderer *renderer);
                SDL_Texture *getTexture() const;
            protected:
                SDL_Texture *_texture;
            private:
        };

        class Renderer;
        typedef std::shared_ptr<sdl::Renderer> RendererPtr;
        typedef std::vector<RendererPtr> RendererVector;
        typedef std::shared_ptr<RendererVector> RendererVectorPtr;
        class Renderer {
            public:
                Renderer();
                ~Renderer();
                void create(Window &window);
                void destroy();
                void present();
                SDL_Renderer *getRenderer() const;
                void clear();
                void draw(Texture &texture, rect_t rect);
                void drawRect(pos_t pos, size_t width, size_t height, color_t color);
//                void drawCircle(pos_t pos, size_t radius, color_t color);
//                void drawLine(pos_t pos1, pos_t pos2, color_t color);
            protected:
                SDL_Renderer *_renderer;
            private:
        };

        class Event {
            public:
                Event();
                ~Event();
                void pollEvent();
                bool isKeyPressed(SDL_Keycode key);
                bool isKeyReleased(SDL_Keycode key);
                SDL_Event getEvent();
            protected:
                SDL_Event _event;
            private:
        };

        typedef std::shared_ptr<sdl::Window> WindowPtr;
        typedef std::vector<WindowPtr> WindowVector;
        typedef std::shared_ptr<WindowVector> WindowVectorPtr;
        typedef std::shared_ptr<sdl::Texture> TexturePtr;
        typedef std::vector<sdl::TexturePtr> TextureVector;
        typedef std::shared_ptr<sdl::TextureVector> TextureVectorPtr;
    }
}
