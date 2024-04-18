/*
** EPITECH PROJECT, 2022
** Menu.hpp
** File description:
** Menu class for Indie Studio.
*/

#include "../Include/Heritage/Background.hpp"
#include "../Include/Heritage/Button.hpp"
#include "../Include/Heritage/Music.hpp"
#include "../Include/Heritage/Sound.hpp"
#include "../Include/Heritage/Shader.hpp"
#include <string.h>
#include <fstream>
#include <vector>

#ifndef _MENU_HPP_
#define _MENU_HPP_

class Menu {
    public:
        Menu();
        ~Menu() {};
        void init_menu();
        void event_menu();
        void draw_shader();
        void draw_shader_victory();

        void MenuP_Button();
        int draw_button_menu();

        void Before_Play_Button();
        int draw_button_before_play();
        void Player_Name();
        std::string Player_Name_Management();

        void How_To_Play_Button();
        int draw_button_how_to_play();
        

        void Option_Button();
        int draw_button_option();

        void Audio_Button();
        int draw_button_audio();
        void On_Off_Audio();
        void Volume_Setter();

        void Graphic_Button();
        int draw_button_graphic();
        void On_Off_Graphic();
        int FPS_Management();
        int FPS_Value();

        void Pause_Button();
        int draw_button_pause();

        void Victory_Button();
        int draw_button_victory();

        void Loose_Button();
        int draw_button_loose();

        std::vector<std::string> parse_txt(std::string path);
    private:
        std::vector<Button> _buttons;
        std::vector<Button> _buttons_bp;
        std::vector<Button> _buttons_how_to_play;
        std::vector<Button> _buttons_opt;
        std::vector<Button> _buttons_audio;
        std::vector<Button> _buttons_graphic;
        std::vector<Button> _buttons_pause;
        std::vector<Button> _buttons_victory;
        std::vector<Button> _buttons_loose;

        std::vector<Background> _background;
        std::vector<Shader_Indie> _shader;

        std::vector<Music_G> _music;
        std::vector<Sound_G> _sound;

        std::string player_name;
        std::string player_name2;

        int _state_music;
        int _option_state;
        int _state_game;
        int _state_fps;
        int _state_graphic;
        int _state_player;
        int _state_launcher;
        int _framesCounter;
        int _letterCount;
        int _letterCount2;
        int _fps;
        double _music_volume = 0.3;
        double _click_volume = 0.7;

        bool _mouseOnText;
};

#endif