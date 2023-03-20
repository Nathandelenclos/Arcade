/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Sprites.cpp
*/

#include "Sprite.hpp"

namespace Arcade {
    namespace sfml {
        Sprite::Sprite(std::string &filename, sf::IntRect rect, pos_t pos)
        {
            _texture.loadFromFile(filename);
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(rect);
            _sprite.setPosition(pos.x, pos.y);
        }

        sf::Drawable *Sprite::getDrawable()
        {
            return &_sprite;
        }

        Sprite::~Sprite() = default;
    }
}
