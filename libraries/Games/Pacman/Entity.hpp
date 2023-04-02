/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Entity.hpp
*/

#pragma once

#include "IObject.hpp"
#include "Entity.hpp"

namespace Arcade {

    typedef struct {
        std::string sprite;
        rect_t rect;
    } sprite_t;

    class Entity : public IEntities {
    public:
        Entity();
        Entity(pos_t pos, color_t color, rect_t rect);
        Entity(pos_t pos, const std::string &sprite, color_t color, rect_t rect);
        Entity(pos_t pos, const sprite_t &sprite, color_t color);
        ~Entity() override = default;

        pos_t getPos() override;
        void setPos(pos_t pos);
        bool isDisplayed() override;
        void setDisplay(bool display);
        ObjectType getType() override;
        std::string &getSprite() override;
        void setSprite(std::string &sprite);
        color_t getColor() override;
        rect_t getRect() override;
        void setRect(rect_t rect);
        float getSize() override;

    protected:
        bool _display;
        pos_t _pos;
        rect_t _rect;
        std::string _sprite;
        color_t _color;
        float _size;
    private:

    };

    typedef std::shared_ptr<Entity> EntityPtr;
    typedef std::vector<EntityPtr> EntityVector;
    typedef std::shared_ptr<EntityVector> EntityVectorPtr;

}