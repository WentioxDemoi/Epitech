/*
** EPITECH PROJECT, 2022
** Music.cpp
** File description:
** Music file for Indie Studio.
*/

#include "../Include/Heritage/Music.hpp"

Music_G::Music_G(float volume, const std::string& path) : _volume(volume)
{
    _music = LoadMusicStream(path.c_str());
    SetMusicVolume(_music, _volume);
}

void Music_G::init_audio()
{
    InitAudioDevice();
}

void Music_G::play_audio()
{
    PlayMusicStream(_music);
}

void Music_G::update_audio()
{
    UpdateMusicStream(_music);
}

void Music_G::set_volume(float _sound)
{
    SetMusicVolume(_music, _sound);
}

void Music_G::stop_audio()
{
    StopMusicStream(_music);
}