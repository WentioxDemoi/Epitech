/*
** EPITECH PROJECT, 2022
** Gameplay.hpp
** File description:
** Gameplay class for Indie Studio.
*/

#include "../Include/VirtualClass/IDraw.hpp"

#ifndef _ImageG_HPP_
#define _ImageG_HPP_


class Image_G : public IDraw {
    public:
        Image_G(Vector2 pos, const std::string& path);
        ~Image_G() {};
        void draw() override;
        void update() override {};
    private:
        Image _image;
        Vector2 _position;
        Texture2D _texture;
        Color _color;
};

#endif