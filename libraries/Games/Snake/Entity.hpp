/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Entity.hpp
*/

#pragma once

#include "Entity.hpp"
#include "IObject.hpp"

namespace Arcade {

    class Entity : public IEntities {
        public:
            Entity();
            Entity(pos_t pos, std::string &sprite, color_t color, rect_t rect);
            Entity(pos_t pos, color_t color, rect_t rect);
            Entity(pos_t pos, std::string &sprite, rect_t rect);
            ~Entity() override = default;

            pos_t getPos() override;
            bool isDisplayed() override;
            ObjectType getType() override;
            std::string &getSprite() override;
            color_t getColor() override;
            rect_t getRect() override;

        protected:
            bool _display;
            pos_t _pos;
            rect_t _rect;
            std::string _sprite;
            color_t _color;
        private:
    };

}
