/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSFML.cpp
*/

#include "LibSFML.hpp"

#include <memory>

namespace Arcade {

    LibSFML::LibSFML()
    {
        std::cout << "constructor LibSFML" << std::endl;
    }

    LibSFML::~LibSFML()
    {
        if (_window.isOpen())
            _window.close();
        std::cout << "destructor LibSFML" << std::endl;
    }

    void LibSFML::loadObjects(IObjectVector gameObjects)
    {
        _objects = std::make_shared<sfml::IObjectVector>();
        initType_t initType[] = {
            {ObjectType::TEXT, &LibSFML::initText},
            {ObjectType::ENTITY, &LibSFML::initSprite}
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

    InputKey LibSFML::getCurrentKey()
    {
       return _key;
    }

    void LibSFML::eventListener() {
        _key = InputKey::NONE;

        if (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
            for (int i = 0; matching[i].inputKey != InputKey::SWITCH_GAME; ++i) {
                if (sf::Keyboard::isKeyPressed(matching[i].key))
                    _key = matching[i].inputKey;
            }
        }
    }

    void LibSFML::display()
    {
        eventListener();
        _window.clear();
        //for (sfml::IObjectPtr &object : *_objects)
        //    _window.draw(*object->getDrawable());
        _window.display();
    }

    windowsParameter_t LibSFML::getWindow()
    {
        return (_windowsParameter);
    }

    void LibSFML::setWindow(windowsParameter_t windows_parameter)
    {
        _videoMode = {windows_parameter.width, windows_parameter.height, 32};
    }

    void LibSFML::openWindow()
    {
        _window.create(_videoMode, "Arcade", sf::Style::Close | sf::Style::Resize);
    }

    void LibSFML::closeWindow()
    {
        _window.close();
    }

    bool LibSFML::isOpen()
    {
        return (_window.isOpen());
    }

    void LibSFML::initText(const IObjectPtr& object)
    {
        sfml::TextPtr text( new sfml::Text(
            (std::string &) "", (std::string &) "", sf::Color::White, object->getPos()));
        _objects->push_back(text);
    }

    void LibSFML::initSprite(const IObjectPtr& object)
    {
        sfml::SpritePtr sprite( new sfml::Sprite(
            (std::string &) "", sf::IntRect(0, 0, 0, 0), object->getPos()));
        _objects->push_back(sprite);
    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSFML();
    }
}
