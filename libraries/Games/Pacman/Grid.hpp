/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Grid.hpp
*/

#pragma once

#include "IObject.hpp"

namespace Arcade {

    enum class EDirection {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

    enum class EntityType {
        WALL,
        GHOST,
        PACMAN,
        COIN,
        POWERUP,
        EMPTY
    };

    class Grid {
    public:
        Grid(int width, int height);
        ~Grid() = default;

        void setEntity(int x, int y, EntityType type);
        EntityType getEntity(int x, int y) const;

        void init();
        void display();
        bool isWall(int x, int y) const;
        bool isEntity(int x, int y) const;

        void movePacman(int x, int y);
        void moveGhost(int ghostIndex, int x, int y);

        bool checkCollision(int x, int y) const;

    protected:
        int _width;
        int _height;
        std::vector<EntityType> _grid;
    private:
    };

    typedef std::shared_ptr<Grid> GridPtr;

} // Arcade