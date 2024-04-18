/*
** EPITECH PROJECT, 2022
** Cube.hpp
** File description:
** Cube class for Indie Studio.
*/

#include "../Player.hpp"

#ifndef _ICUBE_HPP_
#define _ICUBE_HPP_


class Cube : public IDraw , public ICollidable
{
    public:
        Cube(Vector3 pos, Vector3 size, const std::string& path, const std::string& _name);
        ~Cube() {};
        void draw() override;
        void update() override {};
        Vector3 getPos() { return _position; };
        std::string getName() { return _name; };
        void setName(const std::string newname) { _name == newname; };
        void setTexture(const std::string& path) { _texture = LoadTexture(path.c_str()); };
        Texture2D getTexture() { return _texture; };
        bool IsCollide(ICollidable &other) override;
        const ICollidable &getCollidable() const override;
        Vector3 &getCollidable_pos() override {return _position;};
        Vector3 _position;
        Vector3 _size;
    private:
        Texture2D _texture;
        Color _color;
        const std::string _name;
};

#endif