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
            this->_rect = {0, 0, 0, 0};
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
            texture->setRect({0, 0, 0, 0});
            return texture;
        }

        /**
         * @brief Load the Texture from file :: Load the texture from file
         * @param filename Texture filename
         * @param renderer Renderer
         * @return Texture Texture
         */
        TexturePtr Texture::loadFromFile(const RendererPtr &renderer, std::string &filename, pos_t pos) {
            TexturePtr texture = std::make_shared<Texture>();
            texture->_texture = IMG_LoadTexture(renderer->getRenderer(), filename.c_str());
            if (texture->_texture == nullptr) {
                std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << " on " << filename << std::endl;
                exit(84);
            }
            texture->setRect({pos.x * (static_cast<float>(renderer->getWindowParameter().width) / MAPWIDTH), pos.y * (static_cast<float>(renderer->getWindowParameter().height) / MAPHEIGHT), 0, 0});
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
            texture->setRect({0, 0, static_cast<size_t>((16 * 0.60) * text.size()), static_cast<size_t>(16 * 1.2)});
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
            texture->setRect({0, 0, static_cast<size_t>((size * 0.60) * text.size()), static_cast<size_t>(size * 1.2)});
            return texture;
        }

        /**
         * @brief Load the Texture from text :: Get the texture from the text object
         * @param text Text content
         * @param filename Font filename
         * @param color Text color
         * @param size Text size
         * @param renderer Renderer
         * @param pos Text position
         * @return SDL_Texture Texture
         */
        TexturePtr Texture::loadFromText(const RendererPtr &renderer,
            const std::string &text, const std::string &filename, color_t color,
            int size, pos_t pos)
        {
            SurfacePtr surface = Surface::loadFromFont(filename, text, size, color);
            TexturePtr texture = Texture::loadFromSurface(renderer, surface);
            texture->setRect({pos.x, pos.y, static_cast<size_t>((size * 0.60) * text.size()), static_cast<size_t>(size * 1.2)});
            texture->setColor(color);
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

        void Texture::setRect(rect_t rect)
        {
            _rect = rect;
        }

        rect_t Texture::getRect() const
        {
            return _rect;
        }

        void Texture::setColor(color_t color) {
            this->_color = color;
        }

        TexturePtr
        Texture::loadFromRectangle(const RendererPtr& renderer, size_t width, size_t height, color_t color, pos_t pos) {
            sdl::TexturePtr texture = std::make_shared<sdl::Texture>();
            texture->_texture = SDL_CreateTexture(renderer->getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
            SDL_Rect rect = {static_cast<int>(pos.x * (static_cast<float>(renderer->getWindowParameter().width) / MAPWIDTH)),
                             static_cast<int>(pos.y * (static_cast<float>(renderer->getWindowParameter().height) / MAPHEIGHT)),
                             static_cast<int>(width * (static_cast<float>(renderer->getWindowParameter().width) / MAPWIDTH)),
                             static_cast<int>(height * (static_cast<float>(renderer->getWindowParameter().height) / MAPHEIGHT))};
            texture->setRect({static_cast<float>(rect.x), static_cast<float>(rect.y), static_cast<size_t>(rect.w), static_cast<size_t>(rect.h)});
            texture->setColor(color);
            SDL_RenderFillRect(renderer->getRenderer(), &rect);
            return texture;
        }

    }
}