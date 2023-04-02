/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Grid.cpp
*/

#include "Grid.hpp"

namespace Arcade {


    Grid::Grid(int width, int height) : _width(width), _height(height)
    {
        _grid.resize(_width * _height, EntityType::EMPTY);
    }

    void Grid::setEntity(int x, int y, EntityType type)
    {
        _grid[y * _width + x] = type;
    }

    EntityType Grid::getEntity(int x, int y) const
    {
        return _grid[y * _width + x];
    }

    void Grid::init()
    {

    }

    void Grid::display()
    {

    }

    bool Grid::isWall(int x, int y) const
    {
        return getEntity(x, y) != EntityType::WALL;
    }

    bool Grid::isEntity(int x, int y) const
    {
        return getEntity(x, y) == EntityType::EMPTY;
    }

    void Grid::movePacman(int x, int y)
    {

    }

    void Grid::moveGhost(int ghostIndex, int x, int y)
    {

    }

    bool Grid::checkCollision(int x, int y) const
    {
        return getEntity(x, y) != EntityType::EMPTY;
    }
}