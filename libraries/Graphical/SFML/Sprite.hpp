/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Sprites.hpp
*/

#pragma once

#include "IObject.hpp"
#include "SFML/Graphics.hpp"
#include "Object.hpp"

namespace Arcade {
    namespace sfml {
        class Sprite : public sfml::IObject {
            public:
                Sprite(std::string &filename, sf::IntRect rect, pos_t pos);
                Sprite(color_t color, sf::IntRect rect, pos_t pos);
                ~Sprite() override;
                sf::Drawable *getDrawable() override;
        protected:
            sf::Sprite _sprite;
            sf::RectangleShape _rectangle;
            sf::Texture _texture;
            private:
        };
        typedef std::shared_ptr<Sprite> SpritePtr;
        typedef std::vector<SpritePtr> SpriteVector;
        typedef std::shared_ptr<SpriteVector> SpriteVectorPtr;
    }
}