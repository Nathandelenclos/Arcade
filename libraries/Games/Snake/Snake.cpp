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
        apple = APPLE;
        _applePos = pos_t{14, 18};

        _apple = std::make_shared<Entity>(_applePos, apple, "apple", color_t {255, 255, 255, 255},rect_t{0, 0, 29, 28}, true);
        _head = std::make_shared<Entity>(pos_t{3, 5}, directions[3]._head, color_t{255, 255, 255, 255}, true);
        _tail = std::make_shared<Entity>(pos_t{2, 5}, directions[3]._tail, color_t{255, 255, 255, 255}, true);
        _body = std::make_shared<EntityVector>();
        _currentDirection = EDirection::RIGHT;
    }

    EntityPtr Snake::getApple() const
    {
        return _apple;
    }

    EntityPtr Snake::getHead() const
    {
        return _head;
    }

    EntityPtr Snake::getTail() const
    {
        return _tail;
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
        _currentHeadPos = _head->getPos();
        switch (direction)
        {
            case EDirection::UP:
                _currentHeadPos.y -= 1;
                break;
            case EDirection::DOWN:
                _currentHeadPos.y += 1;
                break;
            case EDirection::LEFT:
                _currentHeadPos.x -= 1;
                break;
            case EDirection::RIGHT:
                _currentHeadPos.x += 1;
                break;
        }
        _head->setPos(_currentHeadPos);

        _currentTailPos = _tail->getPos();
        if (_tail->getSprite() == SNAKE_UP)
                _currentTailPos.y -= 1;
        if (_tail->getSprite() == SNAKE_DOWN)
                _currentTailPos.y += 1;
        if (_tail->getSprite() == SNAKE_LEFT)
                _currentTailPos.x -= 1;
        if (_tail->getSprite() == SNAKE_RIGHT)
                _currentTailPos.x += 1;
        _tail->setPos(_currentTailPos);

        for (direction_t dir : directions) {
            if (dir.direction == direction) {
                _head->setSprite(dir._head.sprite);
                _head->setRect(dir._head.rect);
                _tail->setSprite(dir._tail.sprite);
                _tail->setRect(dir._tail.rect);
                break;
            }
        }
    }

    void Snake::movement()
    {
        if (_head->getSprite() == SNAKE_UP && _tail->getSprite() == SNAKE_UP) {
            _head->setPos(pos_t{_head->getPos().x, static_cast<float>(_head->getPos().y - 0.1)});
            _tail->setPos(pos_t{_tail->getPos().x, static_cast<float>(_tail->getPos().y - 0.1)});
        } else if (_head->getSprite() == SNAKE_DOWN && _tail->getSprite() == SNAKE_DOWN) {
            _head->setPos(pos_t{_head->getPos().x, static_cast<float>(_head->getPos().y + 0.1)});
            _tail->setPos(pos_t{_tail->getPos().x, static_cast<float>(_tail->getPos().y + 0.1)});
        } else if (_head->getSprite() == SNAKE_LEFT && _tail->getSprite() == SNAKE_LEFT) {
            _head->setPos(pos_t{static_cast<float>(_head->getPos().x - 0.1), _head->getPos().y});
            _tail->setPos(pos_t{static_cast<float>(_tail->getPos().x - 0.1), _tail->getPos().y});
        } else if (_head->getSprite() == SNAKE_RIGHT && _tail->getSprite() == SNAKE_RIGHT) {
            _head->setPos(pos_t{static_cast<float>(_head->getPos().x + 0.1), _head->getPos().y});
            _tail->setPos(pos_t{static_cast<float>(_tail->getPos().x + 0.1), _tail->getPos().y});
        }
    }

    void Snake::mapBorder()
    {
        if (_head->getPos().x < 2 || _head->getPos().x > 46)
            exit(84);
        if (_head->getPos().y < 5 || _head->getPos().y > 43)
            exit(84);
    }

    bool Snake::checkCollision()
    {
        if (comparePos(_head->getPos(), _apple->getPos()))
            return (true);
        return (false);
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

    bool Snake::comparePos(const pos_t &pos1, const pos_t &pos2)
    {
        if (_head->getSprite() == SNAKE_UP && _tail->getSprite() == SNAKE_UP) {
            if (pos1.x <= pos2.x + (28 / 50.0) && pos1.x + (100 / 50.0) >= pos2.x + (28 / 50.0)
                && pos1.y <= pos2.y + (29 / 50.0) && pos1.y + (100 / 50.0) >= pos2.y + (29 / 50.0))
                return (true);
        }
        if (_head->getSprite() == SNAKE_DOWN && _tail->getSprite() == SNAKE_DOWN) {
            if (pos1.x <= pos2.x + (28 / 50.0) && pos1.x + (100 / 50.0) >= pos2.x + (28 / 50.0)
            && pos1.y <= pos2.y + (29 / 50.0) && pos1.y + (184 / 50.0) >= pos2.y + (29 / 50.0))
                return (true);
        }
        if (_head->getSprite() == SNAKE_RIGHT && _tail->getSprite() == SNAKE_RIGHT) {
            if (pos1.x <= pos2.x + (28 / 50.0) && pos1.x + (130 / 50.0) >= pos2.x + (28/ 50.0)
            && pos1.y <= pos2.y + (29 / 50.0) && pos1.y + (100 / 50.0) >= pos2.y + (29 / 50.0))
                return (true);
        }
        if (_head->getSprite() == SNAKE_LEFT && _tail->getSprite() == SNAKE_LEFT) {
            if (pos1.x <= pos2.x + (28 / 50.0) && pos1.x + (100 / 50.0) >= pos2.x + (28 / 50.0)
            && pos1.y < pos2.y + (29 / 50.0) && pos1.y + (100 / 50.0) >= pos2.y + (29 / 50.0))
                return (true);
        }
        return (false);
    }

    void Snake::addBody(IObjectVector &object)
    {
        _body_hor = SNAKE_BODY_HOR;
        EntityPtr body = std::make_shared<Entity>(pos_t{_currentTailPos.x, _currentTailPos.y}, _body_hor, "body_hor", color_t {255, 255, 255, 255}, rect_t {0, 0, 56, 56}, true);
        _body->push_back(body);
        object->push_back(body);
    }

}