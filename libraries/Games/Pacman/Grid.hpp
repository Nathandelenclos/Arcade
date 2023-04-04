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

    class GenericEntity {
        public:
            GenericEntity() = default;
            ~GenericEntity() = default;
            static EntityPtr generateEntity(EntityType type, pos_t pos);
            EntityPtr generateWall(pos_t pos);
            EntityPtr generatePacman(pos_t pos);
            EntityPtr generateGhost(pos_t pos);
            EntityPtr generateEnergizer(pos_t pos);
            EntityPtr generateFruit(pos_t pos);
            EntityPtr generateDoor(pos_t pos);
    };

    typedef struct {
        EntityType type;
        EntityPtr (GenericEntity::*init)(pos_t pos);
    } entities_t;

    class Grid {
        public:
            Grid();
            ~Grid() = default;

            EntityVector getMap();
            EntityPtr getPacman();

            void changeDirection(EDirection direction);
            void movePacman();

            bool comparePos(const EntityPtr &a, const EntityPtr &b);

        protected:
            EntityVector _map;
            EntityPtr _wall;
            pos_t _wallPos;
            EntityPtr _pacman;
            pos_t _pacmanPos;
            EntityPtr _ghost;
            pos_t _ghostPos;
            EntityPtr _energizer;
            pos_t _energizerPos;
            EntityPtr _fruit;
            pos_t _fruitPos;
            EntityPtr _door;
            pos_t _doorPos;
        private:
            EDirection _currentDirection;
            int _nbFruits;
    };

    typedef std::shared_ptr<Grid> GridPtr;

} // Arcade