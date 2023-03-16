/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Types.hpp
*/

#ifndef ARCADE_TYPES_HPP
#define ARCADE_TYPES_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <IObject.hpp>

namespace Arcade {

    typedef std::shared_ptr<std::vector<std::shared_ptr<IObject>>> IObjectVector;

} // Arcade

#endif //ARCADE_TYPES_HPP