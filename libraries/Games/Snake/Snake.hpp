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
#include "Text.hpp"

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
        float x;
        float y;
    } dir_t;

    typedef struct {
        EDirection direction;
        sprite_t _head;
        sprite_t _tail;
    } direction_t;

    typedef std::vector<dir_t> dirVector;
    typedef std::shared_ptr<dirVector> dirVectorPtr;

    class Snake {
        public:
            Snake();
            ~Snake() = default;

            EntityPtr getApple() const;
            EntityPtr getBodyPart(int index) const;
            void movement();
            bool checkCollision();
            void placeApple();
            void createWalls();
            bool checkWallCollision();
            bool comparePos(const EntityPtr& a, const EntityPtr& b);
            void addBody(IObjectVector &object);
            void changeDirection(EDirection direction);
            EntityPtr getWalls(int index) const;
            dirVectorPtr getDirection() const;
            void setDirection(dir_t dir, int index);
            EntityVectorPtr getBody() const;
        protected:
            direction_t direction;
            std::string apple;
            std::string map;
        private:
            EntityPtr _apple;
            TextPtr _scoreString;
            TextPtr _score;
            EntityVectorPtr _body;
            EntityVectorPtr _walls;
            EntityPtr _head;
            EDirection _currentDirection;
            dirVectorPtr _direction;
            pos_t _applePos;
            std::vector<pos_t> _queuePos;
    };

    typedef std::shared_ptr<Snake> SnakePtr;
}