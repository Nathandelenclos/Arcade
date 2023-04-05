/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibNCURSES.cpp
*/

#include "LibNCURSES.hpp"

#include <memory>

namespace Arcade {

    /**
     * @brief Construct a new Lib NCURSES:: Lib NCURSES object
     *
     */
    LibNCURSES::LibNCURSES()
    {
        _window = std::make_shared<ncurses::Window>();
        _map = std::make_shared<ncurses::charVector>();
        _texts = std::make_shared<ncurses::textVector>();
        _colors = std::make_shared<ncurses::ColorVector>();
        _pairs = std::make_shared<ncurses::ColorPairVector>();
    }

    /**
     * @brief Destroy the Lib NCURSES:: Lib NCURSES object
     *
     */
    LibNCURSES::~LibNCURSES()
    {
        if (_window->isOpen())
            _window->close();
    }

    /**
     * @brief Init the window
     * @param gameObjects IObjectVector - The game objects
     */
    void LibNCURSES::loadObjects(IObjectVector gameObjects)
    {
        initType_t initType[] = {
            {ObjectType::ENTITY, &LibNCURSES::initEntity},
            {ObjectType::TEXT, &LibNCURSES::initText}
        };
        _map = std::make_shared<ncurses::charVector>();
        for (IObjectPtr &gameObject : *gameObjects) {
            if (!gameObject->isDisplayed())
                continue;
            for (initType_t init_type: initType) {
                if (gameObject->getType() == init_type.type) {
                    (this->*init_type.init)(gameObject);
                }
            }
        }
    }

    /**
     * @brief get the current key
     * @param object InputKey - The current key
     */
    InputKey LibNCURSES::getCurrentKey()
    {
        return _currentKey;
    }

    /**
     * @brief Event listener
     */
    void LibNCURSES::display()
    {
        eventListener();
        _window->clearAll();
        _window->displayChar(_map);
    }

    /**
     * @brief get window parameter
     * @return windowsParameter_t - The window parameter
     */
    windowsParameter_t LibNCURSES::getWindow()
    {
        return (_windowsParameter);
    }

    /**
     * @brief set window parameter
     * @param windowsParameter windowsParameter_t - The window parameter
     */
    void LibNCURSES::setWindow(windowsParameter_t windowsParameter)
    {
        _windowsParameter = windowsParameter;
    }

    /**
     * @brief Open the window
     */
    void LibNCURSES::openWindow()
    {
        _window->open();
    }

    /**
     * @brief Close the window
     */
    void LibNCURSES::closeWindow()
    {
        _window->close();
    }

    /**
     * @brief Check if the window is open
     * @return true - The window is open
     * @return false - The window is close
     */
    bool LibNCURSES::isOpen()
    {
        return _window->isOpen();
    }

    /**
     * @brief Init the Entity
     */
    void LibNCURSES::initEntity(const IObjectPtr &object)
    {
        IEntitiesPtr t = std::dynamic_pointer_cast<IEntities>(object);
        ncurses::ColorPtr color = ncurses::Color::searchByColorOrCreate(_colors, t->getColor());
        ncurses::ColorPairPtr pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, COLOR_BLACK, color->getId());
        int width = static_cast<int>(t->getRect().width);
        int height = static_cast<int>(t->getRect().height);
        for (int i = 0; i < width * 2.5; i++) {
            for (int j = 0; j < height; j++) {
                ncurses::charPtr c = searchChar(_map, {t->getPos().x + i, t->getPos().y + j});
                if (c == nullptr) {
                    _map->push_back(std::make_shared<ncurses::char_t>( ncurses::char_t{
                        pair,
                        ' ',
                        static_cast<int>(t->getPos().x) + i,
                        static_cast<int>(t->getPos().y) + j
                    }));
                } else {
                    c->pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, c->pair->getColor(), color->getId());
                }
            }
        };
    }

    /**
     * @brief Init the Text
     */
    void LibNCURSES::initText(const IObjectPtr &object)
    {
        ITextPtr t = std::dynamic_pointer_cast<IText>(object);
        ncurses::ColorPtr color = ncurses::Color::searchByColorOrCreate(_colors, t->getColor());
        ncurses::ColorPairPtr pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, color->getId(), COLOR_BLACK);
        for (int i = 0; i < t->getText().length(); ++i) {
            pos_t pos = {t->getPos().x + static_cast<float>(i), t->getPos().y};
            ncurses::charPtr  c = searchChar(_map, pos);
            if (c == nullptr) {
                _map->push_back(std::make_shared<ncurses::char_t>( ncurses::char_t{
                    pair,
                    t->getText()[i],
                    static_cast<int>(pos.x),
                    static_cast<int>(pos.y)
                }));
            } else {
                c->pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, color->getId(), c->pair->getBackground());
                c->chara = t->getText()[i];
            }
        }
    }

    /**
     * @brief Event listener
     */
    void LibNCURSES::eventListener()
    {
        _currentKey = InputKey::NONE;
        int event = _window->poolEvent();
        for (keyMatching key_matching: mapping) {
            if (event == key_matching.c) {
                _currentKey = key_matching.inputKey;
            }
        }
    }

    /**
     * @brief Search a char in a vector
     * @param v ncurses::charVectorPtr - The vector
     * @param pos pos_t - The position
     * @return ncurses::charPtr - The char
     */
    ncurses::charPtr LibNCURSES::searchChar(const ncurses::charVectorPtr &v,pos_t pos)
    {
        for (ncurses::charPtr &c: *v) {
            if (c->x == static_cast<int>(pos.x) && c->y == static_cast<int>(pos.y)) {
                return c;
            }
        }
        return nullptr;
    }

    /**
     * @brief External constructor
     */
    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibNCURSES();
    }
}
