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

        SDL_Window *Window::getWindow() const {
            return this->_window;
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

        Texture Texture::loadFromText(std::string &text, std::string &filename,
                                      color_t color, SDL_Renderer *renderer) {
            Texture texture;
            TTF_Font *font = TTF_OpenFont(filename.c_str(), 24);
            SDL_Color sdlColor = {color.r, color.g, color.b, color.a};
            SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);
            texture._texture = SDL_CreateTextureFromSurface(renderer, surface);
            return texture;
        }

        Texture Texture::loadFromText(std::string &text, std::string &filename,
                                      color_t color, int size,
                                      SDL_Renderer *renderer) {
            Texture texture;
            TTF_Font *font = TTF_OpenFont(filename.c_str(), size);
            SDL_Color sdlColor = {color.r, color.g, color.b, color.a};
            SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);
            texture._texture = SDL_CreateTextureFromSurface(renderer, surface);
            return texture;
        }

        Texture Texture::loadFromText(std::string &text, std::string &filename,
                                      color_t color, int size, int style,
                                      SDL_Renderer *renderer) {
            Texture texture;
            TTF_Font *font = TTF_OpenFont(filename.c_str(), size);
            SDL_Color sdlColor = {color.r, color.g, color.b, color.a};
            TTF_SetFontStyle(font, style == 0 ? 0 : (1 << style));
            SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);
            texture._texture = SDL_CreateTextureFromSurface(renderer, surface);
            return texture;
        }

        SDL_Texture *Texture::getTexture() const {
            return this->_texture;
        }

        Renderer::Renderer() {
        }

        Renderer::~Renderer() {
        }

        void Renderer::create(Window &window) {
            this->_renderer = SDL_CreateRenderer(window.getWindow(), -1, 0);
            if (this->_renderer == nullptr) {
                std::cout << "SDL_CreateRenderer Error: " << SDL_GetError()
                          << std::endl;
                exit(84);
            }
        }

        void Renderer::destroy() {
            SDL_DestroyRenderer(this->_renderer);
        }

        void Renderer::present() {
            SDL_RenderPresent(this->_renderer);
        }

        void Renderer::clear() {
            SDL_RenderClear(this->_renderer);
        }

        void Renderer::draw(Texture &texture, rect_t rect) {
            SDL_Rect sdlRect = {static_cast<int>(rect.pos.x), static_cast<int>(rect.pos.y), static_cast<int>(rect.width), static_cast<int>(rect.height)};
            SDL_RenderCopy(this->_renderer, texture.getTexture(), nullptr, &sdlRect);
        }

        void Renderer::drawRect(pos_t pos, size_t width, size_t height,
                                color_t color) {
            SDL_Rect sdlRect = {static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(width), static_cast<int>(height)};
            SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(this->_renderer, &sdlRect);
        }

        Event::Event() {
        }

        void Event::pollEvent() {
            SDL_PollEvent(&this->_event);
        }

        bool Event::isKeyPressed(SDL_Keycode key) {
            return this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == key;
        }

        bool Event::isKeyReleased(SDL_Keycode key) {
            return this->_event.type == SDL_KEYUP && this->_event.key.keysym.sym == key;
        }

        SDL_Event Event::getEvent() {
            return this->_event;
        }

        Event::~Event() = default;
    }
}