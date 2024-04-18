#include "animation.hpp"
#include "sprite.hpp"
#include <dirent.h>

component::Animation::Animation(std::string dir_path, int max_frame)
{
    _dir_path = dir_path;
    _cur_frame = 1;
    _max_frame = max_frame;
}

void component::Animation::animate(Entity e)
{
    _cur_frame++;
    if (_cur_frame >= _max_frame)
        _cur_frame = 1;
    std::string n = std::to_string(_cur_frame);
    e.get<component::Sprite>().update_texture(_dir_path + n + ".png");
}