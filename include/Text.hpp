/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Text.cpp
*/

#pragma once

#include "IObject.hpp"

namespace Arcade {
    class Text : public IText {
        public:
            Text();
            Text(pos_t pos, std::string &text, std::string &font, int size, color_t color);
            Text(pos_t pos, std::string &text, std::string &font, int size);
            Text(pos_t pos, std::string &text, std::string &font);
            Text(pos_t pos, std::string &text);
            ~Text() override = default;
            pos_t getPos() override;
            bool isDisplayed() override;
            ObjectType getType() override;
            std::string & getText() override;
            std::string & getFont() override;
            int getSize() override;
            color_t getColor() override;

        protected:
            std::string _font;
            std::string _text;
            int _size;
            color_t _color;
            pos_t _pos;
            bool _display;
        private:
    };

    typedef std::shared_ptr<Text> TextPtr;
    typedef std::vector<TextPtr> TextVector;
    typedef std::shared_ptr<TextVector> TextVectorPtr;
}
