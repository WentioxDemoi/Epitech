#pragma once

#include "../system/ISystem.hpp"

namespace component
{
    class Sprite
    {
        public:
            Sprite(std::string spritepath, float x, float y, float s);
            ~Sprite() {};
            sf::Sprite get_spr(void) const;
            sf::Vector2f get_pos(void) const;
            sf::Vector2f get_move(void) const;
            void set_pos(float x, float y);
            void update_pos(sf::Vector2f n_pos);
            void update_move(sf::Vector2f n_move);
            void update_texture(std::string sprite_path);
            void change_texture(sf::Texture t);
            void set_scale(float s_x, float s_y);
            void set_rotation(int r);
            void set_origin(float o_x, float o_y);
            std::string get_spritepath(void) const;
            sf::Vector2f get_size(void) const;
            void set_color(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha_transparency);
        private:
            std::string _spritepath;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Vector2f _pos;
            sf::Vector2f _size;
            float _scale;
    };
}