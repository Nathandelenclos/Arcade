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
        this->_window = std::make_shared<sdl::Window>();
        this->_renderer = std::make_shared<sdl::Renderer>();
        this->_textures = std::make_shared<std::vector<sdl::TexturePtr>>();
        this->_event = std::make_shared<sdl::Event>();
        std::cout << "constructor LibSDL" << std::endl;
    }

    LibSDL::~LibSDL()
    {
        if (LibSDL::isOpen()) {
            LibSDL::closeWindow();
        }
        std::cout << "destructor LibSDL" << std::endl;
    }

    /**
     * @brief Init the window
     * @param gameObjects IObjectVector - The game objects
     */
    void LibSDL::loadObjects(IObjectVector gameObjects)
    {
        _textures->clear();
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

    void LibSDL::eventListener() {
        this->_key = InputKey::NONE;
        if (!this->_event->pollEvent()) {
            return;
        }
        if (this->_event->getEvent().type == SDL_QUIT) {
            this->closeWindow();
            this->_key = InputKey::ESCAPE;
        }
        if (this->_event->getEvent().type == SDL_KEYDOWN) {
            for (int i = 0; matching[i].inputKey != InputKey::NONE; ++i) {
                if (this->_event->getEvent().key.keysym.sym == matching[i].key)
                    this->_key = matching[i].inputKey;
            }
        }
    }

    void LibSDL::display()
    {
        eventListener();
        this->_renderer->clear();
        int i = 0;
        for (sdl::TexturePtr &texture : *this->_textures) {
            this->_renderer->draw(texture, {texture->getPos().x, texture->getPos().y});
        }
        this->_renderer->present();
    }

    windowsParameter_t LibSDL::getWindow()
    {
        return (this->_windowsParameter);
    }

    void LibSDL::setWindow(windowsParameter_t windows_parameter)
    {
        this->_windowsParameter = windows_parameter;
    }

    void LibSDL::openWindow()
    {
        std::string title = "Arcade";
        _window->create(title, _windowsParameter.width, _windowsParameter.height, false);
        _renderer->create(_window);
    }

    void LibSDL::closeWindow()
    {
        this->_window->setOpened(false);
    }

    bool LibSDL::isOpen()
    {
        return this->_window->isOpened();
    }

    void LibSDL::initText(const IObjectPtr &object) {
        ITextPtr text = std::dynamic_pointer_cast<IText>(object);
        color_t color = {255, 255, 255, 255};

        sdl::TexturePtr texture = sdl::Texture::loadFromText(_renderer, text->getText(), text->getFont(), color);
        this->_textures->push_back(texture);
    }

    void LibSDL::initSprite(const IObjectPtr &object) {

    }

    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSDL();
    }
}
