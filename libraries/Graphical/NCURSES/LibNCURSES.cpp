/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibNCURSES.cpp
*/

#include "LibNCURSES.hpp"

#include <memory>

namespace Arcade {

    LibNCURSES::LibNCURSES()
    {
        std::cout << "constructor LibNCURSES" << std::endl;
        _window = std::make_shared<ncurses::Window>();
        _map = std::make_shared<ncurses::charVector>();
        _texts = std::make_shared<ncurses::textVector>();
        _colors = std::make_shared<ncurses::ColorVector>();
        _pairs = std::make_shared<ncurses::ColorPairVector>();
    }

    LibNCURSES::~LibNCURSES()
    {
        std::cout << "destructor LibNCURSES" << std::endl;
    }

    void LibNCURSES::loadObjects(IObjectVector gameObjects)
    {
        initType_t initType[] = {
            {ObjectType::ENTITY, &LibNCURSES::initEntity},
            {ObjectType::TEXT, &LibNCURSES::initText}
        };
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

    InputKey LibNCURSES::getCurrentKey()
    {
        return _currentKey;
    }

    void LibNCURSES::display()
    {
        eventListener();
        _window->clearAll();
        _window->displayChar(_map);
    }

    windowsParameter_t LibNCURSES::getWindow()
    {
        return (_windowsParameter);
    }

    void LibNCURSES::setWindow(windowsParameter_t windowsParameter)
    {
        _windowsParameter = windowsParameter;
    }

    void LibNCURSES::openWindow()
    {
        _window->open();
    }

    void LibNCURSES::closeWindow()
    {
        _window->close();
    }

    bool LibNCURSES::isOpen()
    {
        return _window->isOpen();
    }

    void LibNCURSES::initEntity(const IObjectPtr &object)
    {
        IEntitiesPtr t = std::dynamic_pointer_cast<IEntities>(object);
        ncurses::ColorPtr color = ncurses::Color::searchByColorOrCreate(_colors, t->getColor());
        ncurses::ColorPairPtr pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, COLOR_BLACK, color->getId());
        int width = static_cast<int>(t->getRect().width);
        int height = static_cast<int>(t->getRect().height);
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                ncurses::charPtr c = searchChar(_map, {t->getPos().x + i, t->getPos().y + j});
                if (c == nullptr) {
                    std::cerr << "push back" << std::endl;
                    _map->push_back(std::make_shared<ncurses::char_t>( ncurses::char_t{
                        pair,
                        ' ',
                        static_cast<int>(t->getPos().x) + i,
                        static_cast<int>(t->getPos().y) + j
                    }));
                } else {
                    std::cerr << "change" << std::endl;
                    c->pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, c->pair->getColor(), color->getId());
                }
            }
        };
    }

    void LibNCURSES::initText(const IObjectPtr &object)
    {
        ITextPtr t = std::dynamic_pointer_cast<IText>(object);
        ncurses::ColorPtr color = ncurses::Color::searchByColorOrCreate(_colors, t->getColor());
        ncurses::ColorPairPtr pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, color->getId(), COLOR_BLACK);
        for (int i = 0; i < t->getText().length(); ++i) {
            pos_t pos = {t->getPos().x + static_cast<float>(i), t->getPos().y};
            ncurses::charPtr  c = searchChar(_map, pos);
            if (c == nullptr) {
                std::cerr << "push back" << std::endl;
                _map->push_back(std::make_shared<ncurses::char_t>( ncurses::char_t{
                    pair,
                    t->getText()[i],
                    static_cast<int>(pos.x),
                    static_cast<int>(pos.y)
                }));
            } else {
                std::cerr << "change" << std::endl;
                c->pair = ncurses::ColorPair::searchByColorPairOrCreate(_pairs, color->getId(), c->pair->getBackground());
                c->chara = t->getText()[i];
            }
        }
    }

    void LibNCURSES::eventListener()
    {
        for (keyMatching key_matching: mapping) {
            if (_window->poolEvent() == key_matching.c)
                _currentKey = key_matching.inputKey;
        }
    }

    ncurses::charPtr LibNCURSES::searchChar(const ncurses::charVectorPtr &v,pos_t pos)
    {
        for (ncurses::charPtr &c: *v) {
            if (c->x == static_cast<int>(pos.x) && c->y == static_cast<int>(pos.y)) {
                return c;
            }
        }
        return nullptr;
    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibNCURSES();
    }
}
