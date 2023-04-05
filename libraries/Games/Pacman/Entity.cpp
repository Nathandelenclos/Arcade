/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

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
     * @param pos {pos_t} - position of the entity
     * @param color {color_t} - color of the entity
     * @param rect {rect_t} - rect of the entity
     */
    Entity::Entity(pos_t pos, color_t color, rect_t rect)
    {
        _pos = pos;
        _color = color;
        _rect = rect;
        _display = true;
    }

    /**
    * @brief Construct a new Entity:: Entity object
    * @param pos {pos_t} - position of the entity
    * @param type {EntityType} - type of the entity
    * @param color {color_t} - color of the entity
    * @param rect {rect_t} - rect of the entity
    */
    Entity::Entity(pos_t pos, EntityType type, color_t color, rect_t rect)
    {
        _pos = pos;
        _color = color;
        _rect = rect;
        _type = type;
        _display = true;
    }

    /**
    * @brief Construct a new Entity:: Entity object
    * @param pos {pos_t} - position of the entity
    * @param sprite {std::string} - path to the sprite
    * @param color {color_t} - color of the entity
    * @param rect  {rect_t} - rect of the entity
    */
    Entity::Entity(pos_t pos, const std::string &sprite, color_t color, rect_t rect) {
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
    * @param sprite {std::string} - path to the sprite
    * @param color {color_t} - color of the entity
    * @param rect {rect_t} - rect of the entity
    */
    Entity::Entity(pos_t pos, const sprite_t &sprite, color_t color)
    {
        _pos = pos;
        _sprite = sprite.sprite;
        _color = color;
        _rect = sprite.rect;
        _display = true;
    }

    /**
     * @brief Get the Pos object
     * @return
     */
    pos_t Entity::getPos()
    {
        return _pos;
    }

    /**
     * @brief Get the Display object
     * @return
     */
    bool Entity::isDisplayed()
    {
        return _display;
    }

    /**
     * @brief Set the Display object
     * @param display
     */
    void Entity::setDisplay(bool display)
    {
        _display = display;
    }

    /**
     * @brief Get the Type object
     * @return
     */
    ObjectType Entity::getType()
    {
        return ObjectType::ENTITY;
    }

    /**
     * @brief Get the Sprite object
     * @return
     */
    std::string &Entity::getSprite()
    {
        return _sprite;
    }

    /**
     * @brief Get the Color object
     * @return
     */
    color_t Entity::getColor()
    {
        return _color;
    }

    /**
     * @brief Get the Rect object
     * @return
     */
    rect_t Entity::getRect()
    {
        return _rect;
    }

    /**
     * @brief Get the Size object
     * @return
     */
    float Entity::getSize()
    {
        return _size;
    }

    /**
     * @brief Set the Size object
     * @param size
     */
    void Entity::setRect(rect_t rect)
    {
        _rect = rect;
    }

    /**
     * @brief Set the Sprite object
     * @param color
     */
    void Entity::setSprite(std::string &sprite)
    {
        _sprite = sprite;
    }

    /**
     * @brief Set the Pas object
     * @param color
     */
    void Entity::setPos(pos_t pos)
    {
        _pos = pos;
    }

    /**
     * @brief Get the entityType object
     * @param color
     */
    EntityType Entity::getEntityType()
    {
        return _type;
    }

}