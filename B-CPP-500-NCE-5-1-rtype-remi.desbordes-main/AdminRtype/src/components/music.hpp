#pragma once

#include "../system/ISystem.hpp"

namespace component
{
    class Music
    {
        public:
            Music(std::string music_path, bool loop);
            ~Music() {};
            //sf::Music get_music(void) const;
            void play_music();
            //sf::SoundSource::Status get_status(void);
            //void change_music(std::string new_music);
        private:
            sf::Music _music;
    };
};