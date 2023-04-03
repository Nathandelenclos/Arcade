/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Grid.cpp
*/

#include "Grid.hpp"

namespace Arcade {

    Grid::Grid()
    {
        _currentDirection = EDirection::RIGHT;
        std::vector<std::string> map = {
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

        for (int j = 0; j < map.size(); j++) {
            std::string row = map[j];
            for (int i = 0; i < row.size(); i++) {
                char c = row[i];
                if (c == '#') {
                    pos_t pos = {(float)i, (float)j};
                    _wallPos = pos;
                    _wall = GenericEntity::generateEntity(EntityType::WALL, pos);
                    _map.push_back(_wall);
                }
                if (c == '.') {
                    pos_t pos = {(float)i, (float)j};
                    _fruitPos = pos;
                    _fruit = GenericEntity::generateEntity(EntityType::FRUIT, pos);
                    _map.push_back(_fruit);
                }
                if (c == 'o') {
                    pos_t pos = {(float)i, (float)j};
                    _energizerPos = pos;
                    _energizer = GenericEntity::generateEntity(EntityType::ENERGIZER, pos);
                    _map.push_back(_energizer);
                }
                if (c == 'P') {
                    pos_t pos = {(float)i, (float)j};
                    _pacmanPos = pos;
                    _pacman = GenericEntity::generateEntity(EntityType::PACMAN, pos);
                    _map.push_back(_pacman);
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
        bool canMove = true;
        pos_t currentPos = _pacman->getPos();
        pos_t newPos = currentPos;

        switch (_currentDirection) {
            case EDirection::UP:
                newPos.y -= 0.5;
                break;
            case EDirection::DOWN:
                newPos.y += 0.5;
                break;
            case EDirection::LEFT:
                newPos.x -= 0.5;
                break;
            case EDirection::RIGHT:
                newPos.x += 0.5;
                break;
            default:
                break;
        }
        for (auto &entity : _map) {
            if (static_cast<EntityType>(entity->getType()) == EntityType::WALL && entity->getPos().x == newPos.x && entity->getPos().y == newPos.y) {
                canMove = false;
                break;
            }
        }
        if (canMove)
            _pacman->setPos(newPos);
    }

    void Grid::changeDirection(EDirection direction)
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

    void Grid::checkCollision()
    {
    }

    EntityPtr GenericEntity::generateWall(pos_t pos)
    {
        return std::make_shared<Entity>(pos, color_t {0, 0, 255, 255}, rect_t{0, 0, 1, 1});;
    }

    EntityPtr GenericEntity::generatePacman(pos_t pos)
    {
        return std::make_shared<Entity>(pos, color_t {255, 255, 0, 255}, rect_t{0, 0, 0.5, 0.5});
    }

    EntityPtr GenericEntity::generateGhost(pos_t pos)
    {
        return Arcade::EntityPtr();
    }

    EntityPtr GenericEntity::generateEnergizer(pos_t pos)
    {
        pos = {static_cast<float>(pos.x + 0.25), static_cast<float>(pos.y + 0.25)};
        return std::make_shared<Entity>(pos, color_t {209, 198, 139, 255}, rect_t{0, 0, 0.5, 0.5});
    }

    EntityPtr GenericEntity::generateFruit(pos_t pos)
    {
        pos = {static_cast<float>(pos.x + 0.30), static_cast<float>(pos.y + 0.30)};
        return std::make_shared<Entity>(pos, color_t {255, 255, 255, 255}, rect_t{0, 0, 0.3, 0.3});
    }

    EntityPtr GenericEntity::generateEntity(EntityType type, pos_t pos)
    {
        entities_t entities[] = {
                {EntityType::WALL, &GenericEntity::generateWall},
                {EntityType::PACMAN, &GenericEntity::generatePacman},
                {EntityType::GHOST, &GenericEntity::generateGhost},
                {EntityType::ENERGIZER, &GenericEntity::generateEnergizer},
                {EntityType::FRUIT, &GenericEntity::generateFruit}
        };
        GenericEntity genericEntity;
        for (auto &entity : entities) {
            if (entity.type == type)
                return (genericEntity.*entity.init)(pos);
        }
    }
}
