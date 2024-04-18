#pragma once

#include "../Entity.hpp"

namespace component
{
    class Collision
    {
        public:
            Collision() {};
            ~Collision() {};
            bool check_collision_up(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count);
            bool check_collision_down(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count);
            bool check_collision_left(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count);
            bool check_collision_right(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count);
        private:
    };
};