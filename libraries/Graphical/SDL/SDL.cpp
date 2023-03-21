/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** SDL.cpp
*/

#include "SDL.hpp"

namespace Arcade {
    namespace sdl {
        Window::Window() {
        }

        Window::Window(std::string &title, int width, int height,
                       bool fullscreen) {
            this->_title = title;
            this->_width = width;
            this->_height = height;
            this->_fullscreen = fullscreen;
        }

        void Window::create(std::string &title, int width, int height,
                            bool fullscreen) {
            this->_window = SDL_CreateWindow(title.c_str(),
                                               SDL_WINDOWPOS_CENTERED,
                                               SDL_WINDOWPOS_CENTERED, width,
                                               height, fullscreen
                                                       ? SDL_WINDOW_FULLSCREEN
                                                       : SDL_WINDOW_SHOWN);
            if (this->_window == nullptr) {
                std::cout << "SDL_CreateWindow Error: " << SDL_GetError()
                          << std::endl;
                exit(84);
            }
        }

        void Window::create() {
            this->_window = SDL_CreateWindow(this->_title.c_str(),
                                             SDL_WINDOWPOS_CENTERED,
                                             SDL_WINDOWPOS_CENTERED, this->_width,
                                             this->_height, this->_fullscreen
                                                     ? SDL_WINDOW_FULLSCREEN
                                                     : SDL_WINDOW_SHOWN);
            if (this->_window == nullptr) {
                std::cout << "SDL_CreateWindow Error: " << SDL_GetError()
                          << std::endl;
                exit(84);
            }
        }

        void Window::setTitle(std::string &title) {
            SDL_SetWindowTitle(this->_window, title.c_str());
        }

        void Window::setFullScreen(bool fullscreen) {
            fullscreen ? SDL_SetWindowFullscreen(this->_window, SDL_WINDOW_FULLSCREEN) : SDL_SetWindowFullscreen(this->_window, 0);
        }

        void Window::setIcon(std::string &filename) {
            this->_icon = IMG_Load(filename.c_str());
            SDL_SetWindowIcon(this->_window, this->_icon);
        }

        void Window::destroy() {
            SDL_FreeSurface(this->_icon);
            SDL_DestroyWindow(this->_window);
        }

        Window::~Window() = default;

        Surface::Surface() {
        }

        Surface::~Surface() = default;

        void Surface::destroy() {
            SDL_FreeSurface(this->_surface);
        }

        Surface Surface::loadFromFile(std::string &filename) {
            Surface surface;
            surface._surface = IMG_Load(filename.c_str());
            if (surface._surface == nullptr) {
                std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl;
                exit(84);
            }
            return surface;
        }

        SDL_Surface *Surface::getSurface() const {
            return this->_surface;
        }

        Texture::Texture() {
        }

        Texture::~Texture() = default;

        void Texture::destroy() {
            SDL_DestroyTexture(this->_texture);
        }

        Texture Texture::loadFromSurface(Surface *surface, SDL_Renderer *renderer) {
            Texture texture;
            texture._texture = SDL_CreateTextureFromSurface(renderer, surface->getSurface());
            if (texture._texture == nullptr) {
                std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            return texture;
        }

        Texture Texture::loadFromFile(std::string &filename, SDL_Renderer *renderer) {
            Texture texture;
            texture._texture = IMG_LoadTexture(renderer, filename.c_str());
            if (texture._texture == nullptr) {
                std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
                exit(84);
            }
            return texture;
        }

        /*Texture Texture::loadFromText(std::string &text, std::string &filename,
                                      color_t color) {
            Texture texture;
        }*/
    }
}