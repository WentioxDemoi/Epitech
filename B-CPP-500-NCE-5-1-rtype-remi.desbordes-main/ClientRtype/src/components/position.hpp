#pragma once

#include "../system/ISystem.hpp"

namespace component
{
    class Position
    {
        public:
            Position(float x, float y);
            ~Position();
            void update_pos(float x, float y);
            sf::Vector2f get_pos(void) const;
        private:
            sf::Vector2f _pos;
    };
};