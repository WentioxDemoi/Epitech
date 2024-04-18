#pragma once

#include "../system/ISystem.hpp"

namespace component
{
    class Music
    {
        public:
            Music(std::string music_path, bool loop);
            ~Music() {};
            void play_music(void);
            void set_volume(int v);
            void volume_up(void);
            void volume_down(void);
            int get_volume(void);
            //void change_music(std::string new_music);
        private:
            sf::Music _music;
    };
};