/*
** EPITECH PROJECT, 2022
** Cube.cpp
** File description:
** Cube file for Indie Studio.
*/

#include "../Include/Heritage/Button.hpp"

Button::Button(float pos_x_r, float pos_y_r, float width_r, float height_r, Vector2 _pos_text, std::string _text_d, const std::string& path ) : _x(pos_x_r), _y(pos_y_r), _width(width_r), _height(height_r), _pos_txt(_pos_text)
{
    _rect = { _x, _y, _width, _height };
    _color = RAYWHITE;
    _font = LoadFontEx(path.c_str(),85, 0, 250);
    _fontsize = (float)_font.baseSize;
    _text = _text_d;
}

bool Button::isHover() const
{
    if (CheckCollisionPointRec(GetMousePosition(), _rect) == true) {
        return (true);
    }
    return (false);
}

bool Button::isClicked() const
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        return true;
    return false;
}

void Button::onHover()
{
    if (this->isHover() == true) {
        return;
    }
}

void Button::onClick()
{
    if (this->isClicked() == true && this->isHover() == true) {
        return;
    }
}

void Button::AddText(std::string _text_d)
{
    _text = _text_d;
}

void Button::update()
{
    DrawTextEx(_font, _text.c_str(), _pos_txt, (float)_font.baseSize, 15, RED);
}

void Button::draw()
{
    // DrawRectangle(_x, _y, _width, _height, _color);
    DrawTextEx(_font, _text.c_str(), _pos_txt, (float)_font.baseSize, 15, RAYWHITE);
}
