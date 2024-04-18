/*
** EPITECH PROJECT, 2022
** Image.cpp
** File description:
** Image file for Indie Studio.
*/

#include "../Include/Image_G.hpp"

Image_G::Image_G(Vector2 pos, const std::string& path) : _position(pos)
{
    _color = RAYWHITE;
    _image = LoadImage(path.c_str());
    _texture = LoadTextureFromImage(_image);
}

void Image_G::draw()
{
    DrawTexture(_texture, _position.x, _position.y, _color);
}