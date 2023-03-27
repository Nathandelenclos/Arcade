/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Entity.cpp
*/

#include "Entity.hpp"
#include "IObject.hpp"

namespace Arcade {

    /**
     * @brief Construct a new Entity:: Entity object
     *
     */
    Entity::Entity()
    {
        _pos = {20,20};
        _sprite = "";
        _color = {255, 255, 255, 255};
        _rect = {0, 0, 50, 50};
        _display = true;
    }

    /**
     * @brief Construct a new Entity:: Entity object
     *
     * @param pos {pos_t} - position of the entity
     * @param sprite {std::string} - path to the sprite
     * @param color {color_t} - color of the entity
     * @param rect {rect_t} - rect of the entity
     */
    Entity::Entity(pos_t pos, std::string &sprite, color_t color, rect_t rect)
    {
        _pos = pos;
        _sprite = sprite;
        _color = color;
        _rect = rect;
        _display = true;
    }

    /**
     * @brief Construct a new Entity:: Entity object
     *
     * @param pos {pos_t} - position of the entity
     * @param color {color_t} - color of the entity
     * @param rect {rect_t} - rect of the entity
     */
    Entity::Entity(pos_t pos, color_t color, rect_t rect)
    {
        _pos = pos;
        _sprite = "";
        _color = color;
        _rect = rect;
        _display = true;
    }

    /**
     * @brief Construct a new Entity:: Entity object
     *
     * @param pos {pos_t} - position of the entity
     * @param sprite {std::string} - path to the sprite
     * @param rect {rect_t} - rect of the entity
     */
    Entity::Entity(pos_t pos, std::string &sprite, rect_t rect)
    {
        _pos = pos;
        _sprite = sprite;
        _color = {255, 255, 255, 255};
        _rect = rect;
        _display = true;
    }

    /**
     * @brief Construct a new Entity:: Entity object
     *
     * @param pos {pos_t} - position of the entity
     * @param sprite {std::string} - path to the sprite
     * @param color {color_t} - color of the entity
     */
    pos_t Entity::getPos()
    {
        return _pos;
    }

    /**
     * @brief Set the Pos object
     *
     * @param pos {pos_t} - position of the entity
     */
    bool Entity::isDisplayed()
    {
        return _display;
    }

    /**
     * @brief Set the Display object
     *
     * @param display {bool} - display the entity
     */
    ObjectType Entity::getType()
    {
        return ObjectType::ENTITY;
    }

    /**
     * @brief Get the Type object
     *
     * @return ObjectType - type of the object
     */
    std::string &Entity::getSprite()
    {
        return _sprite;
    }

    /**
     * @brief Get the Color object
     *
     * @return color_t - color of the entity
     */
    color_t Entity::getColor()
    {
        return _color;
    }

    /**
     * @brief Get the Rect object
     *
     * @return rect_t - rect of the entity
     */
    rect_t Entity::getRect()
    {
        return _rect;
    }

    float Entity::getSize()
    {
        return _size;
    }
}
