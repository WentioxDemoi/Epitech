/*
** EPITECH PROJECT, 2022
** Text.hpp
** File description:
** Text class for Indie Studio.
*/

#include "../Include/VirtualClass/IDraw.hpp"

#ifndef _TextG_HPP_
#define _TextG_HPP_


class Text_G : public IDraw {
    public:
        Text_G(Vector2 _pos_text, std::string _text_d, const std::string& path);
        ~Text_G() {};
        void draw() override;
        void update() override;
        void set_text(std::string _text_d);
    private:
        Vector2 _pos_txt;
        Font _font;
        Color _color;

        std::string _text;
        float _fontsize;
};

#endif