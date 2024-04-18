#include "animation.hpp"
#include "sprite.hpp"
#include <dirent.h>

component::Animation::Animation(std::string dir_path, int max_frame)
{
    _cur_frame = 0;
    _max_frame = max_frame;

    for (int i = 0; i != _max_frame; i++) {
        std::string cur_frame_str = std::to_string(i + 1);
        if (!t.loadFromFile(dir_path + cur_frame_str + ".png"))
            return;
        _animation_frame.push_back(t);
    }
}

void component::Animation::animate(Entity e)
{
    _cur_frame++;
    if (_cur_frame >= _max_frame)
        _cur_frame = 0;
    e.get<component::Sprite>().change_texture(_animation_frame[_cur_frame]);
}