/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** Object.cpp
*/

#pragma once

#include "SFML/Graphics.hpp"

namespace Arcade {
    namespace sfml {
        class IObject {
            public:
                virtual ~IObject() = default;
                virtual sf::Drawable *getDrawable() = 0;
            protected:
            private:
        };
        typedef std::shared_ptr<IObject> IObjectPtr;
        typedef std::vector<IObjectPtr> IObjectVector;
        typedef std::shared_ptr<IObjectVector> IObjectVectorPtr;
    }
}