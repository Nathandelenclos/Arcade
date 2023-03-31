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

        Entity::Entity(pos_t pos, std::string &sprite, const std::string &id, color_t color, rect_t rect,
                       bool display)
        {
            _pos = pos;
            _sprite = sprite;
            _color = color;
            _rect = rect;
            _display = display;
            _id = id;
        }

        Entity::Entity(pos_t pos, const sprite_t& sprite, color_t color, bool display)
        {
            _pos = pos;
            _sprite = sprite.sprite;
            _color = color;
            _rect = sprite.rect;
            _display = display;
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

        float Entity::getSize()
        {
            return _size;
        }

        std::string &Entity::getId()
        {
            return _id;
        }

        void Entity::setId(std::string &id)
        {
            _id = id;
        }

        void Entity::setDisplay(bool display)
        {
            _display = display;
        }

        void Entity::setRect(rect_t rect)
        {
            _rect = rect;
        }

        void Entity::setSprite(std::string &sprite)
        {
            _sprite = sprite;
        }

        void Entity::setPos(pos_t pos)
        {
            _pos = pos;
        }

}