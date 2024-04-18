/*
** EPITECH PROJECT, 2022
** Music.hpp
** File description:
** Music class for Indie Studio.
*/

#include "../Include/VirtualClass/IAudio.hpp"

#ifndef _MUSIC_HPP_
#define _MUSIC_HPP_

class Music_G : IAudio {
    public:
        Music_G(float volume, const std::string& path);
        ~Music_G() {};
        void init_audio() override;
        void play_audio() override;
        void stop_audio() override;
        void update_audio() override;
        void set_volume(float _sound) override;
    private:
        Music _music;
        float _volume;
};

#endif