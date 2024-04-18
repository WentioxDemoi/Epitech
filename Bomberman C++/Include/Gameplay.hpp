/*
** EPITECH PROJECT, 2022
** Gameplay.hpp
** File description:
** Gameplay class for Indie Studio.
*/


#include <iostream>
#include <string.h>
#include <cstring>
#include "raylib.h"
#include "./Heritage/Cube.hpp"
#include "../Include/Heritage/Sound.hpp"
#include "./Image_G.hpp"
#include "./Text.hpp"


#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

class Gameplay {
    public:
        Gameplay();
        ~Gameplay() {};
        int Main_Game(std::string name, int player_h, int green_h, int blue_h, int black_h);

        // Map
        std::vector<std::string> readMap(const std::string& path);
        void setMap(std::vector<std::string> map);

        // Init
        void Init_Image();
        void Init_Text();
        void Init_Sound();

        // Health
        void Health_Manager();
        int get_health_player();
        int get_health_green();
        int get_health_blue();
        int get_health_black();

    private:
        std::vector<Cube> cubes_map;
        std::vector<Player> players;
        std::vector<Image_G> _image;
        std::vector<Text_G> _text;
        std::vector<Sound_G> _sound;

        Camera3D camera = { 0 };

        Vector3 _position;
        std::vector<std::string> map;
        std::string _mapFile;
        std::string _name;

        clock_t _clock;
        double _time;
        double _tmp_time;
        int _tmp;
        int _player_health;
        int _ia_green_health;
        int _ia_blue_health;
        int _ia_black_health;

        int _block = 0;
};

#endif