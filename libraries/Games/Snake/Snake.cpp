/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

namespace Arcade {

    Snake::Snake()
    {
        this->_body = std::make_shared<EntityVector>();
        this->_walls = std::make_shared<EntityVector>();
        this->_direction = std::make_shared<dirVector>();
        this->_currentDirection = EDirection::RIGHT;
        _apple = std::make_shared<Entity>(_applePos, color_t {0, 255, 255, 255},rect_t{0, 0, 1, 2});
        this->placeApple();
    }

    EntityPtr Snake::getApple() const
    {
        return _apple;
    }

    void Snake::movement()
    {
        switch (this->_currentDirection) {
            case EDirection::UP:
                this->setDirection(dir_t{0, -0.6}, 0);
                break;
            case EDirection::DOWN:
                this->setDirection(dir_t{0, 0.6}, 0);
                break;
            case EDirection::LEFT:
                this->setDirection(dir_t{-0.3, 0}, 0);
                break;
            case EDirection::RIGHT:
                this->setDirection(dir_t{0.3, 0}, 0);
                break;
        }
        for (int i = this->_body->size() - 1; i > 0; i--) {
            this->setDirection(this->getDirection()->at(i - 1), i);
            pos_t newPos = {this->_body->at(i - 1)->getPos().x,
                            this->_body->at(i - 1)->getPos().y};
            this->_body->at(i)->setPos(newPos);
        }
        pos_t headPos = this->_body->at(0)->getPos();
        headPos.x += this->getDirection()->at(0).x;
        headPos.y += this->getDirection()->at(0).y;
        this->_body->at(0)->setPos(headPos);
    }



    void Snake::placeApple()
    {
        EntityPtr tmpApple = std::make_shared<Entity>(pos_t{0, 0}, color_t {0, 255, 255, 0},rect_t{0, 0, 1, 2});
        srand(static_cast<unsigned int>(time(nullptr)));
        float newAppleX = rand() % (21 - 2 + 1) + 2;
        float newAppleY = rand() % (42 - 5 + 1) + 5;
        tmpApple->setPos({newAppleX, newAppleY});
        for (int i = 1; i < _body->size(); i++)
            if (comparePos(_body->at(i), tmpApple)) {
                newAppleX = rand() % (21 - 2 + 1) + 2;
                newAppleY = rand() % (42 - 5 + 1) + 5;
                tmpApple->setPos({newAppleX, newAppleY});
                i = 1;
            }
        _apple->setPos(tmpApple->getPos());
    }

    bool Snake::comparePos(const EntityPtr& a, const EntityPtr& b)
    {
        if ((a->getPos().x >= b->getPos().x && a->getPos().x <= b->getPos().x + b->getRect().width && a->getPos().y >= b->getPos().y && a->getPos().y <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x + a->getRect().width >= b->getPos().x && a->getPos().x + a->getRect().width <= b->getPos().x + b->getRect().width && a->getPos().y >= b->getPos().y && a->getPos().y <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x >= b->getPos().x && a->getPos().x <= b->getPos().x + b->getRect().width && a->getPos().y + a->getRect().height >= b->getPos().y && a->getPos().y + a->getRect().height <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x + a->getRect().width >= b->getPos().x && a->getPos().x + a->getRect().width <= b->getPos().x + b->getRect().width && a->getPos().y + a->getRect().height >= b->getPos().y && a->getPos().y + a->getRect().height <= b->getPos().y + b->getRect().height)) {
            return (true);
        }
        return (false);
    }

    void Snake::addBody(IObjectVector &object)
    {
        EntityPtr bodyPart = std::make_shared<Entity>(this->_body->empty() ? pos_t{11, 22} : pos_t{
                this->_body->at(this->_body->size() - 1)->getPos().x - this->_direction->at(this->_body->size() - 1).x,
                this->_body->at(this->_body->size() - 1)->getPos().y - this->_direction->at(this->_body->size() - 1).y},
                this->_body->empty() ? color_t{255, 0, 255, 255} : color_t{255, 255, 0, 255}, rect_t{0, 0, 1, 2});
        this->_direction->push_back(dir_t{0.5, 0});
        this->_body->push_back(bodyPart);
        object->push_back(bodyPart);
    }

    EntityPtr Snake::getBodyPart(int index) const {
        if (index < this->_body->size()) {
            return this->_body->at(index);
        }
        return nullptr;
    }

    void Snake::changeDirection(EDirection direction)
    {
        if (_currentDirection == direction)
            return;
        if (_currentDirection == EDirection::UP && direction == EDirection::DOWN ||
            _currentDirection == EDirection::DOWN && direction == EDirection::UP ||
            _currentDirection == EDirection::LEFT && direction == EDirection::RIGHT ||
            _currentDirection == EDirection::RIGHT && direction == EDirection::LEFT)
            return;

        _currentDirection = direction;

    }

    bool Snake::checkCollision()
    {
        if (comparePos(_body->at(0), _apple))
            return (true);
        return (false);
    }

    bool Snake::checkWallCollision()
    {
        for (int i = 0; i < _walls->size(); i++)
            if (comparePos(_body->at(0), _walls->at(i)))
                return (true);
        return (false);
    }

    void Snake::createWalls() {
            EntityPtr wall1 = std::make_shared<Entity>(pos_t{0, 0}, color_t{155, 155, 155, 255}, rect_t{0, 0, 1, 44});
            this->_walls->push_back(wall1);
            EntityPtr wall2 = std::make_shared<Entity>(pos_t{0, 0}, color_t{155, 155, 155, 255}, rect_t{0, 0, 22, 2});
            this->_walls->push_back(wall2);
            EntityPtr wall3 = std::make_shared<Entity>(pos_t{22, 0}, color_t{155, 155, 155, 255}, rect_t{0, 0, 1, 46});
            this->_walls->push_back(wall3);
            EntityPtr wall4 = std::make_shared<Entity>(pos_t{0, 44}, color_t{155, 155, 155, 255}, rect_t{0, 0, 22, 2});
            this->_walls->push_back(wall4);
    }

    EntityPtr Snake::getWalls(int index) const {
        return this->_walls->at(index);
    }

    dirVectorPtr Snake::getDirection() const {
        return _direction;
    }

    void Snake::setDirection(dir_t dir, int index) {
        _direction->at(index) = dir;
    }
}
