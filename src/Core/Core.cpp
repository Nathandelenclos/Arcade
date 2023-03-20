/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace Arcade {

    Core::Core()
    {
        _gamesLibs = std::make_shared<std::vector<Arcade::IGameLibPtr>>();
        _graphicLibs = std::make_shared<std::vector<Arcade::IGraphicLibPtr>>();
        _currentGame = 0;
        _currentLib = 0;
        _isRunning = true;
        _windowsParameter =  {800, 600, false};
    }

    Core::~Core() = default;

    void Core::addGraphicLib(const Arcade::IGraphicLibPtr& lib)
    {
        _graphicLibs->push_back(lib);
    }

    void Core::addGameLib(const IGameLibPtr &lib)
    {
        _gamesLibs->push_back(lib);
    }

    std::shared_ptr<std::vector<Arcade::IGraphicLibPtr>>
    Core::getGraphicLibs() const
    {
        return _graphicLibs;
    }

    std::shared_ptr<std::vector<Arcade::IGameLibPtr>> Core::getGameLibs() const
    {
        return _gamesLibs;
    }

    IGraphicLibPtr Core::getCurrentGraphicLib() const
    {
        return _graphicLibs->at(_currentLib);
    }

    IGameLibPtr Core::getCurrentGameLib() const
    {
        return _gamesLibs->at(_currentGame);
    }

    void Core::setCurrentGraphicLib(int index)
    {
        _currentLib = index;
    }

    void Core::setCurrentGameLib(int index)
    {
        _currentGame = index;
    }

    void Core::switchGraphicLib()
    {
        stopGraphic();
        if (_currentLib == _graphicLibs->size() - 1)
            _currentLib = 0;
        else
            _currentLib++;
        startGraphic();
    }

    void Core::switchGameLib()
    {
        if (_currentGame == _gamesLibs->size() - 1)
            _currentGame = 0;
        else
            _currentGame++;
    }

    void Core::startGraphic()
    {
        getCurrentGraphicLib()->setWindow(_windowsParameter);
        getCurrentGraphicLib()->loadObjects(_gameObjects);
        getCurrentGraphicLib()->openWindow();
    }

    void Core::stopGraphic()
    {
        getCurrentGraphicLib()->closeWindow();
    }

    bool Core::isRunning() const
    {
        return _isRunning;
    }

    void Core::setRunning(bool isRunning)
    {
        _isRunning = isRunning;
    }
}