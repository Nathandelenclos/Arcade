/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Texts.hpp
*/

#pragma once

#include "IObject.hpp"
#include "SFML/Graphics.hpp"
#include "Object.hpp"

namespace Arcade {
    namespace sfml {
        class Text : public sfml::IObject {
            public:
                Text(std::string &str, std::string &filename, sf::Color color, pos_t pos);
                Text(std::string &str, std::string &filename, sf::Color color, pos_t pos, int size);
                Text(std::string &str, std::string &filename, sf::Color color, pos_t pos, sf::Uint32 style);
                Text(std::string &str, std::string &filename, sf::Color color, pos_t pos, int size, sf::Uint32 style);
                ~Text() override;
                sf::Drawable *getDrawable() override;
            protected:
                sf::Text _text;
                sf::Font _font;
            private:
        };
        typedef std::shared_ptr<Text> TextPtr;
        typedef std::vector<TextPtr> TextVector;
        typedef std::shared_ptr<TextVector> TextVectorPtr;
    }
}