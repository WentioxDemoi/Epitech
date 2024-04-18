#pragma once

#include "../Entity.hpp"

enum e_keys {
    k_up,
    k_down,
    k_left,
    k_right,
    k_z,
    k_s,
    k_q,
    k_d
};

namespace component
{
    class Movement
    {
        public:
            Movement();
            ~Movement() {};
            void move_x(Entity e, int dir);
            void move_y(Entity e, int dir);
            void manage_input(Entity e, std::vector<Entity> tab_e, int e_count);
        private:
            std::vector<sf::Keyboard::Key> key_tab;
            float _v;
            float _a;
    };
};