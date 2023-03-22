/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <utility>
#include "DlLoader.hpp"

namespace Arcade {

    /**
     * @brief Construct a new Core:: Core object
     */
    Core::Core()
    {
        _gamesLibs = std::make_shared<std::vector<Arcade::IGameLibPtr>>();
        _graphicLibs = std::make_shared<std::vector<Arcade::IGraphicLibPtr>>();
        _currentGame = 0;
        _currentLib = 0;
        _isRunning = true;
        _windowsParameter =  {800, 600, false};
    }

    /**
     * @brief Construct a new Core:: Core object
     * @param graphicLibsLoader - the graphic libraries loader
     * @param gameLibsLoader - the game libraries loader
     */
    Core::Core(
        const std::shared_ptr<std::vector<Arcade::DlLoaderGraphicPtr>>& graphicLibsLoader,
        const std::shared_ptr<std::vector<Arcade::DlLoaderGamePtr>>& gameLibsLoader,
        Arcade::StringVectorPtr libs,
        Arcade::StringVectorPtr games)
    {
        _gamesLibs = std::make_shared<std::vector<Arcade::IGameLibPtr>>();
        _graphicLibs = std::make_shared<std::vector<Arcade::IGraphicLibPtr>>();
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _libsName = std::move(libs);
        _gamesName = std::move(games);
        _currentGame = 0;
        _currentLib = 0;
        _isRunning = true;
        _windowsParameter =  {800, 600, false};
        getGraphicalInstances(graphicLibsLoader);
        getGameInstances(gameLibsLoader);
    }

    /**
     * @brief Destroy the Core:: Core object
     */
    Core::~Core() = default;

    /**
     * @brief Add a graphic library to the core
     * @param lib - the library to add
     */
    void Core::addGraphicLib(const Arcade::IGraphicLibPtr& lib)
    {
        _graphicLibs->push_back(lib);
    }

    /**
     * @brief Add a game library to the core
     * @param lib - the library to add
     */
    void Core::addGameLib(const IGameLibPtr &lib)
    {
        _gamesLibs->push_back(lib);
    }

    /**
     * @brief Get the graphic libraries
     */
    std::shared_ptr<std::vector<Arcade::IGraphicLibPtr>>
    Core::getGraphicLibs() const
    {
        return _graphicLibs;
    }

    /**
     * @brief Get the game libraries
     */
    std::shared_ptr<std::vector<Arcade::IGameLibPtr>> Core::getGameLibs() const
    {
        return _gamesLibs;
    }

    /**
     * @brief Get the current graphic library
     */
    IGraphicLibPtr Core::getCurrentGraphicLib() const
    {
        return _graphicLibs->at(_currentLib);
    }

    /**
     * @brief Get the current game library
     */
    IGameLibPtr Core::getCurrentGameLib() const
    {
        return _gamesLibs->at(_currentGame);
    }

    /**
     * @brief Set the current graphic library
     * @param index - the index of the library
     */
    void Core::setCurrentGraphicLib(int index)
    {
        _currentLib = index;
    }

    /**
     * @brief Set the current game library
     * @param index - the index of the library
     */
    void Core::setCurrentGameLib(int index)
    {
        _currentGame = index;
    }

    /**
     * @brief Switch the graphic library
     */
    void Core::switchGraphicLib()
    {
        stopGraphic();
        if (_currentLib == _graphicLibs->size() - 1)
            _currentLib = 0;
        else
            _currentLib++;
        startGraphic();
    }

    /**
     * @brief Switch the game library
     */
    void Core::switchGameLib()
    {
        if (_currentGame == _gamesLibs->size() - 1)
            _currentGame = 0;
        else
            _currentGame++;
    }

    /**
     * @brief Start the graphic library
     */
    void Core::startGraphic()
    {
        getCurrentGraphicLib()->setWindow(_windowsParameter);
        getCurrentGraphicLib()->loadObjects(_gameObjects);
        getCurrentGraphicLib()->openWindow();
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
     * @brief Get graphical instances
     * @param graphicLibs
     */
    void Core::getGraphicalInstances(
        const std::shared_ptr<std::vector<Arcade::DlLoaderGraphicPtr>>& graphicLibs)
    {
        for (auto &lib : *graphicLibs) {
            addGraphicLib(lib->getGraphInstance());
        }
    }

    /**
     * @brief Get game instances
     * @param gameLibs
     */
    void Core::getGameInstances(
        const std::shared_ptr<std::vector<Arcade::DlLoaderGamePtr>>& gameLibs)
    {
        for (auto &lib : *gameLibs) {
            addGameLib(lib->getGameInstance());
        }
    }

    /**
     * @brief Create the main menu
     * @param libsName - the graphic libraries name
     * @param gamesName - the game libraries name
     */
    void Core::createMainMenu(const StringVectorPtr& libsName, const StringVectorPtr& gamesName)
    {
        pos_t basePos = {10, 10};
        int i = 0;
        for (const auto& lib: *libsName) {
            Arcade::ButtonPtr s(new Arcade::Button(lib, {0, 0, 240, 20}, basePos, {255, 255, 255, 255},
                                                   i == 0));
            s->setGroup(Arcade::ButtonGroup::LIB);
            s->setId(i);
            _gameObjects->push_back(s);
            _gameObjects->push_back(s->getText());
            basePos.y += 30;
            i++;
        }
        i = 0;
        basePos = {10, 100};
        for (const auto& game: *gamesName) {
            Arcade::ButtonPtr s(new Arcade::Button(game, {0, 0, 240, 20}, basePos, {255, 255, 255, 255},
                                                   i == 0));
            s->setGroup(Arcade::ButtonGroup::GAME);
            s->setId(i);
            _gameObjects->push_back(s);
            _gameObjects->push_back(s->getText());
            basePos.y += 30;
            i++;
        }
    }

    /**
     * @brief Create the game menu
     */
    void Core::logicalMenu()
    {
        size_t selectedIdLib = 0;
        size_t selectedIdGame = 0;
        for (const auto &obj: *_gameObjects) {
            if (obj->getType() == ObjectType::ENTITY) {
                ButtonPtr button = std::dynamic_pointer_cast<Button>(obj);
                if (getCurrentGraphicLib()->getCurrentKey() ==
                    InputKey::SWITCH_LIB
                    && button->getGroup() == ButtonGroup::LIB) {
                    if (button->isSelected()) {
                        button->setSelected(false);
                        selectedIdLib = button->getId();
                    }
                }
                if (getCurrentGraphicLib()->getCurrentKey() ==
                    InputKey::SWITCH_GAME
                    && button->getGroup() == ButtonGroup::GAME) {
                    if (button->isSelected()) {
                        button->setSelected(false);
                        selectedIdGame = button->getId();
                    }
                }
            }
        }
        if (selectedIdLib == _graphicLibs->size() - 1)
            selectedIdLib = 0;
        else
            selectedIdLib++;
        for (const auto &obj: *_gameObjects) {
            if (obj->getType() == ObjectType::ENTITY) {
                ButtonPtr button = std::dynamic_pointer_cast<Button>(obj);
                if (getCurrentGraphicLib()->getCurrentKey() ==
                    InputKey::SWITCH_LIB
                    && button->getGroup() == ButtonGroup::LIB) {
                    if (button->getId() == selectedIdLib) {
                        button->setSelected(true);
                    }
                }
                if (getCurrentGraphicLib()->getCurrentKey() ==
                    InputKey::SWITCH_GAME
                    && button->getGroup() == ButtonGroup::GAME) {
                    if (button->getId() == selectedIdGame) {
                        button->setSelected(true);
                    }
                }
            }
        }
        getCurrentGraphicLib()->loadObjects(_gameObjects);
    }

}