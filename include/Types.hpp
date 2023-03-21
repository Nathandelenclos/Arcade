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
#include "IObject.hpp"

namespace Arcade {

    class IGraphicLib;
    class IGameLib;

    typedef std::shared_ptr<std::vector<std::shared_ptr<IObject>>> IObjectVector;
    typedef std::shared_ptr<IObject> IObjectPtr;
    typedef std::shared_ptr<Arcade::IGraphicLib> IGraphicLibPtr;
    typedef std::shared_ptr<Arcade::IGameLib> IGameLibPtr;

    typedef std::shared_ptr<IText> ITextPtr;
    typedef std::shared_ptr<IEntities> IEntitiesPtr;
    typedef std::vector<ITextPtr> ITextVector;
    typedef std::vector<IEntitiesPtr> IEntitiesVector;
    typedef std::shared_ptr<ITextVector> ITextVectorPtr;
    typedef std::shared_ptr<IEntitiesVector> IEntitiesVectorPtr;
} // Arcade

#endif //ARCADE_TYPES_HPP