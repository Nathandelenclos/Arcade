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

    typedef struct {
        int x;
        int y;
        int width;
        int height;
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
    };

    class IText : public IObject {
        public:
            virtual ~IText() = default;
            virtual pos_t getPos() = 0;
            virtual bool isDisplayed() = 0;
            virtual ObjectType getType() = 0;
            virtual std::string &getText() = 0;
            virtual std::string &getFont() = 0;
            virtual int getSize() = 0;
            virtual color_t getColor() = 0;
    };

    class IEntities : public IObject {
        public:
            virtual ~IEntities() = default;
            virtual pos_t getPos() = 0;
            virtual bool isDisplayed() = 0;
            virtual ObjectType getType() = 0;
            virtual std::string &getSprite() = 0;
            virtual rect_t getRect() = 0;

    };
}
