/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSDL.cpp
*/

#include "LibSDL.hpp"

namespace Arcade {

    LibSDL::LibSDL()
    {
        std::cout << "constructor LibSDL" << std::endl;
    }

    LibSDL::~LibSDL()
    {
        std::cout << "destructor LibSDL" << std::endl;
    }

    void LibSDL::loadObjects(IObjectVector gameObjects)
    {
        this->_objects = gameObjects;
        initType_t initType[] = {
                {ObjectType::TEXT, &LibSDL::initText},
                {ObjectType::ENTITY, &LibSDL::initSprite}
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

    InputKey LibSDL::getCurrentKey()
    {
        return _key;
    }

    void LibSDL::display()
    {

    }

    windowsParameter_t LibSDL::getWindow()
    {
        return (_windowsParameter);
    }

    void LibSDL::setWindow(windowsParameter_t windows_parameter)
    {

    }

    void LibSDL::openWindow()
    {

    }

    void LibSDL::closeWindow()
    {

    }

    bool LibSDL::isOpen()
    {
        return false;
    }

    void LibSDL::initText(const IObjectPtr &object) {

    }

    void LibSDL::initSprite(const IObjectPtr &object) {

    }

    void LibSDL::eventListener() {

    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSDL();
    }
}
