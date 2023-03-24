/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Texture.cpp
*/

#include "SDL.hpp"

namespace Arcade {
    namespace sdl {

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
        TexturePtr Texture::loadFromSurface(const RendererPtr& renderer, const SurfacePtr& surface) {
            TexturePtr texture = std::make_shared<Texture>();
            texture->_texture = SDL_CreateTextureFromSurface(renderer->getRenderer(), surface->getSurface());
            if (texture->_texture == nullptr) {
                std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            texture->setPos({0, 0});
            return texture;
        }

        /**
         * @brief Load the Texture from file :: Load the texture from file
         * @param filename Texture filename
         * @param renderer Renderer
         * @return Texture Texture
         */
        TexturePtr Texture::loadFromFile(const RendererPtr &renderer, std::string &filename) {
            TexturePtr texture = std::make_shared<Texture>();
            texture->_texture = IMG_LoadTexture(renderer->getRenderer(), filename.c_str());
            if (texture->_texture == nullptr) {
                std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << " on " << filename << std::endl;
                exit(84);
            }
            texture->setPos({0, 0});
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
        TexturePtr Texture::loadFromText(const RendererPtr& renderer, const std::string &text, const std::string &filename, color_t color) {
            SurfacePtr surface = Surface::loadFromFont(filename, text, color);
            TexturePtr texture = Texture::loadFromSurface(renderer, surface);
            texture->setPos({0, 0});
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
        TexturePtr Texture::loadFromText(const RendererPtr& renderer, const std::string &text, const std::string &filename, color_t color, int size) {
            SurfacePtr surface = Surface::loadFromFont(filename, text, size, color);
            TexturePtr texture = Texture::loadFromSurface(renderer, surface);
            return texture;
        }

        TexturePtr Texture::loadFromText(const RendererPtr &renderer,
            const std::string &text, const std::string &filename, color_t color,
            int size, pos_t pos)
        {
            SurfacePtr surface = Surface::loadFromFont(filename, text, size, color);
            TexturePtr texture = Texture::loadFromSurface(renderer, surface);
            texture->setPos(pos);
            return texture;
        }

        /**
         * @brief Get Texture :: Get the texture from the texture object
         * @return SDL_Texture *Texture
         */
        SDL_Texture *Texture::getTexture() const {
            return _texture;
        }

        color_t Texture::getColor() const
        {
            return _color;
        }
    }
}