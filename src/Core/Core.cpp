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
        _charNbr = 0;
        _username = "";
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
        _windowsParameter = {1920, 1080, false};
        _state = Arcade::CoreState::MENU;
        _username = "";
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
        makeLibInstance(_currentLibIndex);
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
        makeGameInstance(_currentGameIndex);
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
        makeLibInstance(_currentLibIndex);
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
        makeGameInstance(_currentGameIndex);
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
        pos_t basePos = {5, 10};
        int i = 0;
        for (const std::string &lib: *libsName) {
            Arcade::ButtonPtr s(
                new Arcade::Button(
                    lib,
                    {0, 0, 18, 2},
                    basePos,
                    {255, 255, 255, 255},
                    i == 0
                ));
            s->setGroup(Arcade::ButtonGroup::LIB);
            s->setId(i);
            _menuObjects->push_back(s);
            _menuObjects->push_back(s->getText());
            basePos.y += 3;
            i++;
        }
        i = 0;
        basePos = {25, 10};
        for (const std::string &game: *gamesName) {
            Arcade::ButtonPtr s(
                new Arcade::Button(
                    game,
                    {0, 0, 18, 2},
                    basePos,
                    {255, 255, 255, 500},
                    i == 0
                ));
            s->setGroup(Arcade::ButtonGroup::GAME);
            s->setId(i);
            _menuObjects->push_back(s);
            _menuObjects->push_back(s->getText());
            basePos.y += 3;
            i++;
        }
        Arcade::TextPtr text(new Arcade::Text({10, 32},
                                              "Please enter your username: (press enter to validate, you must enter a username before being able to play)",
                                              {255, 255, 255, 255}));
        _menuObjects->push_back(text);
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
        if (getCurrentGraphicLib()->getCurrentKey() == InputKey::INTERACT && !_username.empty()) {
            std::string libName = Button::searchInList(_gameObjects,
                ButtonGroup::LIB,
                _tempLibIndex)->getText()->getText();
            std::string gameName = Button::searchInList(_gameObjects,
                ButtonGroup::GAME,
                _tempGameIndex)->getText()->getText();
            _state = Arcade::CoreState::GAME;
            setCurrentGameLib(_tempGameIndex);
            if (_tempLibIndex != _currentLibIndex) {
                setCurrentGraphicLib(_tempLibIndex);
            }
            _gameObjects = getCurrentGameLib()->getGameObjects();
        }
        printInput();
    }

    void Core::printInput() {
        for (int a = 0; a < 28; a++) {
            if (getCurrentGraphicLib()->getCurrentKey() == matching[a].inputKey) {
                pos_t lastCharPos = {0, 0};
                for (int i = 0; i < _gameObjects->size(); i++) {
                    if (_gameObjects->at(i)->getType() ==
                        Arcade::ObjectType::TEXT) {
                        lastCharPos = {_gameObjects->at(i)->getPos().x,
                                       _gameObjects->at(i)->getPos().y};
                    }
                }
                if (lastCharPos.x == 10 && lastCharPos.y == 32) {
                    lastCharPos = {20, 34};
                }
                if (_charNbr > 0 && matching[a].inputKey == InputKey::BackSpace) {
                    _gameObjects->pop_back();
                    _username.pop_back();
                    _charNbr--;
                    continue;
                } else if (_charNbr == 0 && matching[a].inputKey == InputKey::BackSpace)
                    continue;
                if (_charNbr < 15) {
                    Arcade::TextPtr text(new Arcade::Text(
                            {static_cast<float>(lastCharPos.x + 0.5),
                             lastCharPos.y}, matching[a].character,
                            {255, 255, 255, 255}));
                    _gameObjects->push_back(text);
                    _username.push_back(matching[a].character[0]);
                    _charNbr++;
                }
            }
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

    std::string Core::getUsername() const
    {
        return _username;
    }
}