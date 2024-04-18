/*
** EPITECH PROJECT, 2022
** Background.hpp
** File description:
** Background class for Indie Studio.
*/

#include "../Include/VirtualClass/IDraw.hpp"

#ifndef _BACKGROUND_HPP_
#define _BACKRGOUND_HPP_

class Background : public IDraw {
    public:
        Background(float pos_x, float pos_y, const std::string& path);
        ~Background() {};
        void draw() override;
        void update() override;
    private:
     float _x;
     float _y;

    Color _color;
    Texture2D _texture;

};

#endif