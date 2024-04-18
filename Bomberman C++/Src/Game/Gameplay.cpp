/*
** EPITECH PROJECT, 2022
** Gameplay.cpp
** File description:
** Gameplay functions for Indie Studio.
*/

// C'est le fichier utiliser pour créer le gameplay de notre jeu (combat, etc...).

#include "../Include/Gameplay.hpp"
#include "../Include/Heritage/Button.hpp"
#include "../Include/Heritage/Cube.hpp"
#include "../Include/Bomb.hpp"
#include "raylib.h"
#include <iostream>
#include <iosfwd>
#include <vector>
#include <fstream>
#include <sstream>

Gameplay::Gameplay()
{
    Init_Image();
    Init_Text();
    this->_mapFile = "Ressources/map.txt";

    this->camera.position = Vector3{ 7.0f, -20.0f, 25.0f };
    this->camera.target = Vector3{ 7.0f, 0.0f, 5.0f };
    this->camera.up = Vector3{ 0.0f, 5.0f, 0.0f };
    this->camera.fovy = 20.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    this->map = readMap(this->_mapFile);
    this->setMap(this->map);

    _player_health = 1;
    _ia_green_health = 1;
    _ia_blue_health = 1;
    _ia_black_health = 1;  
    
    _clock = clock();
    _time = GetTime();
    _tmp_time = 0;
    _tmp = 0;
    
}

///////////////////////////////////////////////////////////////
///////////////////////// INIT ////////////////////////////////
///////////////////////////////////////////////////////////////

void Gameplay::Init_Image()
{
    _image.push_back(Image_G(Vector2{57, 240}, "Ressources/Images/player.png"));
    _image.push_back(Image_G(Vector2{50, 60}, "Ressources/Images/ia-green.png"));
    _image.push_back(Image_G(Vector2{1807, 240}, "Ressources/Images/ia-blue.png"));
    _image.push_back(Image_G(Vector2{1815, 60}, "Ressources/Images/ia-black.png"));
    _image.push_back(Image_G(Vector2{-20, 170}, "Ressources/Images/bg_player.png"));
    _image.push_back(Image_G(Vector2{-20, -10}, "Ressources/Images/bg_green.png"));
    _image.push_back(Image_G(Vector2{1570, -10}, "Ressources/Images/bg_black.png"));
    _image.push_back(Image_G(Vector2{1570, 170}, "Ressources/Images/bg_blue.png"));
}

void Gameplay::Init_Text()
{
    _text.push_back(Text_G(Vector2{140, 205}, _name.c_str(), "Ressources/Text_Font/among_us.ttf"));
    _text.push_back(Text_G(Vector2{165, 250}, "Alive", "Ressources/Text_Font/among_us.ttf"));

    _text.push_back(Text_G(Vector2{140, 25}, "Green", "Ressources/Text_Font/among_us.ttf"));
    _text.push_back(Text_G(Vector2{165, 70}, "Alive", "Ressources/Text_Font/among_us.ttf"));

    _text.push_back(Text_G(Vector2{1645, 205}, "Blue", "Ressources/Text_Font/among_us.ttf"));
    _text.push_back(Text_G(Vector2{1615, 250}, "Alive", "Ressources/Text_Font/among_us.ttf"));

    _text.push_back(Text_G(Vector2{1645, 25}, "Black", "Ressources/Text_Font/among_us.ttf"));
    _text.push_back(Text_G(Vector2{1615, 70}, "Alive", "Ressources/Text_Font/among_us.ttf"));

}

void Gameplay::Init_Sound(){
    _sound.push_back(Sound_G(0.7f, "Ressources/Sound/kill.wav"));
}

std::vector<std::string> Gameplay::readMap(const std::string& path)
{
    std::vector<std::string> lines;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

float intToFloat(int i)
{
    return static_cast<float>(i);
}

void Gameplay::setMap(std::vector<std::string> map)
{
    for (int y = 0; y < this->map.size() ; y++ )
        for (int x = 0; x < this->map[y].size(); x++)
        {
            this->_position = Vector3{intToFloat(x) * 1, intToFloat(y) * 1, 1};
            if (this->map[y][x] == '1'){
                cubes_map.emplace_back(this->_position, Vector3{1, 1, 1}, "Ressources/wood.png", "destructible");
            }
            else if (this->map[y][x] == '0')
            {
                cubes_map.emplace_back(this->_position, Vector3{1, 1, 1}, "Ressources/wood_bleu.png", "indestructible");
            }
            else if (this->map[y][x] == '2')
            {
                this->_position = Vector3{intToFloat(x) * 1, intToFloat(y) * 1, 0};
                cubes_map.emplace_back(this->_position, Vector3{1, 1, 1}, "Ressources/wood_vert.png", "indestructible");
            }
            else if (this->map[y][x] == '3')
            {
                this->_position = Vector3{intToFloat(x) * 1, intToFloat(y) * 1, 0};
                cubes_map.emplace_back(this->_position, Vector3{1, 1, 1}, "Ressources/wood_vert.png", "indestructible");
                this->_position = Vector3{intToFloat(x) * 1, intToFloat(y) * 1, 1};
                players.emplace_back(this->_position, 0.4f, "player");
                players.at(0)._color ++;
            }
        }
}

int Gameplay::Main_Game(std::string name, int player_h, int green_h, int blue_h, int black_h)
{
    _time = GetTime();
    _name = name;
    _text.at(0).set_text(_name.c_str());
    _player_health = player_h;
    _ia_green_health = green_h;
    _ia_blue_health = blue_h;
    _ia_black_health = black_h;
    _block = 0;

   BeginMode3D(this->camera);
    for (int map_size = 0; map_size != cubes_map.size(); map_size++)
        cubes_map[map_size].draw();

    for (int i = 0; i < players.size(); i++){
        players.at(i).setModel(i);
        players.at(i).draw();
        players.at(i).among_event(i);
        players.at(i).ia_event(i, players);
        players.at(i).emplace_bomb(_time, cubes_map, players, i);
    }
    

    for (int j = 0; j < players.size(); j++)
        for (int i = 0; i != cubes_map.size(); i++)
            players.at(j)._collide = players.at(j).IsCollide(cubes_map.at(i));
    
    for (int i = 0; i < players.size(); i++)
        for (int j = 0; j < players.size(); j++)
            if (i != j && players.at(j).IsinLife())
                players.at(i)._collide = players.at(i).IsCollide(players.at(j));
    

    EndMode3D();
    if (_player_health == 1)   players.at(0).IsinLife() ? _player_health = 1 : _player_health = 0;
    if(_ia_green_health == 1) players.at(2).IsinLife() ? _ia_green_health = 1 : _ia_green_health = 0;
    if(_ia_blue_health == 1)   players.at(1).IsinLife() ? _ia_blue_health = 1 : _ia_blue_health = 0;
    if(_ia_black_health == 1)  players.at(3).IsinLife() ? _ia_black_health = 1 : _ia_black_health = 0;
    Health_Manager();

    if (IsKeyDown(KEY_TAB))
        return (10);
    else if ((_ia_black_health == -1) && (_ia_blue_health == -1) && (_ia_green_health == -1)){
        cubes_map.clear();
        players.clear();
        setMap(map);
        return (11);
    }
    else if (_player_health == -1){
        cubes_map.clear();
        players.clear();
        setMap(map);
        return (12);
    }
    return (9);
}


///////////////////////////////////////////////////////////////
///////////////////////// HEALTH //////////////////////////////
///////////////////////////////////////////////////////////////


void Gameplay::Health_Manager()
{
    _image[4].draw();
    _image[5].draw();
    _image[6].draw();
    _image[7].draw();
    if (_player_health == 0 || _player_health == -1) {
        _text[1].set_text("DeAD");
        _text.at(0).update();
        _text[1].update();
        if (_player_health == 0){
            _player_health = -1;
            _sound.at(0).play_audio();}
    } else {
        _text[1].set_text("Alive");
        _text.at(0).draw();
        _text[1].draw();
    }

    if (_ia_green_health == 0 || _ia_green_health == -1) {
        _text[3].set_text("DeAd");
        _text[2].update();
        _text[3].update();
        if (_ia_green_health == 0){
            _ia_green_health = -1;
            _sound.at(0).play_audio();}
    } else {
        _text[3].set_text("Alive");
        _text[2].draw();
        _text[3].draw();
    }
    if (_ia_blue_health == 0 || _ia_blue_health == -1) {
        _text[5].set_text("DeAd");
        _text[4].update();
        _text[5].update();
        if (_ia_blue_health == 0){
            _ia_blue_health = -1;
            _sound.at(0).play_audio();}
    } else {
         _text[5].set_text("Alive");
        _text[4].draw();
        _text[5].draw();
    }
    if (_ia_black_health == 0 || _ia_black_health == -1) {
        _text[7].set_text("DeAd");
        _text[6].update();
        _text[7].update();
        if (_ia_black_health == 0){
            _ia_black_health = -1;
            _sound.at(0).play_audio();}
    } else {
        _text[7].set_text("Alive");
        _text[6].draw();
        _text[7].draw();
    }
    _image.at(0).draw();
    _image[1].draw();
    _image[2].draw();
    _image[3].draw();
}

int Gameplay::get_health_player()
{
    return (_player_health);
}

int Gameplay::get_health_green()
{
    return (_ia_green_health);
}

int Gameplay::get_health_blue()
{
    return (_ia_blue_health);
}

int Gameplay::get_health_black()
{
    return (_ia_black_health);
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////