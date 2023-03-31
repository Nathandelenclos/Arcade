/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once

#include "Entity.hpp"
#include "Types.hpp"
#include "csignal"

#define APPLE "./assets/sprites/snake_game/apple.png"

#define SNAKE_UP "./assets/sprites/snake_game/snakkel_UP.png"
#define SNAKE_DOWN "./assets/sprites/snake_game/snakkel_DOWN.png"
#define SNAKE_LEFT "./assets/sprites/snake_game/snakkel_LEFT.png"
#define SNAKE_RIGHT "./assets/sprites/snake_game/snakkel_RIGHT.png"

#define SNAKE_BODY_HOR "./assets/sprites/snake_game/snakkel_body_hor.png"
#define SNAKE_BODY_VER "./assets/sprites/snake_game/snakkel_body_ver.png"


namespace Arcade {

    enum class EDirection {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };


    typedef struct {
        EDirection direction;
        sprite_t _head;
        sprite_t _tail;
    } direction_t;


    class Snake {
        public:
            Snake();
            ~Snake() = default;

            EntityPtr getApple() const;
            EntityPtr getBodyPart(int index) const;
            void movement();
            bool checkCollision();
            void placeApple();
            bool comparePos(const EntityPtr& a, const EntityPtr& b);
            void addBody(IObjectVector &object);
            void changeDirection(EDirection direction);
        protected:
            direction_t direction;
            std::string apple;
            std::string map;
        private:
            EntityPtr _apple;
            EntityVectorPtr _body;
            EntityPtr _head;
            EDirection _currentDirection;
            pos_t _applePos;
            std::vector<pos_t> _queuePos;
    };

    typedef std::shared_ptr<Snake> SnakePtr;
}