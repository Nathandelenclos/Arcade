/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Button.cpp
*/

#include "Button.hpp"

namespace Arcade {

    Button::Button(const std::string &libName, rect_t rect, pos_t pos, color_t color)
    {
        _libName = libName;
        _pos = pos;
        _display = true;
        _rect = rect;
        _sprite = "";
        _color = color;
        color_t colorText = {0, 0, 0, 255};
        _text = std::make_shared<Text>(pos, libName, colorText);
        _selected = false;
    }

    Button::Button(const std::string &libName, rect_t rect, pos_t pos, color_t color, bool selected)
    {
        _libName = libName;
        _pos = pos;
        _display = true;
        _rect = rect;
        _sprite = "";
        _color = color;
        color_t colorText = {0, 0, 0, 255};
        _text = std::make_shared<Text>(pos, libName, colorText);
        _selected = selected;
    }

    pos_t Button::getPos()
    {
        return _pos;
    }

    bool Button::isDisplayed()
    {
        return _display;
    }

    ObjectType Button::getType()
    {
        return ObjectType::ENTITY;
    }

    std::string &Button::getSprite()
    {
        return _sprite;
    }

    color_t Button::getColor()
    {
        if (_selected)
            return {0, 255, 255, 255};
        return _color;
    }

    rect_t Button::getRect()
    {
        return _rect;
    }

    TextPtr Button::getText()
    {
        return _text;
    }

    void Button::setSelected(bool selected)
    {
        _selected = selected;
    }

    std::string Button::getLibName()
    {
        return _libName;
    }

    bool Button::isSelected() const
    {
        return _selected;
    }

    enum ButtonGroup Button::getGroup()
    {
        return _group;
    }

    void Button::setGroup(enum ButtonGroup group)
    {
        _group = group;
    }

    size_t Button::getId() const
    {
        return _id;
    }

    void Button::setId(size_t id)
    {
        _id = id;
    }

}
