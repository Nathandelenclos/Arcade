/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Button.cpp
*/

#include "Button.hpp"

namespace Arcade {

    /**
     * @brief Construct a new Button:: Button object
     *
     * @param libName {const std::string &libName} - The name of the lib
     * @param rect {rect_t} - The rect of the button
     * @param pos {pos_t} - The position of the button
     * @param color {color_t} - The color of the button
     */
    Button::Button(const std::string &libName, rect_t rect, pos_t pos, color_t color)
    {
        _pos = pos;
        _display = true;
        _rect = rect;
        _sprite = "";
        _color = color;
        color_t colorText = {255, 255, 255, 255};
        _text = std::make_shared<Text>(pos, libName, colorText);
        _selected = false;
    }

    /**
     * @brief Construct a new Button:: Button object
     *
     * @param libName {const std::string &libName} - The name of the lib
     * @param rect {rect_t} - The rect of the button
     * @param pos {pos_t} - The position of the button
     * @param color {color_t} - The color of the button
     * @param selected {bool} - If the button is selected
     */
    Button::Button(const std::string &libName, rect_t rect, pos_t pos, color_t color, bool selected)
    {
        _pos = pos;
        _display = true;
        _rect = rect;
        _sprite = "";
        _color = color;
        color_t colorText = {255, 255, 255, 255};
        _text = std::make_shared<Text>(pos, libName, colorText);
        _selected = selected;
    }

    /**
     * @brief Get if the button is displayed
     *
     * @return bool - If the button is displayed
     */
    bool Button::isDisplayed()
    {
        return _display;
    }

    /**
     * @brief Get the Type object
     *
     * @return enum ObjectType - The type of the object
     */
    ObjectType Button::getType()
    {
        return ObjectType::ENTITY;
    }

    /**
     * @brief Get the Lib Name object
     *
     * @return std::string - The name of the lib
     */
    std::string &Button::getSprite()
    {
        return _sprite;
    }

    /**
     * @brief Get the Color object
     *
     * @return color_t - The color of the button
     */
    color_t Button::getColor()
    {
        if (_selected)
            return {0, 255, 255, 255};
        return _color;
    }

    /**
     * @brief Get the Rect object
     *
     * @return rect_t - The rect of the button
     */
    rect_t Button::getRect()
    {
        return _rect;
    }

    /**
     * @brief Get the Text object
     *
     * @return TextPtr - The text of the button
     */
    TextPtr Button::getText()
    {
        return _text;
    }

    /**
     * @brief Set the Selected object
     *
     * @param selected {bool} - If the button is selected
     */
    void Button::setSelected(bool selected)
    {
        _selected = selected;
    }

    /**
     * @brief Get the Selected object
     *
     * @return true - If the button is selected
     * @return false - If the button is not selected
     */
    bool Button::isSelected() const
    {
        return _selected;
    }

    /**
     * @brief Get the Group object
     *
     * @return enum ButtonGroup - The group of the button
     */
    enum ButtonGroup Button::getGroup()
    {
        return _group;
    }

    /**
     * @brief Set the Group object
     *
     * @param group {enum ButtonGroup} - The group of the button
     */
    void Button::setGroup(enum ButtonGroup group)
    {
        _group = group;
    }

    /**
     * @brief Get the Id object
     *
     * @return size_t - The id of the button
     */
    size_t Button::getId() const
    {
        return _id;
    }

    /**
     * @brief Set the Id object
     *
     * @param id {size_t} - The id of the button
     */
    void Button::setId(size_t id)
    {
        _id = id;
    }

    /**
     * @brief Get the Pos object
     *
     * @return pos_t - The position of the button
     */
    pos_t Button::getPos()
    {
        return _pos;
    }

    /**
     * Search a button in a list
     * @param list {const ButtonVectorPtr&} - The list of buttons
     * @param group {enum ButtonGroup} - The group of the button
     * @param id {size_t} - The id of the button
     * @return ButtonPtr - The button found
     */
    ButtonPtr Button::searchInList(const ButtonVectorPtr& list, enum ButtonGroup group,
        size_t id)
    {
        for (auto &button : *list) {
            if (button->getGroup() == group && button->getId() == id)
                return button;
        }
        return nullptr;
    }

    /**
     * Search a button in a list
     * @param list {const IEntitiesVectorPtr&} - The list of buttons
     * @param group {enum ButtonGroup} - The group of the button
     * @param id {size_t} - The id of the button
     * @return ButtonPtr - The button found
     */
    ButtonPtr Button::searchInList(const IEntitiesVectorPtr& list, enum ButtonGroup group,
        size_t id)
    {
        for (auto &element : *list) {
            if (!Button::isButton(element))
                continue;
            ButtonPtr button = std::dynamic_pointer_cast<Button>(element);
            if (button->getGroup() == group && button->getId() == id)
                return button;
        }
        return nullptr;
    }

    /**
     * Search a button in a list
     * @param list {const IObjectVector&} - The list of buttons
     * @param group {enum ButtonGroup} - The group of the button
     * @param id {size_t} - The id of the button
     * @return ButtonPtr - The button found
     */
    ButtonPtr Button::searchInList(const IObjectVector& list, enum ButtonGroup group, size_t id)
    {
        for (auto &element : *list) {
            if (!Button::isButton(element))
                continue;
            ButtonPtr button = std::dynamic_pointer_cast<Button>(element);
            if (button->getGroup() == group && button->getId() == id)
                return button;
        }
        return nullptr;
    }

    /**
     * @brief Get the Sprite Type object
     *
     * @return enum SpriteType - The type of the sprite
     */
    SpriteType Button::getSpriteType()
    {
        return BUTTON;
    }

    /**
     * @brief Get the Button object
     *
     * @param object {const IObjectPtr&} - The object to check
     * @return true - If the object is a button
     * @return false - If the object is not a button
     */
    bool Button::isButton(const IObjectPtr &object)
    {
        if (object->getType() != ObjectType::ENTITY) {
            return false;
        }
        ISpriteTypePtr sprite = std::dynamic_pointer_cast<ISpriteType>(object);
        if (sprite->getSpriteType() != BUTTON) {
            return false;
        }
        return true;
    }

    /**
     * @brief Get the Button object
     *
     * @param object {const IEntitiesPtr&} - The object to check
     * @return true - If the object is a button
     * @return false - If the object is not a button
     */
    bool Button::isButton(const IEntitiesPtr &object)
    {
        ISpriteTypePtr sprite = std::dynamic_pointer_cast<ISpriteType>(object);
        if (sprite->getSpriteType() != BUTTON) {
            return false;
        }
        return true;
    }

    float Button::getSize()
    {
        return _size;
    }

    void Button::setSize(float size)
    {
        _size = size;
    }
}
