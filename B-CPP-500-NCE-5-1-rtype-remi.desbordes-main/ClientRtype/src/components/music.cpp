#include "music.hpp"

component::Music::Music(std::string music_path, bool loop)
{
    _music.openFromFile(music_path);
}

void component::Music::play_music(void)
{
    _music.play();
}

void component::Music::set_volume(int v)
{
    _music.setVolume(v);
}

void component::Music::volume_up(void)
{
    _music.setVolume(_music.getVolume() + 10);
}

void component::Music::volume_down(void)
{
    _music.setVolume(_music.getVolume() - 10);
}

int component::Music::get_volume(void)
{
    return _music.getVolume();
}
