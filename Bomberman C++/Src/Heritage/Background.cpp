/*
** EPITECH PROJECT, 2022
** Background.cpp
** File description:
** Background file for Indie Studio.
*/

#include "../Include/Heritage/Background.hpp"

Background::Background(float pos_x, float pos_y, const std::string& path ) : _x(pos_x), _y(pos_y)
{
    _color = RAYWHITE;
    _texture = LoadTexture(path.c_str());
}

void Background::draw()
{
    DrawTexture(_texture, _x, _y, _color);
}

void Background::update()
{
}
