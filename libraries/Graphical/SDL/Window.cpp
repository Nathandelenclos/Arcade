/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Window.cpp
*/

#include "SDL.hpp"

namespace Arcade {
    namespace sdl {

        /**
         * @brief Init the Window object :: Window object
         */
        Window::Window() {
            SDL_Init(SDL_INIT_VIDEO);
            SDL_Init(SDL_INIT_EVENTS);
            SDL_Init(SDL_INIT_AUDIO);
            SDL_Init(SDL_INIT_TIMER);
            TTF_Init();
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
            this->_windowParameter = {static_cast<unsigned int>(width), static_cast<unsigned int>(height), fullscreen};
            SDL_Init(SDL_INIT_VIDEO);
            SDL_Init(SDL_INIT_EVENTS);
            SDL_Init(SDL_INIT_AUDIO);
            SDL_Init(SDL_INIT_TIMER);
            TTF_Init();
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
            this->_windowParameter = {static_cast<unsigned int>(width),
                                      static_cast<unsigned int>(height), fullscreen};
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

        /**
         * @brief Get the Is Opened object :: Get the window is opened or not
         * @return true Window is opened
         * @return false Window is closed
         */
        bool Window::isOpened() const {
            return this->_isOpened;
        }

        /**
         * @brief Set the Is Opened object :: Set the window is opened or not
         * @param isOpened Window is opened or not
         */
        void Window::setOpened(bool isOpened) {
            this->_isOpened = isOpened;
        }

        /**
         * @brief Destroy the Window object :: Destroy the window
         */
        Window::~Window() {
            TTF_Quit();
            SDL_DestroyWindow(_window);
        }

        /**
         * @brief Get the Window Parameter object :: Get the window parameter
         * @return windowParameter_t Window parameter
         */
        windowsParameter_t Window::getWindowParameter() const {
            return this->_windowParameter;
        };
    }
}