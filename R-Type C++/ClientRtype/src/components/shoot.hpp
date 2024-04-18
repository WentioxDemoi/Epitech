#pragma once

#include "../Entity.hpp"

namespace component
{
    class Shoot
    {
        public:
            Shoot(std::string spritepath);
            ~Shoot() {};
            void manage_input(sf::Event event, sf::Vector2f pos, sf::Vector2f size);
            void create_bullet(std::vector<float> pos);
            sf::Sprite get_sprite(void) const;
        private:
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Vector2f _pos;
            sf::Vector2f _size;
    };
};