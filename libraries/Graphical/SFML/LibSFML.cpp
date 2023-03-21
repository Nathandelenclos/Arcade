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
        _objects = std::make_shared<sfml::IObjectVector>();
    }

    LibSFML::~LibSFML()
    {
        if (_window.isOpen())
            _window.close();
        std::cout << "destructor LibSFML" << std::endl;
    }

    /**
     * @brief Init the window
     * @param gameObjects IObjectVector - The game objects
     */
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

    /**
     * @brief Get the current key
     * @return InputKey - The current key
     */
    InputKey LibSFML::getCurrentKey()
    {
       return _key;
    }

    /**
     * @brief Event listener
     */
    void LibSFML::eventListener() {
        _key = InputKey::NONE;

        if (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window.close();
                _key = InputKey::ESCAPE;
            }
            for (int i = 0; matching[i].inputKey != InputKey::SWITCH_GAME; ++i) {
                if (sf::Keyboard::isKeyPressed(matching[i].key))
                    _key = matching[i].inputKey;
            }
        }
    }

    /**
     * @brief Initialize a text
     * @param object IObjectPtr - The object to initialize
     */
    void LibSFML::display()
    {
        eventListener();
        _window.clear();
        for (sfml::IObjectPtr &object : *_objects)
            _window.draw(*object->getDrawable());
        _window.display();
    }

    /**
     * @brief Get the window
     * @return windowsParameter_t - The window parameters
     */
    windowsParameter_t LibSFML::getWindow()
    {
        return (_windowsParameter);
    }

    /**
     * @brief Set the window
     * @param windows_parameter windowsParameter_t - The window parameters
     */
    void LibSFML::setWindow(windowsParameter_t windows_parameter)
    {
        _videoMode = {windows_parameter.width, windows_parameter.height, 32};
    }

    /**
     * @brief Open the window
     */
    void LibSFML::openWindow()
    {
        _window.create(_videoMode, "Arcade", sf::Style::Close | sf::Style::Resize);
    }

    /**
     * @brief Close the window
     */
    void LibSFML::closeWindow()
    {
        _window.close();
    }

    /**
     * @brief Check if the window is open
     * @return bool - True if the window is open
     */
    bool LibSFML::isOpen()
    {
        return (_window.isOpen());
    }

    /**
     * @brief Init a text
     * @param object const IObjectPtr& - The object to init
     */
    void LibSFML::initText(const IObjectPtr& object)
    {
        ITextPtr t = std::dynamic_pointer_cast<IText>(object);
        sfml::TextPtr text( new sfml::Text(
            t->getText(),
            t->getFont(),
            sf::Color(t->getColor().r, t->getColor().g, t->getColor().b, t->getColor().a),
            object->getPos()));
        _objects->push_back(text);
    }

    /**
     * @brief Init a sprite
     * @param object const IObjectPtr& - The object to init
     */
    void LibSFML::initSprite(const IObjectPtr& object)
    {
        IEntitiesPtr s = std::dynamic_pointer_cast<IEntities>(object);
        sfml::SpritePtr sprite( new sfml::Sprite(
            s->getSprite(),
            sf::IntRect(s->getRect().x, s->getRect().y, s->getRect().width, s->getRect().height),
            object->getPos()));
        _objects->push_back(sprite);
    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSFML();
    }
}
