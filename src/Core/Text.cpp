/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Text.cpp
*/

#include "IObject.hpp"
#include "Text.hpp"

namespace Arcade {

    Text::Text(pos_t pos, const std::string &text, std::string &font, int size,
        color_t color)
    {
        _font = font;
        _text = text;
        _size = size;
        _color = color;
        _pos = pos;
        _display = true;
    }

    Text::Text(pos_t pos, const std::string &text, std::string &font, int size)
    {
        _font = font;
        _text = text;
        _size = size;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }

    Text::Text(pos_t pos, const std::string &text, std::string &font)
    {
        _font = font;
        _text = text;
        _size = 16;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }

    Text::Text(pos_t pos, const std::string &text)
    {
        _font = "../assets/fonts/GamePlayed.ttf";
        _text = text;
        _size = 16;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }

    Text::Text(pos_t pos, const std::string &text, int size)
    {
        _font = "../assets/fonts/GamePlayed.ttf";
        _text = text;
        _size = size;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }


    Text::Text()
    {
        _font = "../assets/fonts/GamePlayed.ttf";
        _text = "caca";
        _size = 16;
        _color = { 0, 255, 255, 200};
        _pos = {140,  100};
        _display = true;
    }

    pos_t Text::getPos()
    {
        return _pos;
    }

    bool Text::isDisplayed()
    {
        return _display;
    }

    ObjectType Text::getType()
    {
        return ObjectType::TEXT;
    }

    std::string &Text::getText()
    {
        return _text;
    }

    std::string &Text::getFont()
    {
        return _font;
    }

    int Text::getSize()
    {
        return _size;
    }

    color_t Text::getColor()
    {
        return _color;
    }

    void Text::setPos(pos_t pos)
    {
        _pos = pos;
    }

    void Text::setDisplay(bool display)
    {
        _display = display;
    }

    void Text::setText(const std::string &text)
    {
        _text = text;
    }

    void Text::setFont(const std::string &font)
    {
        _font = font;
    }

    void Text::setSize(int size)
    {
        _size = size;
    }

    void Text::setColor(color_t color)
    {
        _color = color;
    }
}