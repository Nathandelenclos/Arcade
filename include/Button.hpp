/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Button.hpp
*/

#pragma once

#include "IObject.hpp"
#include "Text.hpp"

namespace Arcade {

    class Button;
    typedef std::shared_ptr<Button> ButtonPtr;
    typedef std::vector<ButtonPtr> ButtonVector;
    typedef std::shared_ptr<ButtonVector> ButtonVectorPtr;

    enum ButtonGroup {
        GAME,
        LIB
    };

    class Button : public IEntities {
        public:
            Button(const std::string &libName, rect_t rect, pos_t pos, color_t color);
            Button(const std::string &libName, rect_t rect, pos_t pos, color_t color, bool selected);
            ~Button() override = default;

            static ButtonPtr searchInList(ButtonVectorPtr list, enum ButtonGroup group, size_t id);
            pos_t getPos() override;
            bool isDisplayed() override;
            ObjectType getType() override;
            std::string &getSprite() override;
            color_t getColor() override;
            rect_t getRect() override;

            TextPtr getText();
            bool isSelected() const;
            void setSelected(bool selected);
            std::string getLibName();
            void setGroup(enum ButtonGroup group);
            enum ButtonGroup getGroup();
            size_t getId() const;
            void setId(size_t id);

        protected:
            pos_t _pos;
            bool _display;
            rect_t _rect;
            std::string _sprite;
            color_t _color;
        private:
            TextPtr _text;
            bool _selected;
            std::string _libName;
            enum ButtonGroup _group;
            size_t _id{};
    };

}
