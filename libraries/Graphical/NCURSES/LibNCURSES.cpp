/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibNCURSES.cpp
*/

#include "LibNCURSES.hpp"

namespace Arcade {

    LibNCURSES::LibNCURSES()
    {
        std::cout << "constructor LibNCURSES" << std::endl;
        _window = std::make_shared<ncurses::Window>();
    }

    LibNCURSES::~LibNCURSES()
    {
        std::cout << "destructor LibNCURSES" << std::endl;
    }

    void LibNCURSES::loadObjects(IObjectVector gameObjects)
    {
        initType_t initType[] = {
            {ObjectType::ENTITY, &LibNCURSES::initEntity}
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

        int width = static_cast<int>(t->getRect().width) % 20;
        int height = static_cast<int>(t->getRect().height) % 20;
        int x = static_cast<int>(t->getPos().x) % 20;
        int y = static_cast<int>(t->getPos().y) % 20;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                _map->push_back(std::make_shared<ncurses::char_t>(ncurses::char_t{
                    color_t {t->getColor().r, t->getColor().g, t->getColor().b, t->getColor().a},
                    ' ',
                    y + j,
                    x + i
                }));
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

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibNCURSES();
    }
}
