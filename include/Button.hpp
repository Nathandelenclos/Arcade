/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Button.hpp
*/

#pragma once

#include "IObject.hpp"
#include "Types.hpp"
#include "Text.hpp"
#include "ISpriteType.hpp"

namespace Arcade {

    class Button;
    typedef std::shared_ptr<Button> ButtonPtr;
    typedef std::vector<ButtonPtr> ButtonVector;
    typedef std::shared_ptr<ButtonVector> ButtonVectorPtr;

    enum class ButtonGroup {
        GAME,
        LIB
    };

    class Button : public ISpriteType {
        public:
            Button(const std::string &libName, rect_t rect, pos_t pos, color_t color);
            Button(const std::string &libName, rect_t rect, pos_t pos, color_t color, bool selected);
            ~Button() override = default;

            static ButtonPtr searchInList(const ButtonVectorPtr& list, enum ButtonGroup group, size_t id);
            static ButtonPtr searchInList(const IEntitiesVectorPtr& list, enum ButtonGroup group, size_t id);
            static ButtonPtr searchInList(const IObjectVector& list, enum ButtonGroup group, size_t id);
            static bool isButton(const IObjectPtr& object);
            static bool isButton(const IEntitiesPtr& object);

            pos_t getPos() override;
            bool isDisplayed() override;
            ObjectType getType() override;
            std::string &getSprite() override;
            color_t getColor() override;
            rect_t getRect() override;
            SpriteType getSpriteType() override;

            TextPtr getText();
            bool isSelected() const;
            void setSelected(bool selected);
            void setGroup(enum ButtonGroup group);
            enum ButtonGroup getGroup();
            size_t getId() const;
            void setId(size_t id);
            void setSize(float size);
            float getSize() override;

        protected:
            pos_t _pos;
            bool _display;
            rect_t _rect;
            std::string _sprite;
            color_t _color;
        private:
            TextPtr _text;
            bool _selected;
            std::string _textContent;
            enum ButtonGroup _group;
            size_t _id{};
            float _size;
    };

}
