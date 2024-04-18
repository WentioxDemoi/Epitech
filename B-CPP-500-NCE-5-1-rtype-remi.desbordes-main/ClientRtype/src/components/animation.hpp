#pragma once

#include "../Entity.hpp"

namespace component
{
    class Animation
    {
        public:
            Animation(std::string dir_path, int max_frame);
            ~Animation() {};
            void animate(Entity e);
        private:
            std::vector<sf::Texture> _animation_frame;
            int _cur_frame;
            int _max_frame;
            sf::Texture t;
    };
};