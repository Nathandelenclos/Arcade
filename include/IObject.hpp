/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IObject
*/

#include <iostream>
#include <memory>
#include <vector>
#include "EKey.hpp"

#pragma once

namespace Arcade {
    typedef struct {
        size_t x;
        size_t y;
    } pos_t;

    enum class ObjectType {
        TEXT,
        ENTITY
    };

    class IObject {
        public:
            virtual ~IObject() = default;
            virtual pos_t getPos() = 0;
            virtual bool isDisplayed() = 0;
            virtual ObjectType getType() = 0;
    };

    class IText : public IObject {
        public:
            virtual ~IText() = default;
            virtual pos_t getPos() = 0;
            virtual bool isDisplayed() = 0;
            virtual ObjectType getType() = 0;
            virtual void setText(std::string text) = 0;
            virtual void setFont(std::string font) = 0;
            virtual void setPos(pos_t pos) = 0;
            virtual void setDisplayed(bool displayed) = 0;
    };

    class ISprite : public IObject {
        public:
            virtual ~ISprite() = default;
            virtual pos_t getPos() = 0;
            virtual bool isDisplayed() = 0;
            virtual ObjectType getType() = 0;
            virtual void setPos(pos_t pos) = 0;
            virtual void setDisplayed(bool displayed) = 0;
            virtual void setSprite(std::string sprite) = 0;
    };
}
