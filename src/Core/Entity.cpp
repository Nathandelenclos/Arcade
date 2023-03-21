/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Entity.cpp
*/

#include "Entity.hpp"
#include "IObject.hpp"

namespace Arcade {

    Entity::Entity()
    {
        _pos = {20,20};
        _sprite = "";
        _color = {255, 255, 255, 255};
        _rect = {0, 0, 50, 50};
        _display = true;
    }

    Entity::Entity(pos_t pos, std::string &sprite, color_t color, rect_t rect)
    {
        _pos = pos;
        _sprite = sprite;
        _color = color;
        _rect = rect;
        _display = true;
    }

    Entity::Entity(pos_t pos, color_t color, rect_t rect)
    {
        _pos = pos;
        _sprite = "";
        _color = color;
        _rect = rect;
        _display = true;
    }

    Entity::Entity(pos_t pos, std::string &sprite, rect_t rect)
    {
        _pos = pos;
        _sprite = sprite;
        _color = {255, 255, 255, 255};
        _rect = rect;
        _display = true;
    }

    pos_t Entity::getPos()
    {
        return _pos;
    }

    bool Entity::isDisplayed()
    {
        return _display;
    }

    ObjectType Entity::getType()
    {
        return ObjectType::ENTITY;
    }

    std::string &Entity::getSprite()
    {
        return _sprite;
    }

    color_t Entity::getColor()
    {
        return _color;
    }

    rect_t Entity::getRect()
    {
        return _rect;
    }
}
