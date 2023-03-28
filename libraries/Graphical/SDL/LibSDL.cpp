/*
** EPITECH PROJECT, 2023
** B_OOP_400_LIL_4_1_arcade_nathan_delenclos
** File description:
** LibSDL.cpp
*/

#include "LibSDL.hpp"

namespace Arcade {

    /**
     * @brief Constructor of LibSDL object
     */
    LibSDL::LibSDL()
    {
        this->_window = std::make_shared<sdl::Window>();
        this->_renderer = std::make_shared<sdl::Renderer>();
        this->_textures = std::make_shared<std::vector<sdl::TexturePtr>>();
        this->_event = std::make_shared<sdl::Event>();
        std::cout << "constructor LibSDL" << std::endl;
    }

    /**
     * @brief Destructor of LibSDL object
     */
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

    /**
     * @brief Get the current key
     * @return InputKey - The current key
     */
    InputKey LibSDL::getCurrentKey()
    {
        return _key;
    }

    /**
     * @brief Event listener
     */
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

    /**
     * @brief Display every objects
     */
    void LibSDL::display()
    {
        eventListener();
        this->_renderer->clear();
        int i = 0;
        for (sdl::TexturePtr &texture : *this->_textures) {
            this->_renderer->clear();
            this->_renderer->draw(texture, texture->getRect());
        }
        this->_renderer->present();
    }

    /**
     * @brief Get the current window parameters
     * @return windowParameter_t - The window parameters
     */
    windowsParameter_t LibSDL::getWindow()
    {
        return (this->_windowsParameter);
    }

    /**
     * @brief Set the current window parameters
     * @param windows_parameter windowsParameter_t - The window parameters
     */
    void LibSDL::setWindow(windowsParameter_t windows_parameter)
    {
        this->_windowsParameter = windows_parameter;
    }

    /**
     * @brief Open the window
     */
    void LibSDL::openWindow()
    {
        std::string title = "Arcade";
        _window->create(title, _windowsParameter.width, _windowsParameter.height, false);
        _renderer->create(_window);
    }

    /**
     * @brief Close the window
     */
    void LibSDL::closeWindow()
    {
        this->_window->setOpened(false);
    }

    /**
     * @brief Check if the window is open
     * @return bool - True if the window is open else false
     */
    bool LibSDL::isOpen()
    {
        return this->_window->isOpened();
    }

    /**
     * @brief Init the text
     * @param object IObjectPtr - The text object
     */
    void LibSDL::initText(const IObjectPtr &object) {
        ITextPtr text = std::dynamic_pointer_cast<IText>(object);
        color_t color = {255, 255, 255, 255};

        sdl::TexturePtr texture = sdl::Texture::loadFromText(_renderer, text->getText(), text->getFont(), color, text->getSize(), text->getPos());
        this->_textures->push_back(texture);
    }

    /**
     * @brief Init the sprite
     * @param object IObjectPtr - The sprite object
     */
    void LibSDL::initSprite(const IObjectPtr &object) {
        IEntitiesPtr s = std::dynamic_pointer_cast<IEntities>(object);
        if (s->getSprite().empty()) {
            sdl::TexturePtr texture = sdl::Texture::loadFromRectangle(this->_renderer, s->getRect().width, s->getRect().height, s->getColor(), s->getPos());
            this->_textures->push_back(texture);
        } else {
            sdl::TexturePtr texture = sdl::Texture::loadFromFile(this->_renderer, s->getSprite());
            texture->setColor(s->getColor());
            Arcade::sdl::rect_t rect = {{s->getRect().x, s->getRect().y}, static_cast<size_t>(s->getRect().width), static_cast<size_t>(s->getRect().height)};
            texture->setRect(rect);
        }
    }

    /**
     * @brief Init the library in C
     */
    extern "C" IGraphicLib *constructor_graphic()
    {
        return new LibSDL();
    }
}
