#include "music.hpp"

component::Music::Music(std::string music_path, bool loop)
{
    _music.openFromFile(music_path);
}

/*sf::Music component::Music::get_music(void) const
{
    return _music;
}*/

void component::Music::play_music(void)
{
    _music.play();
}

