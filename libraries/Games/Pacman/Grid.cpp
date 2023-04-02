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
        _pacmanPos = {10, 10};
        _pacman = std::make_shared<Entity>(_pacmanPos, color_t{255, 255, 0, 255}, rect_t{0, 0, 0.5, 1});
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
                    EntityPtr entity = std::make_shared<Entity>(pos, color_t {0, 0, 255, 255}, rect_t{0, 0, 1, 1});
                    _map.push_back(entity);
                }
                if (c == '.') {
                    pos_t pos = {(float)i, (float)j};
                    EntityPtr entity = std::make_shared<Entity>(pos, color_t {255, 255, 255, 255}, rect_t{0, 0, 1, 1});
                    _map.push_back(entity);
                }
                if (c == 'o') {
                    pos_t pos = {(float)i, (float)j};
                    EntityPtr entity = std::make_shared<Entity>(pos, color_t {255, 255, 0, 255}, rect_t{0, 0, 1, 1});
                    _map.push_back(entity);
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

}
