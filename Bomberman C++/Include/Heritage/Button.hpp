/*
** EPITECH PROJECT, 2022
** Button.hpp
** File description:
** Button class for Indie Studio.
*/

#include "../Include/VirtualClass/IDraw.hpp"
#include "../Include/VirtualClass/IHover.hpp"
#include "../Include/VirtualClass/IClick.hpp"

#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

class Button : public IDraw, public IClick, public IHover {
    public:
        Button(float pos_x_r, float pos_y_r, float width_r, float height_r, Vector2 _pos_text, std::string _text_d, const std::string& path);
        ~Button() {};
        void draw() override;
        void update() override;
        bool isClicked() const override;
        void onClick() override;
        bool isHover() const override;
        void onHover() override;
        void AddText(std::string _text_d);
    private:
        Vector4 _position;
        Vector2 _pos_txt;
        Rectangle _rect;
        Font _font;
        float _fontsize;
        float _x;
        float _y;
        float _width;
        float _height;
        std::string _text;
        Color _color;
        Vector2 _mouse;
};



#endif
