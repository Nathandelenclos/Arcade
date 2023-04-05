/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"

namespace Arcade {

    /**
     * @brief Construct a new Pacman:: Pacman object
     */
    Pacman::Pacman()
    {
        _gameObjects = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _gameObjectsToWin = std::make_shared<std::vector<std::shared_ptr<IObject>>>();
        _currentKey = InputKey::NONE;
        _isEnded = false;
        _score = 0;
        _grid = std::make_shared<Grid>();
        _mapEntities = _grid->getMap();
        for (const EntityPtr& entity : _mapEntities) {
            _gameObjects->push_back(entity);
        }
    }

    /**
     * @brief Destroy the Pacman:: Pacman object
     */
    Pacman::~Pacman()
    {
    }

    /**
     * @brief Set the Game Objects object
     */
    void Pacman::setGameObjects()
    {

    }

    /**
     * @brief Get the Game Objects object
     * @return IObjectVector
     */
    IObjectVector Pacman::getGameObjects()
    {
        return _gameObjects;
    }

    /**
     * @brief Update the Game Objects object
     */
    void Pacman::updateGameObjects()
    {
        runPacman();
    }

    /**
     * @brief Check if the game is ended
     * @return true
     * @return false
     */
    bool Pacman::isEnded()
    {
        return _isEnded;
    }

    /**
     * @brief Set the Current Input Key object
     * @param key
     */
    void Pacman::setCurrentInputKey(InputKey key)
    {
        _currentKey = key;
    }

    /**
     * @brief Get the Score object
     * @return int
     */
    int Pacman::getScore()
    {
        return _score;
    }

    /**
     * @brief Run the Pacman game
     */
    void Pacman::runPacman()
    {
        for (key_direction_t keyDirection : key_direction) {
            if (keyDirection.key == _currentKey) {
                _grid->changeDirection(keyDirection.direction);
                break;
            }
        }
        _grid->movePacman();
        _gameObjects->clear();
        _mapEntities = _grid->getMap();
        for (const EntityPtr& entity : _mapEntities) {
            _gameObjects->push_back(entity);
        }
    }

    /**
     * @brief Construct a new Pacman:: Pacman object
     */
    extern "C" IGameLib *constructor_game()
    {
        return new Pacman();
    }
}
