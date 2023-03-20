/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Text.cpp
*/

#include "Text.hpp"

namespace Arcade {
    namespace sfml {

        Text::Text(std::string &str, std::string &filename, sf::Color color, pos_t pos)
        {
            _font.loadFromFile(filename);
            _text.setString(str);
            _text.setFont(_font);
            _text.setFillColor(color);
            _text.setPosition(pos.x, pos.y);
        }

        Text::Text(std::string &str, std::string &filename, sf::Color color, pos_t pos,
            int size)
        {
            _font.loadFromFile(filename);
            _text.setString(str);
            _text.setFont(_font);
            _text.setFillColor(color);
            _text.setPosition(pos.x, pos.y);
            _text.setCharacterSize(size);
        }

        Text::Text(std::string &str, std::string &filename, sf::Color color, pos_t pos,
            sf::Uint32 style)
        {
            _font.loadFromFile(filename);
            _text.setString(str);
            _text.setFont(_font);
            _text.setFillColor(color);
            _text.setPosition(pos.x, pos.y);
            _text.setStyle(style);
        }

        Text::Text(std::string &str, std::string &filename, sf::Color color, pos_t pos,
            int size, sf::Uint32 style)
        {
            _font.loadFromFile(filename);
            _text.setString(str);
            _text.setFont(_font);
            _text.setFillColor(color);
            _text.setPosition(pos.x, pos.y);
            _text.setCharacterSize(size);
            _text.setStyle(style);
        }

        sf::Drawable *Text::getDrawable()
        {
            return &_text;
        }

        Text::~Text() = default;
    }
}