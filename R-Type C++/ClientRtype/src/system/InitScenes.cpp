//
// Created by perus-matteo on 10/29/22.
//

#include "magicsystem.hpp"
#include "../factory/factory.hpp"

//Welcome menu
void my_system::MagicSystem::init_entities_welcome_menu(void)
{
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Window.png", 1920 / 4, 0, 1));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Start.png", "start", 745, 550, 1));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Exit.png", "exit", 745, 750, 1));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Info.png", "info", 1920 / 3.2, 200, 1));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Settings.png", "settings", 1920 / 1.77, 200, 1));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/logo.png", 730, 35, 1));
}

void my_system::MagicSystem::init_entities_settings_menu()
{
    this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Window.png", 1920 / 4, 0, 1));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/logo.png", 730, 35, 1));
    this->entities.push_back(Factory::create_music("Assets/Music/music_random.ogg", true));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Backward_BTN.png", "back", 545, 35, 0.45));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Backward_BTN.png", "sound_down", 640, 200, 0.5));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Music_BTN.png", "music", 790, 200, 0.5));
    this->entities.push_back(Factory::create_text(940, 200, 80, "Assets/ethnocentric_rg.otf", ""));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Forward_BTN.png", "sound_up", 1140, 200, 0.5));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Backward_BTN.png", "fps_down", 590, 400, 0.5));
    this->entities.push_back(Factory::create_text(750, 400, 80, "Assets/ethnocentric_rg.otf", ""));
    this->entities.push_back(Factory::create_text(940, 400, 80, "Assets/ethnocentric_rg.otf", "fps"));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Forward_BTN.png", "fps_up", 1190, 400, 0.5));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Backward_BTN.png", "kb_down", 640, 600, 0.5));
    this->entities.push_back(Factory::create_text(790, 600, 80, "Assets/ethnocentric_rg.otf", "^<>v"));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Forward_BTN.png", "kb_up", 1140, 600, 0.5));
}

//Connection to server
void my_system::MagicSystem::init_entities_connection_menu()
{
    this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Window.png", 1920 / 4, 0, 1));
    this->entities.push_back(Factory::create_text(1920/3, 180, 80, "Assets/ethnocentric_rg.otf", "PSEUDO :"));
    this->entities.push_back(Factory::create_text(1920/3, 480, 80, "Assets/ethnocentric_rg.otf", "IP :"));
    this->entities.push_back(Factory::create_text(1920/3, 780, 80, "Assets/ethnocentric_rg.otf", "PORT :"));
    this->entities.push_back(Factory::create_text(1920/3, 260, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_text(1920/3, 560, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_text(1920/3, 860, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120 + 225, 50, 30, "Assets/ethnocentric_rg.otf", ""));
    //this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/logo.png", 730, 35, 1));
    this->entities.push_back(Factory::create_button("Assets/Images/Menu/Backward_BTN.png", "back", 545, 35, 0.45));
}

//Join or create lobby
void my_system::MagicSystem::init_entities_channel_menu()
{
    this->which_data = 0;
    this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Window.png", 1920 / 4, 0, 1));
    this->entities.push_back(Factory::create_text(1920/3, 180, 50, "Assets/ethnocentric_rg.otf", "Create room :"));
    this->entities.push_back(Factory::create_text(1920/3, 580, 50, "Assets/ethnocentric_rg.otf", "Join room :"));
    this->entities.push_back(Factory::create_text(1920/3, 260, 50, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_text(1920/3, 660, 50, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));
    this->entities.push_back(Factory::create_text(1920/3, 400, 50, "Assets/ethnocentric_rg.otf", "PRIVATE ?"));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Ok_BTN.png", 1920 / 5.5 + 700, 350, 0.75));
    this->entities.push_back(Factory::create_text(1920 / 5.5 + 475, 850, 50, "Assets/ethnocentric_rg.otf", "AUTO-JOIN"));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Replay_BTN.png", 1920/3, 810, 0.75));
}

//Waiting room
void my_system::MagicSystem::init_entities_waiting_room()
{
    this->which_data = 0;
    this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Window.png", 1920 / 4, 0, 1));
    this->entities.push_back(Factory::create_text(1920/3, 50, 30, "Assets/ethnocentric_rg.otf", "Waiting for 4 players..."));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 180, 50, "Assets/ethnocentric_rg.otf", "Player in the room :"));
    this->entities.push_back(Factory::create_text(1920/3, 380, 50, "Assets/ethnocentric_rg.otf", ""));
    this->entities.push_back(Factory::create_text(1920/3, 480, 50, "Assets/ethnocentric_rg.otf", ""));
    this->entities.push_back(Factory::create_text(1920/3, 580, 50, "Assets/ethnocentric_rg.otf", ""));
    this->entities.push_back(Factory::create_text(1920/3, 680, 50, "Assets/ethnocentric_rg.otf", ""));
}

void my_system::MagicSystem::init_entities_game_test(void)
{
    this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));

    // set les positions (et ça commence à entities[8] jusqu'à entities[11] pour les """"""joueurs""""""
    this->entities.push_back(Factory::create_player("Assets/Images/Player/yellow_ship/frame_1.png", 300, 100, 0.15, "Assets/Images/Player/yellow_ship/frame_", 10));
    this->entities.push_back(Factory::create_player("Assets/Images/Player/blue_ship/frame_1.png", 300, 250, 0.15, "Assets/Images/Player/blue_ship/frame_", 10));
    this->entities.push_back(Factory::create_player("Assets/Images/Player/red_ship/frame_1.png", 300, 500, 0.15, "Assets/Images/Player/red_ship/frame_", 10));
    this->entities.push_back(Factory::create_player("Assets/Images/Player/purple_ship/frame_1.png", 300, 650, 0.15, "Assets/Images/Player/purple_ship/frame_", 10));

    /*this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    // set les positions (et ça commence à entities[8] jusqu'à entities[11] pour les """"""joueurs""""""
    this->entities.push_back(Factory::create_sprite("Assets/Images/Player/yellow_ship/frame_1.png", _received._posPlayer[0][0], _received._posPlayer[0][1], 0.15));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Player/yellow_ship/frame_1.png", _received._posPlayer[1][0], _received._posPlayer[1][1], 0.15));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Player/yellow_ship/frame_1.png", _received._posPlayer[2][0], _received._posPlayer[2][1], 0.15));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Player/yellow_ship/frame_1.png", _received._posPlayer[3][0], _received._posPlayer[3][1], 0.15));
    this->entities.push_back(Factory::create_enemy("Assets/Images/Player/blue_ship_2.png", 1000, 100, 0.15));
    this->entities.push_back(Factory::create_enemy("Assets/Images/Player/blue_ship_2.png", 1000, 400, 0.15));
    this->entities.push_back(Factory::create_enemy("Assets/Images/Player/blue_ship_2.png", 1000, 700, 0.15));
    //push back 4 balles
    this->entities.push_back(Factory::create_enemy("Assets/Images/Shot/purple_shot.png", 0, 0, 0.15));
    this->entities.push_back(Factory::create_enemy("Assets/Images/Shot/purple_shot.png", 0, 0, 0.15));
    this->entities.push_back(Factory::create_enemy("Assets/Images/Shot/purple_shot.png", 0, 0, 0.15));
    this->entities.push_back(Factory::create_enemy("Assets/Images/Shot/purple_shot.png", 0, 0, 0.15));
    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", "HOWADJEHO"));
    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", "GEORGE"));
    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", "MICKAEL"));
    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", "ALFRED"));*/

    /* _player.number = 0;
     for (int i = 0; i <= 3; i++) {
         if (i != _player.number) {
             this->entities[8 + i].get<component::Sprite>().set_color(255, 255, 255, 128);
             this->entities[19 + i].get<component::Text_R>().set_color(255, 255, 255, 128);
         }
         this->entities[19 + i].get<component::Text_R>().update_pos
                 (this->entities[8 + i].get<component::Sprite>().get_pos().x + 100,
                  this->entities[8 + i].get<component::Sprite>().get_pos().y - 2);
     }*/
}

//create_game
void my_system::MagicSystem::init_entities_game(void)
{
    this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));

    // set les positions (et ça commence à entities[8] jusqu'à entities[11] pour les """"""joueurs""""""
    this->entities.push_back(Factory::create_player("Assets/Images/Player/yellow_ship/frame_1.png", _received._posPlayer[0][0], _received._posPlayer[0][1], 0.15, "Assets/Images/Player/yellow_ship/frame_", 10));
    this->entities.push_back(Factory::create_player("Assets/Images/Player/blue_ship/frame_1.png", _received._posPlayer[1][0], _received._posPlayer[1][1], 0.15, "Assets/Images/Player/blue_ship/frame_", 10));
    this->entities.push_back(Factory::create_player("Assets/Images/Player/red_ship/frame_1.png", _received._posPlayer[2][0], _received._posPlayer[2][1], 0.15, "Assets/Images/Player/red_ship/frame_", 10));
    this->entities.push_back(Factory::create_player("Assets/Images/Player/purple_ship/frame_1.png", _received._posPlayer[3][0], _received._posPlayer[3][1], 0.15, "Assets/Images/Player/purple_ship/frame_", 10));

    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", _received._names4waitingroom[0]));
    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", _received._names4waitingroom[1]));
    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", _received._names4waitingroom[2]));
    this->entities.push_back(Factory::create_text(1920/3, 180, 10, "Assets/ethnocentric_rg.otf", _received._names4waitingroom[3]));

    /*for (int i = 0; i != 100; i++) {
        this->bullets.push_back(Factory::create_shoot("Assets/Images/Shot/purple_shot.png"));
        std::cout << "Bullet created" << std::endl;
    }*/
    for (int i = 0; i <= 3; i++) {
        if (i != _player.number) {
            this->entities[8 + i].get<component::Sprite>().set_color(255, 255, 255, 128);
            this->entities[12 + i].get<component::Text_R>().set_color(255, 255, 255, 128);
        }
        this->entities[12 + i].get<component::Text_R>().update_pos
                (this->entities[8 + i].get<component::Sprite>().get_pos().x + 100,
                 this->entities[8 + i].get<component::Sprite>().get_pos().y - 2);

    }
}

void my_system::MagicSystem::init_entities_hunter_re(void)
{
    this->entities.clear();
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    this->entities.push_back(Factory::create_hunter_re("Assets/Images/Enemies/Ship_01.png", 2020, rand() % 700 + 200, 0.15));
    this->entities.push_back(Factory::create_text(1640, 30, 20, "Assets/ethnocentric_rg.otf", "Press 'q' to quit"));
}