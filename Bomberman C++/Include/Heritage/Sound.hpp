/*
** EPITECH PROJECT, 2022
** Soudn.hpp
** File description:
** Sound class for Indie Studio.
*/

#include "../Include/VirtualClass/IAudio.hpp"

#ifndef _SOUND_HPP_
#define _SOUND_HPP_

class Sound_G : IAudio {
    public:
        Sound_G(float volume, const std::string& path);
        ~Sound_G() {};
        void init_audio() override {};
        void play_audio() override;
        void stop_audio() override;
        void update_audio() override {};
        void set_volume(float _sound) override;
    private:
        Sound _sound;
        float _volume;
};

#endif