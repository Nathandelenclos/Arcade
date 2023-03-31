/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Surface.cpp
*/

#include "SDL.hpp"

namespace Arcade {
    namespace sdl {

        /**
         * @brief Create the Surface object :: Surface object
         */
        Surface::Surface() {
        }

        /**
         * @brief Destroy the Surface object :: Destroy the surface
         */
        Surface::~Surface() {
            if (_font != nullptr) {
                TTF_CloseFont(_font);
            }
            if (_surface)
                SDL_FreeSurface(_surface);
        };

        /**
         * @brief Destroy the Surface object :: Destroy the surface
         */
        void Surface::destroy() {
            if (_surface)
                SDL_FreeSurface(this->_surface);
            if (_font) {
                TTF_CloseFont(_font);
            }
        }

        /**
         * @brief Load the Surface from file :: Load the surface from file
         * @param filename Surface filename
         * @return Surface Surface
         */
        SurfacePtr Surface::loadFromFile(std::string &filename) {
            SurfacePtr surface = std::make_shared<Surface>();
            surface->_surface = IMG_Load(filename.c_str());
            if (surface->_surface == nullptr) {
                std::cout << "IMG_Load Error: " << IMG_GetError() << " on " << filename << std::endl;
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
         * @brief Load the Surface from font :: Load the surface from font
         * @param filename Font filename
         * @param str String
         * @param size Font size
         * @param color Font color
         * @return SurfacePtr Surface
         */
        SurfacePtr Surface::loadFromFont(const std::string &filename, const std::string &str, int size, color_t color) {
            SurfacePtr surface = std::make_shared<Surface>();
            surface->_font = TTF_OpenFont(filename.c_str(), size);
            if (surface->_font == nullptr) {
                std::cout << TTF_GetError() << std::endl;
                exit(84);
            }
            surface->_surface = TTF_RenderText_Solid(surface->_font, str.c_str(), {
                static_cast<Uint8>(color.r), static_cast<Uint8>(color.g),
                static_cast<Uint8>(color.b), static_cast<Uint8>(color.a)
            });
            return surface;
        }

        /**
         * @brief Load the Surface from font :: Load the surface from font
         * @param filename Font filename
         * @param str String
         * @param size Font size
         * @return SurfacePtr Surface
         */
        SurfacePtr Surface::loadFromFont(const std::string &filename, const std::string &str, int size) {
            return Surface::loadFromFont(filename, str, size, {255, 255, 255, 255});
        }

        /**
         * @brief Load the Surface from font :: Load the surface from font
         * @param filename Font filename
         * @param str String
         * @return SurfacePtr Surface
         */
        SurfacePtr Surface::loadFromFont(const std::string &filename,
            const std::string &str)
        {
            return Surface::loadFromFont(filename, str, 16, {255, 255, 255, 255});
        }

        /**
         * @brief Load the Surface from font :: Load the surface from font
         * @param filename Font filename
         * @param str String
         * @param color Font color
         * @return SurfacePtr Surface
         */
        SurfacePtr Surface::loadFromFont(const std::string &filename,
            const std::string &str, color_t color)
        {
            return Surface::loadFromFont(filename, str, 16, color);
        }
    }
}