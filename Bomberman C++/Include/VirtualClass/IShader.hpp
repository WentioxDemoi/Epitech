/*
** EPITECH PROJECT, 2022
** IShader.hpp
** File description:
** IShader class for Indie Studio.
*/

#include "raylib.h"
#define GLSL_VERSION            330
#include <string>

#ifndef _ISHADER_HPP_
#define _ISHADER_HPP_

class IShader{
    public:
        virtual void value_shader() = 0;
        virtual void timer_shader() = 0;
        virtual void draw_shader() = 0;
        virtual void stop_shader() = 0;
};

#endif