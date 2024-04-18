/*
** EPITECH PROJECT, 2022
** ISound.hpp
** File description:
** ISound class for Indie Studio.
*/

#include "raylib.h"
#include <string>

#ifndef _IAUDIO_HPP_
#define _IAUDIO_HPP_

class IAudio {
    public:
        virtual void init_audio() = 0;
        virtual void play_audio() = 0;
        virtual void stop_audio() = 0;
        virtual void update_audio() = 0;
        virtual void set_volume(float _sound) = 0;
};

#endif