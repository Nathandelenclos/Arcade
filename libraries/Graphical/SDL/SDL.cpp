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

        /**
         * @brief Create the Window object :: Window object
         */
        Window::Window(std::string &title, int width, int height,
                       bool fullscreen) {
            this->_title = title;
            this->_width = width;
            this->_height = height;
            this->_fullscreen = fullscreen;
            this->_isOpened = false;
        }

        /**
         * @brief Create the Window with custom title, width, height and fullscreen
         * @param title Window title
         * @param width Window width
         * @param height Window height
         * @param fullscreen Window fullscreen or not
         */
        void Window::create(std::string &title, int width, int height,
                            bool fullscreen) {
            this->_window = SDL_CreateWindow(title.c_str(),
                                               SDL_WINDOWPOS_CENTERED,
                                               SDL_WINDOWPOS_CENTERED, width,
                                               height, fullscreen
                                                       ? SDL_WINDOW_FULLSCREEN
                                                       : SDL_WINDOW_SHOWN);
            this->_isOpened = true;
            if (this->_window == nullptr) {
                std::cout << "SDL_CreateWindow Error: " << SDL_GetError()
                          << std::endl;
                exit(84);
            }
        }

        /**
         * @brief Create the Window with default title, width, height and fullscreen
         */
        void Window::create() {
            this->_window = SDL_CreateWindow(this->_title.c_str(),
                                             SDL_WINDOWPOS_CENTERED,
                                             SDL_WINDOWPOS_CENTERED, this->_width,
                                             this->_height, this->_fullscreen
                                                     ? SDL_WINDOW_FULLSCREEN
                                                     : SDL_WINDOW_SHOWN);
            this->_isOpened = true;
            if (this->_window == nullptr) {
                std::cout << "SDL_CreateWindow Error: " << SDL_GetError()
                          << std::endl;
                exit(84);
            }
        }

        /**
         * @brief Set the Title object :: Set the title of the window
         * @param title Window title
         */
        void Window::setTitle(std::string &title) {
            SDL_SetWindowTitle(this->_window, title.c_str());
        }

        /**
         * @brief Set the FullScreen object :: Set the fullscreen of the window
         * @param fullscreen Window fullscreen or not
         */
        void Window::setFullScreen(bool fullscreen) {
            fullscreen ? SDL_SetWindowFullscreen(this->_window, SDL_WINDOW_FULLSCREEN) : SDL_SetWindowFullscreen(this->_window, 0);
        }

        /**
         * @brief Set the Icon object :: Set the icon of the window
         * @param filename Icon filename
         */
        void Window::setIcon(std::string &filename) {
            this->_icon = IMG_Load(filename.c_str());
            SDL_SetWindowIcon(this->_window, this->_icon);
        }

        /**
         * @brief Destroy the Window object :: Destroy the window
         */
        void Window::destroy() {
            SDL_FreeSurface(this->_icon);
            SDL_DestroyWindow(this->_window);
            this->_isOpened = false;
        }

        /**
         * @brief Get the Window object :: Get the window
         * @return SDL_Window* Window
         */
        SDL_Window *Window::getWindow() const {
            return this->_window;
        }

        bool Window::isOpened() const {
            return this->_isOpened
        }

        void Window::setOpened(bool isOpened) {
            this->_isOpened = isOpened;
        }

        /**
         * @brief Destroy the Window object :: Destroy the window
         */
        Window::~Window() = default;

        /**
         * @brief Create the Surface object :: Surface object
         */
        Surface::Surface() {
        }

        /**
         * @brief Destroy the Surface object :: Destroy the surface
         */
        Surface::~Surface() = default;

        /**
         * @brief Destroy the Surface object :: Destroy the surface
         */
        void Surface::destroy() {
            SDL_FreeSurface(this->_surface);
        }

        /**
         * @brief Load the Surface from file :: Load the surface from file
         * @param filename Surface filename
         * @return Surface Surface
         */
        Surface Surface::loadFromFile(std::string &filename) {
            Surface surface;
            surface._surface = IMG_Load(filename.c_str());
            if (surface._surface == nullptr) {
                std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl;
                exit(84);
            }
            return surface;
        }

        /**
         * @brief Get Surface :: Get the surface from the surface object
         * @return SDL_Surface *Surface
         */
        SDL_Surface *Surface::getSurface() const {
            return this->_surface;
        }

        /**
         * @brief Create the Texture object :: Texture object
         */
        Texture::Texture() {
        }

        /**
         * @brief Destroy the Texture object :: Destroy the texture
         */
        Texture::~Texture() = default;

        /**
         * @brief Destroy the Texture object :: Destroy the texture
         */
        void Texture::destroy() {
            SDL_DestroyTexture(this->_texture);
        }

        /**
         * @brief Load the Texture from surface :: Load the texture from surface
         * @param surface Surface
         * @param renderer Renderer
         * @return Texture Texture
         */
        Texture Texture::loadFromSurface(Surface *surface, SDL_Renderer *renderer) {
            Texture texture;
            texture._texture = SDL_CreateTextureFromSurface(renderer, surface->getSurface());
            if (texture._texture == nullptr) {
                std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            return texture;
        }

        /**
         * @brief Load the Texture from file :: Load the texture from file
         * @param filename Texture filename
         * @param renderer Renderer
         * @return Texture Texture
         */
        Texture Texture::loadFromFile(std::string &filename, SDL_Renderer *renderer) {
            Texture texture;
            texture._texture = IMG_LoadTexture(renderer, filename.c_str());
            if (texture._texture == nullptr) {
                std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
                exit(84);
            }
            return texture;
        }

        /**
         * @brief Load the Texture from text :: Get the texture from the text object
         * @param text Text content
         * @param filename Font filename
         * @param color Text color
         * @param renderer Renderer
         * @return SDL_Texture Texture
         */
        Texture Texture::loadFromText(std::string &text, std::string &filename,
                                      color_t color, SDL_Renderer *renderer) {
            Texture texture;
            TTF_Font *font = TTF_OpenFont(filename.c_str(), 24);
            SDL_Color sdlColor = {color.r, color.g, color.b, color.a};
            SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);
            texture._texture = SDL_CreateTextureFromSurface(renderer, surface);
            return texture;
        }

        /**
         * @brief Load the Texture from text :: Get the texture from the text object
         * @param text Text content
         * @param filename Font filename
         * @param color Text color
         * @param size Text size
         * @param renderer Renderer
         * @return SDL_Texture Texture
         */
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

        /**
         * @brief Load the Texture from text :: Get the texture from the text object
         * @param text Text content
         * @param filename Font filename
         * @param color Text color
         * @param size Text size
         * @param style Text style
         * @param renderer Renderer
         * @return SDL_Texture Texture
         */
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

        /**
         * @brief Get Texture :: Get the texture from the texture object
         * @return SDL_Texture *Texture
         */
        SDL_Texture *Texture::getTexture() const {
            return this->_texture;
        }

        /**
         * @brief Create the Renderer object :: Renderer object
         */
        Renderer::Renderer() {
        }

        /**
         * @brief Destroy the Renderer object :: Destroy the renderer
         */
        Renderer::~Renderer() {
        }

        /**
         * @brief Create the Renderer object :: Create the renderer
         * @param window Window
         */
        void Renderer::create(Window &window) {
            this->_renderer = SDL_CreateRenderer(window.getWindow(), -1, 0);
            if (this->_renderer == nullptr) {
                std::cout << "SDL_CreateRenderer Error: " << SDL_GetError()
                          << std::endl;
                exit(84);
            }
        }

        /**
         * @brief Destroy the Renderer object :: Destroy the renderer
         */
        void Renderer::destroy() {
            SDL_DestroyRenderer(this->_renderer);
        }

        /**
         * @brief Print the texture on the renderer :: Print the texture on the renderer
         */
        void Renderer::present() {
            SDL_RenderPresent(this->_renderer);
        }

        /**
         * @brief Clear the renderer :: Clear the renderer
         */
        void Renderer::clear() {
            SDL_RenderClear(this->_renderer);
        }

        /**
         * @brief Draw the texture on the renderer :: Draw the texture on the renderer
         * @param texture Texture
         * @param rect Rectangle
         */
        void Renderer::draw(Texture &texture, rect_t rect) {
            SDL_Rect sdlRect = {static_cast<int>(rect.pos.x), static_cast<int>(rect.pos.y), static_cast<int>(rect.width), static_cast<int>(rect.height)};
            SDL_RenderCopy(this->_renderer, texture.getTexture(), nullptr, &sdlRect);
        }

        /**
         * @brief Draw the texture on the renderer :: Draw the texture on the renderer
         * @param pos Position on the renderer
         * @param width Width
         * @param height Height
         * @param color Color
         */
        void Renderer::drawRect(pos_t pos, size_t width, size_t height,
                                color_t color) {
            SDL_Rect sdlRect = {static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(width), static_cast<int>(height)};
            SDL_SetRenderDrawColor(this->_renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(this->_renderer, &sdlRect);
        }

        SDL_Renderer *Renderer::getRenderer() const {
            return this->_renderer;
        }

        /**
         * @brief Create the Event object :: Event object
         */
        Event::Event() {
        }

        /**
         * @brief Set the poll event :: Set the poll eventl
         */
        void Event::pollEvent() {
            SDL_PollEvent(&this->_event);
        }

        /**
         * @brief Check if a key is pressed :: Check if a key is pressed
         * @param key Key
         * @return true Key is pressed
         * @return false Key is not pressed
         */
        bool Event::isKeyPressed(SDL_Keycode key) {
            return this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == key;
        }

        /**
         * @brief Check if a key is released :: Check if a key is released
         * @param key Key
         * @return true Key is released
         * @return false Key is not released
         */
        bool Event::isKeyReleased(SDL_Keycode key) {
            return this->_event.type == SDL_KEYUP && this->_event.key.keysym.sym == key;
        }

        /**
         * @brief get the current event :: Get the current event
         * @return
         */
        SDL_Event Event::getEvent() {
            return this->_event;
        }

        /**
         * @brief Destroy the Event object :: Destroy the event
         */
        Event::~Event() = default;
    }
}