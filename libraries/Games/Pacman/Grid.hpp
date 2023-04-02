/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Grid.hpp
*/

#pragma once

#include "Entity.hpp"

#define PACMAN_SPRITE "./assets/sprites/pacman_game/pacman.png"
#define PACMAN_UP "./assets/sprites/pacman_game/pacman_up.png"
#define PACMAN_DOWN "./assets/sprites/pacman_game/pacman_down.png"
#define PACMAN_LEFT "./assets/sprites/pacman_game/pacman_left.png"
#define PACMAN_RIGHT "./assets/sprites/pacman_game/pacman_right.png"

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
        PACMAN,
        GHOST,
        ENERGIZER,
        FRUIT,
        NONE
    };

    class Grid {
    public:
        Grid();
        ~Grid() = default;

        EntityVector getMap();
        EntityPtr getPacman();

        void changeDirection(EDirection direction);

        void movePacman();

    protected:
        EntityVector _map;
        std::string _pacmanSprite;
        EntityPtr _pacman;
        pos_t _pacmanPos;
    private:

        EDirection _currentDirection;
    };

    typedef std::shared_ptr<Grid> GridPtr;

} // Arcade