#pragma once

#include "../system/ISystem.hpp"
#include "../components/draw.hpp"
#include "../components/position.hpp"
#include "../components/sprite.hpp"
#include "../components/parallax.hpp"
#include "../components/clickable.hpp"
#include "../components/text.hpp"
#include "../components/movement.hpp"
#include "../components/collision.hpp"
#include "../components/animation.hpp"
#include "../components/shoot.hpp"
#include "../components/enemy.hpp"
#include "../components/music.hpp"

class Factory
{
    public:
        static Entity create_sprite(std::string spritepath, float x, float y, float s);
        static Entity create_parallax(std::string spritepath, float x, float y, float s, float parallax);
        static Entity create_button(std::string spritepath, std::string button_name, float x, float y, float s);
        static Entity create_text(float x, float y, unsigned int size, std::string font_path, std::string text);
        static Entity create_player(std::string spritepath, float x, float y, float s, std::string dir_path, int max_frame);
        static Entity create_enemy(std::vector<std::vector<float>> info);
        static Entity create_music(std::string music_path, bool loop);
        static Entity create_shoot(std::string spritepath);
        static Entity create_hunter_re(std::string spritepath, float x, float y, float s);
};