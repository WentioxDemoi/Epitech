/*
** EPITECH PROJECT, 2022
** Core.cpp
** File description:
** Core functions for Indie Studio.
*/

// C'est le fichier utiliser pour créer notre boucle de jeu.

#include "../Include/Menu/Menu.hpp"
#include "../Include/Logo/Logo.hpp"
#include "../Include/Core/Core.hpp"
#include "../Include/Gameplay.hpp"
#include "../Include/Tools.hpp"

Core::Core()
{
    this->currentScreen = LOGO;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    
    InitWindow(1920, 1080, "BomberGus !");
    ToggleFullscreen();
    SetTargetFPS(60);
    _fps = 0;
    _health_player = 1;
    _health_green = 1;
    _health_blue = 1;
    _health_black = 1;
}

Core::~Core()
{
}

int Core::Launching_Game(int ac)
{
    Logo logo;
    Menu menu;
    Gameplay game;

    menu.init_menu();
    logo.init_logo();
    game.Init_Sound();

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case LOGO:
            {
                logo.shader_timer();
            } break;
        default:
            {
                menu.event_menu();
            } break;
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch(currentScreen)
        {

            case LOGO:
            {
                currentScreen = (GameScreen)logo.Logo_Loader();
            } break;

            case MENU:
            {
                menu.draw_shader();
                currentScreen = (GameScreen)menu.draw_button_menu();
            } break;

            case PLAY:
            {
                menu.draw_shader();
                currentScreen = (GameScreen)menu.draw_button_before_play();
                _name = menu.Player_Name_Management();
            } break;

            case HOW_TO_PLAY:
            {
                menu.draw_shader();
                currentScreen = (GameScreen)menu.draw_button_how_to_play();
            } break;

            case OPTION:
            {
                menu.draw_shader();
                currentScreen = (GameScreen)menu.draw_button_option();
            } break;

            case GAME:
            {
                menu.draw_shader();
                currentScreen = (GameScreen)game.Main_Game(_name, _health_player, _health_green, _health_blue, _health_black);
                _health_player = game.get_health_player();
                _health_green = game.get_health_green();
                _health_blue = game.get_health_blue();
                _health_black = game.get_health_black();
                
            } break;

            case QUIT:
            {
                exit(0);
            } break;

             case AUDIO:
            {
                menu.draw_shader();
                currentScreen = (GameScreen)menu.draw_button_audio();
            } break;

             case GRAPHICS:
            {
                menu.draw_shader();
                _fps = menu.FPS_Value();
                currentScreen = (GameScreen)menu.draw_button_graphic();
            } break;

             case PAUSE:
            {
                menu.draw_shader();
                currentScreen = (GameScreen)menu.draw_button_pause();
            } break;

            case VICTORY:
            {
                menu.draw_shader_victory();
                _health_player = 1;
                _health_green = 1;
                _health_blue = 1;
                _health_black = 1;
                currentScreen = (GameScreen)menu.draw_button_victory();
            } break;

             case LOOSE:
            {
                menu.draw_shader_victory();
                 _health_player = 1;
                _health_green = 1;
                _health_blue = 1;
                _health_black = 1;
                currentScreen = (GameScreen)menu.draw_button_loose();
            } break;
        
             default: break;
        }
        if (_fps == 1)
            DrawFPS(1820, 10);

        EndDrawing();
    }
    CloseWindow();
   return (0);
}

void Core::Erroring(int ac)
{
    if (ac != 1) throw my_exception();
}