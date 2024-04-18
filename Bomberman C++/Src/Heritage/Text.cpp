/*
** EPITECH PROJECT, 2022
** Text.cpp
** File description:
** Text file for Indie Studio.
*/

#include "../Include/Text.hpp"

Text_G::Text_G(Vector2 _pos_text, std::string _text_d, const std::string& path) : _pos_txt(_pos_text)
{
    _color = RAYWHITE;
    _font = LoadFontEx(path.c_str(), 40, 0, 250);
    _fontsize = (float)_font.baseSize;
    _text = _text_d;
}

void Text_G::update()
{
    DrawTextEx(_font, _text.c_str(), _pos_txt, (float)_font.baseSize, 15, RED);
}

void Text_G::set_text(std::string _text_d)
{
    _text = _text_d;
}

void Text_G::draw()
{
    DrawTextEx(_font, _text.c_str(), _pos_txt, (float)_font.baseSize, 15, _color);
}
