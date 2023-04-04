/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Grid.cpp
*/

#include "Grid.hpp"

namespace Arcade {

    Grid::Grid() : _currentDirection(EDirection::NONE)
    {
        _mapString = {
                " ################### ",
                " #........#........# ",
                " #o##.###.#.###.##o# ",
                " #.................# ",
                " #.##.#.#####.#.##.# ",
                " #....#...#...#....# ",
                " ####.### # ###.#### ",
                "    #.#   0   #.#    ",
                "#####.# ##=## #.#####",
                "     .  #123#  .     ",
                "#####.# ##### #.#####",
                "    #.#       #.#    ",
                " ####.# ##### #.#### ",
                " #........#........# ",
                " #.##.###.#.###.##.# ",
                " #o.#.....P.....#.o# ",
                " ##.#.#.#####.#.#.## ",
                " #....#...#...#....# ",
                " #.######.#.######.# ",
                " #.................# ",
                " ################### "
        };
        _pacmanSpeed = 0.1;

        loadMap();
    }

    void Grid::loadMap()
    {
        for (int j = 0; j < _mapString.size(); j++) {
            std::string row = _mapString[j];
            for (int i = 0; i < row.size(); i++) {
                char c = row[i];
                if (c == '#') {
                    pos_t pos = {(float)i, (float)j};
                    _wallPos = pos;
                    _wall = GenericEntity::generateEntity(EntityType::WALL, _wallPos);
                    _map.push_back(_wall);
                }
                if (c == '.') {
                    _nbFruits++;
                    pos_t pos = {(float)i, (float)j};
                    _fruitPos = pos;
                    _fruit = GenericEntity::generateEntity(EntityType::FRUIT, _fruitPos);
                    _map.push_back(_fruit);
                }
                if (c == 'o') {
                    pos_t pos = {(float)i, (float)j};
                    _energizerPos = pos;
                    _energizer = GenericEntity::generateEntity(EntityType::ENERGIZER, _energizerPos);
                    _map.push_back(_energizer);
                }
                if (c == 'P') {
                    pos_t pos = {(float)i, (float)j};
                    _pacmanPos = pos;
                    _pacman = GenericEntity::generateEntity(EntityType::PACMAN, _pacmanPos);
                    _map.push_back(_pacman);
                }
                if (c == '=') {
                    pos_t pos = {(float)i, (float)j};
                    _doorPos = pos;
                    _door = GenericEntity::generateEntity(EntityType::DOOR, _doorPos);
                    _map.push_back(_door);
                }
            }
        }
    }

    EntityVector Grid::getMap()
    {
        return _map;
    }

    EntityPtr Grid::getPacman()
    {
        return _pacman;
    }

    void Grid::movePacman()
    {
        pos_t currentPos = _pacman->getPos();
        pos_t newPos = currentPos;
        float deltaY = 0.0;
        float deltaX = 0.0;

        switch (_currentDirection) {
            case EDirection::UP:
                deltaY = -_pacmanSpeed * 2;
                break;
            case EDirection::DOWN:
                deltaY = _pacmanSpeed * 2;
                break;
            case EDirection::LEFT:
                deltaX = -_pacmanSpeed;
                break;
            case EDirection::RIGHT:
                deltaX = _pacmanSpeed;
                break;
            default:
                break;
        }
        newPos.x += deltaX;
        newPos.y += deltaY;
        _pacman->setPos(newPos);
        int i = 0;
        for (auto &entity : _map) {
            i++;
            if (entity->getEntityType() == EntityType::WALL && comparePos(_pacman, entity) ||
                entity->getEntityType() == EntityType::DOOR && comparePos(_pacman, entity)) {
                currentPos.x -= deltaX == 0 ? 0 : 0.01;
                currentPos.y -= deltaY == 0 ? 0 : 0.01;
                _pacman->setPos(currentPos);
                _currentDirection = EDirection::NONE;
            }
        }
        for (auto it = _map.begin(); it != _map.end(); ++it) {
            if ((*it)->getEntityType() == EntityType::FRUIT && comparePos(*it, _pacman)) {
                _map.erase(it);
                _nbFruits--;
                break;
            }
            if ((*it)->getEntityType() == EntityType::ENERGIZER && comparePos(*it, _pacman)) {
                _map.erase(it);
                break;
            }
        }
        std::cout << _nbFruits << std::endl;
        if (newPos.x > 20.5019) {
            newPos.x = -0.000928198;
            newPos.y = 9.35749;
            _pacman->setPos(newPos);
            _currentDirection = EDirection::RIGHT;
        } else if (newPos.x < -0.000928198) {
            newPos.x = 20.5019;
            newPos.y = 9.35749;
            _pacman->setPos(newPos);
            _currentDirection = EDirection::LEFT;
        }
        if (_nbFruits == 0) {
            _currentDirection = EDirection::NONE;
            _pacmanSpeed += 0.1;
            for (auto &entity : _map) {
                _map.erase(_map.begin(), _map.end());
            }
            loadMap();
        }
    }

    void Grid::changeDirection(EDirection direction)
    {
        if (_currentDirection == direction)
            return;
        _currentDirection = direction;
    }

    bool Grid::comparePos(const EntityPtr& a, const EntityPtr& b)
    {
        if ((a->getPos().x >= b->getPos().x && a->getPos().x <= b->getPos().x + b->getRect().width && a->getPos().y >= b->getPos().y && a->getPos().y <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x + a->getRect().width >= b->getPos().x && a->getPos().x + a->getRect().width <= b->getPos().x + b->getRect().width && a->getPos().y >= b->getPos().y && a->getPos().y <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x >= b->getPos().x && a->getPos().x <= b->getPos().x + b->getRect().width && a->getPos().y + a->getRect().height >= b->getPos().y && a->getPos().y + a->getRect().height <= b->getPos().y + b->getRect().height) ||
            (a->getPos().x + a->getRect().width >= b->getPos().x && a->getPos().x + a->getRect().width <= b->getPos().x + b->getRect().width && a->getPos().y + a->getRect().height >= b->getPos().y && a->getPos().y + a->getRect().height <= b->getPos().y + b->getRect().height)) {
            return (true);
        }
        return (false);
    }

    EntityPtr GenericEntity::generateWall(pos_t pos)
    {
        return std::make_shared<Entity>(pos, EntityType::WALL, color_t {0, 0, 255, 255}, rect_t{0, 0, 1, 1});
    }

    EntityPtr GenericEntity::generatePacman(pos_t pos)
    {
        pos = {static_cast<float>(pos.x + 0.25), static_cast<float>(pos.y + 0.25)};
        return std::make_shared<Entity>(pos, EntityType::PACMAN, color_t {255, 255, 0, 255}, rect_t{0, 0, 0.5, 0.5});
    }

    EntityPtr GenericEntity::generateGhost(pos_t pos)
    {
        return Arcade::EntityPtr();
    }

    EntityPtr GenericEntity::generateEnergizer(pos_t pos)
    {
        pos = {static_cast<float>(pos.x + 0.25), static_cast<float>(pos.y + 0.25)};
        return std::make_shared<Entity>(pos, EntityType::ENERGIZER, color_t {209, 198, 139, 255}, rect_t{0, 0, 0.5, 0.5});
    }

    EntityPtr GenericEntity::generateFruit(pos_t pos)
    {
        pos = {static_cast<float>(pos.x + 0.30), static_cast<float>(pos.y + 0.30)};
        return std::make_shared<Entity>(pos, EntityType::FRUIT, color_t {255, 255, 255, 255}, rect_t{0, 0, 0.3, 0.3});
    }

    EntityPtr GenericEntity::generateDoor(pos_t pos)
    {
        return std::make_shared<Entity>(pos, EntityType::DOOR, color_t {64, 224, 208, 255}, rect_t{0, 0, 1, 1});
    }

    EntityPtr GenericEntity::generateEntity(EntityType type, pos_t pos)
    {
        entities_t entities[] = {
                {EntityType::WALL, &GenericEntity::generateWall},
                {EntityType::PACMAN, &GenericEntity::generatePacman},
                {EntityType::GHOST, &GenericEntity::generateGhost},
                {EntityType::ENERGIZER, &GenericEntity::generateEnergizer},
                {EntityType::FRUIT, &GenericEntity::generateFruit},
                {EntityType::DOOR, &GenericEntity::generateDoor}
        };
        GenericEntity genericEntity;
        for (auto &entity : entities) {
            if (entity.type == type)
                return (genericEntity.*entity.init)(pos);
        }
        return nullptr;
    }

}
