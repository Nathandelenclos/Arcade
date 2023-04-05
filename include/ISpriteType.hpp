/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-nathan.delenclos
** File description:
** ISpriteType.hpp
*/

#pragma once

#include "IObject.hpp"

namespace Arcade {

    /**
     * @brief The Sprite type
     */
    enum SpriteType {
        BUTTON,
    };

    class ISpriteType : public IEntities {
        public:
            /**
             * @brief Destroy the ISpriteType object
             */
            ~ISpriteType() override = default;
            /**
             * @brief Get the Sprite Type object
             * @return The Sprite type
             */
            virtual SpriteType getSpriteType() = 0;
        protected:
        private:
    };

    typedef std::shared_ptr<ISpriteType> ISpriteTypePtr;
    typedef std::vector<ISpriteTypePtr> ISpriteTypeVector;
    typedef std::shared_ptr<ISpriteTypeVector> ISpriteTypeVectorPtr;
}