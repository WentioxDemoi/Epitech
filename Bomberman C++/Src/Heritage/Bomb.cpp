/*
** EPITECH PROJECT, 2022
** Bomb.cpp
** File description:
** Bomb file for Indie Studio.
*/

#include "../Include/Bomb.hpp"

Bomb::Bomb(Vector3 pos, Vector3 size, const std::string& path) : _size(size)
{
    _position = pos;
    _color = RAYWHITE;
    _model = LoadModel(path.c_str());
    _texture = LoadTexture(path.c_str());
    Init_Sound_Game();
}


void Bomb::draw_model(){
    DrawModel(_model,{_position.x, _position.y, _position.z}, _scale, BLACK);
}

void Bomb::draw(){
    DrawCubeTexture(_texture, _position, _size.x, _size.y, _size.z, _color);
}

void Bomb::explode(int i){
    for (; i!= -1; i--){
        _cube_explode_right.push_back(Cube(Vector3{_position.x+(_size.x*i), _position.y, _position.z}, _size, "Ressources/lava.png", "enplosion")); 
        _cube_explode_left.push_back(Cube(Vector3{_position.x-(_size.x*i), _position.y, _position.z}, _size, "Ressources/lava.png", "enplosion"));  
        _cube_explode_up.push_back(Cube(Vector3{_position.x, _position.y+(_size.y*i), _position.z}, _size, "Ressources/lava.png", "enplosion"));
        _cube_explode_down.push_back(Cube(Vector3{_position.x, _position.y-(_size.y*i), _position.z}, _size, "Ressources/lava.png", "enplosion"));
    }
}


bool Bomb::IsCollide(Bomb::ICollidable &other) {
    if (CheckCollisionBoxes(
            BoundingBox{ Vector3{ _position.x - 0.6f/2,
                                     _position.y - 0.6f/2,
                                     _position.z - 0.6f/2 },
                           Vector3{ _position.x + 0.6f/2,
                                     _position.y + 0.6f/2,
                                     _position.z + 0.6f/2 }},
            BoundingBox{ Vector3{ other.getCollidable_pos().x - 0.6f/2,
                                     other.getCollidable_pos().y - 0.6f/2,
                                     other.getCollidable_pos().z - 0.6f/2 },
                           Vector3{ other.getCollidable_pos().x + 0.6f/2,
                                     other.getCollidable_pos().y + 0.6f/2,
                                     other.getCollidable_pos().z + 0.6f/2}})) _collide = true;
    return _collide;
}


void Bomb::Init_Sound_Game()
{
    _sound.push_back(Sound_G(0.7f, "Ressources/Sound/explosion.wav"));
}

void Bomb::end_explode(){
   for (int i = 0; i < _cube_explode_down.size(); i++)
        _cube_explode_down.at(i).draw();
   for (int i = 0; i < _cube_explode_up.size(); i++)
        _cube_explode_up.at(i).draw();
   for (int i = 0; i < _cube_explode_right.size(); i++)
        _cube_explode_right.at(i).draw();
   for (int i = 0; i < _cube_explode_left.size(); i++)
        _cube_explode_left.at(i).draw();
}

void Bomb::boom_sound(){
    _sound.at(0).play_audio();
}

void Bomb::clean_list(){
    _cube_explode_down.clear();
    _cube_explode_up.clear();
    _cube_explode_right.clear();
    _cube_explode_left.clear();
}