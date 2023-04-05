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
    /**
     * @brief The position of an object
     */
    typedef struct {
        float x;
        float y;
    } pos_t;

    /**
     * @brief The size of a rect of an object along with its position
     */
    typedef struct {
        float x;
        float y;
        float width;
        float height;
    } rect_t;

    /**
     * @brief The color of an object
     */
    typedef struct {
        int r;
        int g;
        int b;
        int a;
    } color_t;

    /**
     * @brief The type of an object
     */
    enum class ObjectType {
        TEXT,
        ENTITY
    };

    class IObject {
    public:
        /**
         * @brief Destroy the IObject object
         */
        virtual ~IObject() = default;
        /**
         * @brief Get the Pos object
         * @return The position of the object
         */
        virtual pos_t getPos() = 0;
        /**
         * @brief Get if the object is displayed
         * @return True if the object is displayed, false otherwise
         */
        virtual bool isDisplayed() = 0;
        /**
         * @brief Get the Type object
         * @return The type of the object
         */
        virtual ObjectType getType() = 0;
        /**
         * @brief Get the Color object
         * @return The color of the object
         */
        virtual color_t getColor() = 0;
        /**
         * @brief Get the Size object
         * @return The size of the object
         */
        virtual float getSize() = 0;
    };

    class IText : public IObject {
    public:
        /**
         * @brief Destroy the IText object
         */
        virtual ~IText() = default;
        /**
         * @brief Get the Text object
         * @return The content of the text object
         */
        virtual std::string &getText() = 0;
        /**
         * @brief Get the Font object
         * @return The font of the text object
         */
        virtual std::string &getFont() = 0;
        /**
         * @brief Get if the text is centered
         * @return True if the text is centered, false otherwise
         */
        virtual bool positionCentered() = 0;
    };

    class IEntities : public IObject {
    public:
        /**
         * @brief Destroy the IEntities object
         */
        virtual ~IEntities() = default;
        /**
         * @brief Get the Sprite object
         * @return The sprite file path of the entity
         */
        virtual std::string &getSprite() = 0;
        /**
         * @brief Get the Rect object
         * @return The rect of the entity
         */
        virtual rect_t getRect() = 0;
    };
}