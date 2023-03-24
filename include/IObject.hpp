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
        float x;
        float y;
    } pos_t;

    typedef struct {
        float x;
        float y;
        float width;
        float height;
    } rect_t;

    typedef struct {
        int r;
        int g;
        int b;
        int a;
    } color_t;

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
            virtual float getSize() = 0;
    };

    class IText : public IObject {
        public:
            virtual std::string &getText() = 0;
            virtual std::string &getFont() = 0;
            virtual color_t getColor() = 0;
    };

    class IEntities : public IObject {
        public:
            virtual std::string &getSprite() = 0;
            virtual color_t getColor() = 0;
            virtual rect_t getRect() = 0;

    };
}
