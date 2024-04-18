/*
** EPITECH PROJECT, 2022
** Cube.cpp
** File description:
** Cube file for Indie Studio.
*/

#include "../Include/Heritage/Cube.hpp"

Cube::Cube(Vector3 pos, Vector3 size, const std::string& path, const std::string& _name ) : _position(pos), _size(size), _name(_name)
{
    _color = RAYWHITE;
    _texture = LoadTexture(path.c_str());
}


void Cube::draw()
{
    DrawCubeTexture(_texture, _position, _size.x, _size.y, _size.z, _color);
}

bool Cube::IsCollide(ICollidable &other) {
     if (CheckCollisionBoxes(
            BoundingBox{ Vector3{ _position.x - _size.x/2,
                                     _position.y - _size.y/2,
                                     _position.z - _size.z/2 },
                           Vector3{ _position.x + _size.x/2,
                                     _position.y + _size.y/2,
                                     _position.z + _size.z/2 }},
            BoundingBox{ Vector3{ other.getCollidable_pos().x - 1/2,
                                     other.getCollidable_pos().y - 1/2,
                                     other.getCollidable_pos().z - 1/2 },
                           Vector3{ other.getCollidable_pos().x + 1/2,
                                     other.getCollidable_pos().y + 1/2,
                                     other.getCollidable_pos().z + 1/2 }})) return true;
    else return false;
}
const Cube::ICollidable & Cube::getCollidable() const {
    return *this;
}