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

    enum class ObjectType {
        TEXT,
        ENTITY
    };

    class IObject {
        public:
            virtual ~IObject() = default;

            virtual pos_t getPos() = 0;
            virtual void setPos(pos_t pos) = 0;
            virtual bool isDisplayed() = 0;
            virtual void setDisplay(bool display) = 0;
            virtual ObjectType getType() = 0;
            virtual void setType(ObjectType type) = 0;
            virtual std::string getId() = 0;
    };
}
