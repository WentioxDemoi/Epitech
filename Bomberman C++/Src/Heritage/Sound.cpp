/*
** EPITECH PROJECT, 2022
** Sound.cpp
** File description:
** Sound file for Indie Studio.
*/

#include "../Include/Heritage/Sound.hpp"

Sound_G::Sound_G(float volume, const std::string& path) : _volume(volume)
{
    _sound = LoadSound(path.c_str());
    SetSoundVolume(_sound, _volume);
}

void Sound_G::play_audio()
{
    PlaySoundMulti(_sound);
}

void Sound_G::set_volume(float _sounder)
{
    SetSoundVolume(_sound, _sounder);
}

void Sound_G::stop_audio()
{
    StopSound(_sound);
}
