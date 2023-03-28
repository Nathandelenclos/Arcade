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

    typedef struct {
        std::string sprite;
        rect_t rect;
    } sprite_t;

    class Entity : public IEntities {
        public:
            Entity();
            Entity(pos_t pos, std::string &sprite, color_t color, rect_t rect);
            Entity(pos_t pos, color_t color, rect_t rect);
            Entity(pos_t pos, std::string &sprite, rect_t rect);
            Entity(pos_t pos, const sprite_t& sprite, color_t color, bool display);
            Entity(pos_t pos, std::string &sprite, const std::string &id, color_t color, rect_t rect, bool display);
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
            std::string &getId();
            void setId(std::string &id);
            float getSize() override;


        protected:
            bool _display;
            pos_t _pos;
            rect_t _rect;
            std::string _sprite;
            color_t _color;
            float _size;
            std::string _id;

        private:
    };

    typedef std::shared_ptr<Entity> EntityPtr;
    typedef std::vector<EntityPtr> EntityVector;
    typedef std::shared_ptr<EntityVector> EntityVectorPtr;
}
