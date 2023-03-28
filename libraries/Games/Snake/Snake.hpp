/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once

#include "Entity.hpp"

#define APPLE "./assets/sprites/snake_game/apple.png"

#define SNAKE_UP "./assets/sprites/snake_game/snakkel_UP.png"
#define SNAKE_DOWN "./assets/sprites/snake_game/snakkel_DOWN.png"
#define SNAKE_LEFT "./assets/sprites/snake_game/snakkel_LEFT.png"
#define SNAKE_RIGHT "./assets/sprites/snake_game/snakkel_RIGHT.png"


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


    static const direction_t directions[] = {
            {EDirection::UP, sprite_t {
                SNAKE_UP,rect_t{0, 0, 56, 56}
                }, sprite_t{
                SNAKE_UP,rect_t{0, 120, 56, 184}
            }},
            {EDirection::DOWN, sprite_t{
                SNAKE_DOWN, rect_t{0, 110, 56, 184}
                }, sprite_t {
                SNAKE_DOWN, rect_t{0, 0, 56, 56}
            }},
            {EDirection::LEFT, sprite_t {
                SNAKE_LEFT, rect_t{0, 0, 65, 56}
                }, sprite_t {
                SNAKE_LEFT, rect_t{145, 0, 184, 56}
            }},
            {EDirection::RIGHT, sprite_t {
                SNAKE_RIGHT, rect_t{120, 0, 184, 56}
                }, sprite_t {
                SNAKE_RIGHT, rect_t{0, 0, 39, 56}
            }}
    };

    class Snake {
        public:
            Snake();
            ~Snake() = default;

            EntityPtr getApple() const;
            EntityPtr getHead() const;
            EntityPtr getTail() const;

            void changeDirection(EDirection direction);
            void movement();
            void mapBorder();

            bool checkCollision();

            void placeApple();
            static bool comparePos(const pos_t &pos1, const pos_t &pos2);

        protected:
            direction_t snakkel_up;
            direction_t snakkel_down;
            direction_t snakkel_left;
            direction_t snakkel_right;
            std::string apple;
            std::string map;
        private:
            EntityPtr _apple;
            EntityPtr _head;
            EntityVectorPtr _body;
            EntityPtr _tail;
            EDirection _currentDirection;
            pos_t _applePos;
            pos_t _currentHeadPos;
            pos_t _currentTailPos;

    };

    typedef std::shared_ptr<Snake> SnakePtr;
}