/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Renderer.cpp
*/

#include "SDL.hpp"

namespace Arcade {
    namespace sdl {

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
        void Renderer::create(const WindowPtr& window) {
            this->_renderer = SDL_CreateRenderer(window->getWindow(), -1, 0);
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
        void Renderer::draw(const TexturePtr& texture, rect_t rect) {
            SDL_Rect sdlRect = {static_cast<int>(rect.pos.x), static_cast<int>(rect.pos.y), static_cast<int>(rect.width), static_cast<int>(rect.height)};
            SDL_RenderCopy(this->_renderer, texture->getTexture(), nullptr, &sdlRect);
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
    }
}