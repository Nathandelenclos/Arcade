/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <utility>

namespace Arcade {

    /**
     * @brief Construct a new Core:: Core object
     */
    Core::Core()
    {
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _menuObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _currentGameIndex = 0;
        _currentLibIndex = 0;
        _isRunning = true;
        _windowsParameter = {800, 600, false};
        _state = Arcade::CoreState::MENU;
    }

    Core::Core(const std::string &lib, const Arcade::StringVectorPtr &libs,
        const Arcade::StringVectorPtr &games)
    {
        _libLoader = std::make_shared<Arcade::DlLoaderGraphic>(lib);
        _libsName = libs;
        _gamesName = games;
        _currentGameIndex = 0;
        _currentLibIndex = 0;
        for (std::string &l: *_libsName) {
            if (l == lib) {
                break;
            }
            _currentLibIndex++;
        }
        _currentLib = _libLoader->getGraphInstance();
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _menuObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _isRunning = true;
        _windowsParameter = {800, 600, false};
        _state = Arcade::CoreState::MENU;
    }

    /**
     * @brief Destroy the Core:: Core object
     */
    Core::~Core() = default;

    /**
     * @brief Get the current graphic library
     */
    IGraphicLibPtr Core::getCurrentGraphicLib() const
    {
        return _currentLib;
    }

    /**
     * @brief Get the current game library
     */
    IGameLibPtr Core::getCurrentGameLib() const
    {
        return _currentGame;
    }

    /**
     * @brief Set the current graphic library
     * @param index - the index of the library
     */
    void Core::setCurrentGraphicLib(int index)
    {
        stopGraphic();
        _currentLibIndex = index;
        if (_currentLibIndex == _libsName->size()) {
            _currentLibIndex = 0;
        }
        _libLoader = std::make_shared<Arcade::DlLoaderGraphic>(
            _libsName->at(_currentLibIndex));
        _currentLib = _libLoader->getGraphInstance();
        startGraphic();
    }

    /**
     * @brief Set the current game library
     * @param index - the index of the library
     */
    void Core::setCurrentGameLib(int index)
    {
        _currentGameIndex = index;
        if (_currentGameIndex == _gamesName->size()) {
            _currentGameIndex = 0;
        }
        _gameLoader = std::make_shared<Arcade::DlLoaderGame>(
            _gamesName->at(_currentGameIndex));
        _currentGame = _gameLoader->getGameInstance();
        setState(Arcade::CoreState::GAME);
    }

    /**
     * @brief Switch the graphic library
     */
    void Core::switchGraphicLib()
    {
        stopGraphic();
        _currentLibIndex++;
        if (_currentLibIndex == _libsName->size()) {
            _currentLibIndex = 0;
        }
        _libLoader = std::make_shared<Arcade::DlLoaderGraphic>(
            _libsName->at(_currentLibIndex));
        _currentLib = _libLoader->getGraphInstance();
        startGraphic();
    }

    /**
     * @brief Switch the game library
     */
    void Core::switchGameLib()
    {
        _currentGameIndex++;
        if (_currentGameIndex == _gamesName->size()) {
            _currentGameIndex = 0;
        }
        _gameLoader = std::make_shared<Arcade::DlLoaderGame>(
            _gamesName->at(_currentGameIndex));
        _currentGame = _gameLoader->getGameInstance();
        setState(Arcade::CoreState::GAME);
    }

    /**
     * @brief Start the graphic library
     */
    void Core::startGraphic()
    {
        getCurrentGraphicLib()->setWindow(_windowsParameter);
        getCurrentGraphicLib()->openWindow();
        getCurrentGraphicLib()->loadObjects(_gameObjects);
    }

    /**
     * @brief Stop the graphic library
     */
    void Core::stopGraphic() const
    {
        getCurrentGraphicLib()->closeWindow();
    }

    /**
     * @brief Get the running state
     */
    bool Core::isRunning() const
    {
        return _isRunning;
    }

    /**
     * @brief Set the running state
     * @param isRunning - the new state
     */
    void Core::setRunning(bool isRunning)
    {
        _isRunning = isRunning;
    }

    /**
     * @brief Create the main menu
     * @param libsName - the graphic libraries name
     * @param gamesName - the game libraries name
     */
    void Core::createMainMenu(const StringVectorPtr &libsName,
        const StringVectorPtr &gamesName)
    {
        pos_t basePos = {5, 0};
        int i = 0;
        for (const std::string &lib: *libsName) {
            Arcade::ButtonPtr s(
                new Arcade::Button(
                    lib,
                    {0, 0, 25, 1},
                    basePos,
                    {255, 255, 255, 255},
                    i == 0
                ));
            s->setGroup(Arcade::ButtonGroup::LIB);
            s->setId(i);
            _menuObjects->push_back(s);
            _menuObjects->push_back(s->getText());
            basePos.y += 2;
            i++;
        }
        i = 0;
        basePos = {35, 0};
        for (const std::string &game: *gamesName) {
            Arcade::ButtonPtr s(
                new Arcade::Button(
                    game,
                    {0, 0, 25, 1},
                    basePos,
                    {255, 255, 255, 500},
                    i == 0
                ));
            s->setGroup(Arcade::ButtonGroup::GAME);
            s->setId(i);
            _menuObjects->push_back(s);
            _menuObjects->push_back(s->getText());
            basePos.y += 2;
            i++;
        }
        _gameObjects = _menuObjects;
    }

    /**
     * @brief Create the game menu
     */
    void Core::logicalMenu()
    {
        if (_state != Arcade::CoreState::MENU) {
            return;
        }
        for (const auto &obj: *_gameObjects) {
            if (!Button::isButton(obj)) {
                continue;
            }
            ButtonPtr button = std::dynamic_pointer_cast<Button>(obj);
            if (getCurrentGraphicLib()->getCurrentKey() == InputKey::SWITCH_LIB
                && button->getGroup() == ButtonGroup::LIB) {
                if (button->isSelected()) {
                    button->setSelected(false);
                    ButtonPtr nextButton = Button::searchInList(_gameObjects,
                        ButtonGroup::LIB,
                        (button->getId() + 1) % _libsName->size());
                    if (nextButton) {
                        nextButton->setSelected(true);
                        _tempLibIndex = nextButton->getId();
                        break;
                    }
                }
            }
            if (getCurrentGraphicLib()->getCurrentKey() ==
                InputKey::SWITCH_GAME
                && button->getGroup() == ButtonGroup::GAME) {
                if (button->isSelected()) {
                    button->setSelected(false);
                    ButtonPtr nextButton = Button::searchInList(_gameObjects,
                        ButtonGroup::GAME,
                        (button->getId() + 1) % _gamesName->size());
                    if (nextButton) {
                        nextButton->setSelected(true);
                        _tempGameIndex = nextButton->getId();
                        break;
                    }
                }
            }
        }

        if (getCurrentGraphicLib()->getCurrentKey() ==
            Arcade::InputKey::ESCAPE) {
            setRunning(false);
        }
        if (getCurrentGraphicLib()->getCurrentKey() == InputKey::INTERACT) {
            std::string libName = Button::searchInList(_gameObjects,
                ButtonGroup::LIB,
                _tempLibIndex)->getText()->getText();
            std::string gameName = Button::searchInList(_gameObjects,
                ButtonGroup::GAME,
                _tempGameIndex)->getText()->getText();
            _state = Arcade::CoreState::GAME;
            makeGameInstance(_tempGameIndex);
            if (_tempLibIndex != _currentLibIndex)
                makeLibInstance(_tempLibIndex);
            _gameObjects = getCurrentGameLib()->getGameObjects();
            std::cerr << "Starting " << gameName << " with " << libName
                << std::endl;
        }
    }

    /**
     * @brief Get the current game library
     * @return the current game library
     */
    Arcade::IObjectVector Core::getGameObjects() const
    {
        return _gameObjects;
    }

    /**
     * @brief Get the current game library
     * @return the current game library
     */
    enum CoreState Core::getState() const
    {
        return _state;
    }

    /**
     * @brief Set the current game library
     * @param state - the new state
     */
    void Core::setState(enum CoreState state)
    {
        if (state == Arcade::CoreState::MENU) {
            _gameObjects = _menuObjects;
        } else if (state == Arcade::CoreState::GAME) {
            _gameObjects = getCurrentGameLib()->getGameObjects();
        }
        _state = state;
    }

    /**
     * @brief Get the current graphic library
     * @param index - the index of the library
     */
    void Core::makeGameInstance(int index)
    {
        _currentGameIndex = index;
        if (_currentGame) {
            _currentGame.reset();
        }
        if (_gameLoader) {
            _gameLoader.reset();
        }
        _gameLoader = std::make_shared<Arcade::DlLoaderGame>(
            _gamesName->at(index));
        _currentGame = _gameLoader->getGameInstance();
    }

    /**
     * @brief Get the current graphic library
     * @param index - the index of the library
     */
    void Core::makeLibInstance(int index)
    {
        _currentLibIndex = index;
        if (_currentLib) {
            _currentLib.reset();
        }
        if (_libLoader) {
            _libLoader.reset();
        }
        _libLoader = std::make_shared<Arcade::DlLoaderGraphic>(
            _libsName->at(index));
        _currentLib = _libLoader->getGraphInstance();
    }
}