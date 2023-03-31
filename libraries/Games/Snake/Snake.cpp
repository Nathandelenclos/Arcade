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
        _applePos = pos_t{14, 18};

        this->_body = std::make_shared<EntityVector>();
        this->_currentDirection = EDirection::RIGHT;
        _apple = std::make_shared<Entity>(_applePos, color_t {0, 255, 255, 255},rect_t{0, 0, 1, 2});
    }

    EntityPtr Snake::getApple() const
    {
        return _apple;
    }

    void Snake::movement()
    {
        int j = 0;
        _queuePos.push_back(_body->at(0)->getPos());
        switch (this->_currentDirection) {
            case EDirection::UP:
                this->_body->at(0)->setPos(pos_t{this->_body->at(0)->getPos().x, static_cast<float>(this->_body->at(0)->getPos().y - 0.02)});
                break;
            case EDirection::DOWN:
                this->_body->at(0)->setPos(pos_t{this->_body->at(0)->getPos().x, static_cast<float>(this->_body->at(0)->getPos().y + 0.02)});
                break;
            case EDirection::LEFT:
                this->_body->at(0)->setPos(pos_t{static_cast<float>(this->_body->at(0)->getPos().x - 0.01), this->_body->at(0)->getPos().y});
                break;
            case EDirection::RIGHT:
                this->_body->at(0)->setPos(pos_t{static_cast<float>(this->_body->at(0)->getPos().x + 0.01), this->_body->at(0)->getPos().y});
                break;
        }
    }

    void Snake::placeApple()
    {
        srand((unsigned) time(nullptr));
        float oldAppleX = rand() % (44 - 2 + 1) + 2;
        float oldAppleY = rand() % (38 - 5 + 1) + 5;
        pos_t oldApplePos{oldAppleX, oldAppleY};
        _apple->setPos(oldApplePos);

        float newAppleX = rand() % (44 - 2 + 1) + 2;
        float newAppleY = rand() % (38 - 5 + 1) + 5;
        pos_t newApplePos{newAppleX, newAppleY};
        _apple->setPos(newApplePos);
    }

    bool Snake::comparePos(const EntityPtr& a, const EntityPtr& b)
    {
        if ((a->getPos().x >= b->getPos().x && a->getPos().x <= b->getPos().x + b->getRect().width && a->getPos().y >= b->getPos().y && a->getPos().y <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x + a->getRect().width >= b->getPos().x && a->getPos().x + a->getRect().width <= b->getPos().x + b->getRect().width && a->getPos().y >= b->getPos().y && a->getPos().y <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x >= b->getPos().x && a->getPos().x <= b->getPos().x + b->getRect().width && a->getPos().y + a->getRect().height >= b->getPos().y && a->getPos().y + a->getRect().height <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x + a->getRect().width >= b->getPos().x && a->getPos().x + a->getRect().width <= b->getPos().x + b->getRect().width && a->getPos().y + a->getRect().height >= b->getPos().y && a->getPos().y + a->getRect().height <= b->getPos().y + b->getRect().height))
            return (true);
        return (false);
    }

    void Snake::addBody(IObjectVector &object)
    {
        EntityPtr bodyPart = std::make_shared<Entity>(this->_body->empty() ? pos_t{25, 25} : pos_t{
                this->_body->at(this->_body->size() - 1)->getPos().x - 2, this->_body->at(this->_body->size() - 1)->getPos().y}, this->_body->empty() ? color_t{255, 0, 255, 255} : color_t{255, 255, 0, 255}, rect_t{0, 0, 1, 2});
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
        pos_t _currentHeadPos = _body->at(0)->getPos();
        switch (direction)
        {
            case EDirection::UP:
                _currentHeadPos.y -= 0.05;
                break;
            case EDirection::DOWN:
                _currentHeadPos.y += 0.05;
                break;
            case EDirection::LEFT:
                _currentHeadPos.x -= 0.05;
                break;
            case EDirection::RIGHT:
                _currentHeadPos.x += 0.05;
                break;
        }
        _body->at(0)->setPos(_currentHeadPos);

    }

    bool Snake::checkCollision()
    {
        if (comparePos(_body->at(0), _apple))
            return (true);
        return (false);
    }

}