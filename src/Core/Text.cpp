/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Text.cpp
*/

#include "IObject.hpp"
#include "Text.hpp"

namespace Arcade {

    /**
     * @brief Construct a new Text:: Text object
     *
     */
    Text::Text(pos_t pos, const std::string &text, std::string &font, int size,
        color_t color)
    {
        _font = font;
        _text = text;
        _size = size;
        _color = color;
        _pos = pos;
        _display = true;
    }

    /**
     * @brief Construct a new Text:: Text object
     *
     * @param pos {pos_t} - position of the text
     * @param text {std::string} - text to display
     * @param font {std::string} - path to the font
     * @param size {int} - size of the text
     */
    Text::Text(pos_t pos, const std::string &text, std::string &font, int size)
    {
        _font = font;
        _text = text;
        _size = size;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }

    /**
     * @brief Construct a new Text:: Text object
     *
     * @param pos {pos_t} - position of the text
     * @param text {std::string} - text to display
     * @param font {std::string} - path to the font
     */
    Text::Text(pos_t pos, const std::string &text, std::string &font)
    {
        _font = font;
        _text = text;
        _size = 16;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }

    /**
     * @brief Construct a new Text:: Text object
     *
     * @param pos {pos_t} - position of the text
     * @param text {std::string} - text to display
     * @param size {int} - size of the text
     */
    Text::Text(pos_t pos, const std::string &text)
    {
        _font = "./assets/fonts/GamePlayed.ttf";
        _text = text;
        _size = 16;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }

    /**
     * @brief Construct a new Text:: Text object
     *
     * @param pos {pos_t} - position of the text
     * @param text {std::string} - text to display
     * @param color {color_t} - color of the text
     */
    Text::Text(pos_t pos, const std::string &text, color_t color)
    {
        _font = "./assets/fonts/GamePlayed.ttf";
        _text = text;
        _size = 16;
        _color = color;
        _pos = pos;
        _display = true;
    }

    /**
     * @brief Construct a new Text:: Text object
     *
     * @param pos {pos_t} - position of the text
     * @param text {std::string} - text to display
     * @param size {int} - size of the text
     * @param color {color_t} - color of the text
     */
    Text::Text(pos_t pos, const std::string &text, int size)
    {
        _font = "./assets/fonts/GamePlayed.ttf";
        _text = text;
        _size = size;
        _color = { 255, 255, 255, 255};
        _pos = pos;
        _display = true;
    }

    /**
     * @brief Construct a new Text:: Text object
     *
     * @param pos {pos_t} - position of the text
     * @param text {std::string} - text to display
     * @param size {int} - size of the text
     * @param color {color_t} - color of the text
     */
    Text::Text()
    {
        _font = "./assets/fonts/GamePlayed.ttf";
        _text = "caca";
        _size = 16;
        _color = { 0, 255, 255, 200};
        _pos = {140,  100};
        _display = true;
    }

    /**
     * @brief Destroy the Text:: Text object
     *
     */
    pos_t Text::getPos()
    {
        return _pos;
    }

    /**
     * @brief Get the Display object
     *
     * @return true - if the text is displayed
     * @return false - if the text is not displayed
     */
    bool Text::isDisplayed()
    {
        return _display;
    }

    /**
     * @brief Get the Type object
     *
     * @return ObjectType - the type of the object
     */
    ObjectType Text::getType()
    {
        return ObjectType::TEXT;
    }

    /**
     * @brief Get the Text object
     *
     * @return std::string - the text
     */
    std::string &Text::getText()
    {
        return _text;
    }

    /**
     * @brief Get the Font object
     *
     * @return std::string - the font
     */
    std::string &Text::getFont()
    {
        return _font;
    }

    /**
     * @brief Get the Size object
     *
     * @return int - the size of the text
     */
    float Text::getSize()
    {
        return _size;
    }

    /**
     * @brief Get the Color object
     *
     * @return color_t - the color of the text
     */
    color_t Text::getColor()
    {
        return _color;
    }

    /**
     * @brief Set the Pos object
     *
     * @param pos - the new position
     */
    void Text::setPos(pos_t pos)
    {
        _pos = pos;
    }

    /**
     * @brief Set the Display object
     *
     * @param display - true if the text is displayed, false if not
     */
    void Text::setDisplay(bool display)
    {
        _display = display;
    }

    /**
     * @brief Set the Text object
     *
     * @param text - the new text
     */
    void Text::setText(const std::string &text)
    {
        _text = text;
    }

    /**
     * @brief Set the Font object
     *
     * @param font - the new font
     */
    void Text::setFont(const std::string &font)
    {
        _font = font;
    }

    /**
     * @brief Set the Size object
     *
     * @param size - the new size
     */
    void Text::setSize(float size)
    {
        _size = size;
    }

    /**
     * @brief Set the Color object
     *
     * @param color - the new color
     */
    void Text::setColor(color_t color)
    {
        _color = color;
    }

    bool Text::positionCentered()
    {
        return false;
    }
}