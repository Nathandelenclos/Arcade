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
                    _map.push_back(GenericEntity::generateEntity(EntityType::WALL, pos));
                }
                if (c == '.') {
                    pos_t pos = {(float)i, (float)j};
                    _map.push_back(GenericEntity::generateEntity(EntityType::FRUIT, pos));
                }
                if (c == 'o') {
                    pos_t pos = {(float)i, (float)j};
                    _map.push_back(GenericEntity::generateEntity(EntityType::ENERGIZER, pos));
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
        switch (_currentDirection) {
            case EDirection::UP:
                _pacmanPos.y -= 0.6;
                break;
            case EDirection::DOWN:
                _pacmanPos.y += 0.6;
                break;
            case EDirection::LEFT:
                _pacmanPos.x -= 0.6;
                break;
            case EDirection::RIGHT:
                _pacmanPos.x += 0.6;
                break;
            default:
                break;
        }
        _pacman->setPos(_pacmanPos);
    }

    void Grid::changeDirection(EDirection direction) {
        if (_currentDirection == direction)
            return;
        if (_currentDirection == EDirection::UP && direction == EDirection::DOWN ||
            _currentDirection == EDirection::DOWN && direction == EDirection::UP ||
            _currentDirection == EDirection::LEFT && direction == EDirection::RIGHT ||
            _currentDirection == EDirection::RIGHT && direction == EDirection::LEFT)
            return;
        _currentDirection = direction;
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
        return std::make_shared<Entity>(pos, color_t {209, 198, 139, 255}, rect_t{0, 0, 0.6, 0.6});
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
