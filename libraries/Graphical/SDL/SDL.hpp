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
#include "IGraphicLib.hpp"
#include "Types.hpp"

namespace Arcade {
    namespace sdl {
        typedef struct {
            pos_t pos;
            size_t width;
            size_t height;
        } rect_t;

        class Texture;

        typedef std::shared_ptr<sdl::Texture> TexturePtr;
        typedef std::vector<sdl::TexturePtr> TextureVector;
        typedef std::shared_ptr<sdl::TextureVector> TextureVectorPtr;

        class Surface;

        typedef std::shared_ptr<sdl::Surface> SurfacePtr;
        typedef std::vector<SurfacePtr> SurfaceVector;
        typedef std::shared_ptr<SurfaceVector> SurfaceVectorPtr;

        class Window;

        typedef std::shared_ptr<sdl::Window> WindowPtr;
        typedef std::vector<WindowPtr> WindowVector;
        typedef std::shared_ptr<WindowVector> WindowVectorPtr;

        class Renderer;

        typedef std::shared_ptr<sdl::Renderer> RendererPtr;
        typedef std::vector<RendererPtr> RendererVector;
        typedef std::shared_ptr<RendererVector> RendererVectorPtr;

        class Event;

        typedef std::shared_ptr<sdl::Event> EventPtr;
        typedef std::vector<EventPtr> EventVector;
        typedef std::shared_ptr<EventVector> EventVectorPtr;

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
            windowsParameter_t getWindowParameter() const;
        protected:
            SDL_Window *_window;
            std::string _title;
            int _width;
            int _height;
            bool _fullscreen;
            SDL_Surface *_icon;
            bool _isOpened;
            Arcade::windowsParameter_t _windowParameter;
        private:
        };

        class Renderer {
        public:
            Renderer();
            ~Renderer();
            void create(const WindowPtr& window);
            void destroy();
            void present();
            SDL_Renderer *getRenderer() const;
            void clear();
            void draw(const TexturePtr &texture, rect_t rect);
            void drawRect(const TexturePtr& texture, rect_t rect);
            void setWindowParameter(const WindowPtr& window);
            windowsParameter_t getWindowParameter() const;
        protected:
            SDL_Renderer *_renderer;
            Arcade::windowsParameter_t _windowParameter;
        private:
        };

        class Surface {
        public:
            Surface();
            ~Surface();
            void destroy();
            static SurfacePtr loadFromFile(std::string &filename);
            static SurfacePtr loadFromFont(const std::string &filename, const std::string &str, int size, color_t color);
            static SurfacePtr loadFromFont(const std::string &filename, const std::string &str, color_t color);
            static SurfacePtr loadFromFont(const std::string &filename, const std::string &str, int size);
            static SurfacePtr loadFromFont(const std::string &filename, const std::string &str);
            SDL_Surface *getSurface() const;
        protected:
            SDL_Surface *_surface{};
            TTF_Font *_font{};
        private:
        };

        class Texture {
        public:
            Texture();
            ~Texture();
            void destroy();
            static TexturePtr loadFromText(const RendererPtr& renderer, const std::string &text, const std::string &filename, color_t color, int size, pos_t pos);
            static TexturePtr loadFromText(const RendererPtr& renderer, const std::string &text, const std::string &filename, color_t color, int size);
            static TexturePtr loadFromText(const RendererPtr& renderer, const std::string &text, const std::string &filename, color_t color);
            static TexturePtr loadFromSurface(const RendererPtr& renderer, const SurfacePtr &surface);
            static TexturePtr loadFromFile(const RendererPtr &renderer, std::string &filename, pos_t pos);
            static TexturePtr loadFromRectangle(const RendererPtr& renderer, size_t width, size_t height, color_t color, pos_t pos);
            SDL_Texture *getTexture() const;
            rect_t getRect() const;
            void setRect(rect_t rect);
            color_t getColor() const;
            void setColor(color_t color);
        protected:
            SDL_Texture *_texture;
            rect_t _rect;
            color_t _color;
        private:
        };

        class Event {
        public:
            Event();
            ~Event();
            bool pollEvent();
            bool isKeyPressed(SDL_Keycode key);
            bool isKeyReleased(SDL_Keycode key);
            SDL_Event getEvent();
        protected:
            SDL_Event _event;
        private:
        };

    }
}
