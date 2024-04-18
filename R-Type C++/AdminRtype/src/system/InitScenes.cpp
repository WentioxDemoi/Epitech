//
// Created by perus-matteo on 10/29/22.
//

#include "magicsystem.hpp"
#include "../factory/factory.hpp"

// LES INITIALISATIONS DE MENUS UTILISENT LES VARIABLES A RECEVOIR PAR LE SERVEUR (VOIR LE HPP)

void my_system::MagicSystem::init_entities_connection_menu()
{
    if (!this->entities.empty())
        this->entities.clear();
    this->which_data = 0;
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 0, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/BG.png", 1920, 0, 1, 1));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Meteors.png", 1920, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 0, 0, 1, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Planets.png", 1920, 1, 0, 2));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 0, 0, 1, 3));
    this->entities.push_back(Factory::create_parallax("Assets/Images/Parallax/One/Stars.png", 1920, 0, 1, 3));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Window.png", 1920 / 4, 0, 1));
    this->entities.push_back(Factory::create_text(1920/3, 180, 80, "Assets/ethnocentric_rg.otf", "IP :"));
    this->entities.push_back(Factory::create_text(1920/3, 480, 80, "Assets/ethnocentric_rg.otf", "PORT :"));
    this->entities.push_back(Factory::create_text(1920/3, 260, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_text(1920/3, 560, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));
}

void my_system::MagicSystem::init_entities_selection_room(void)
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
    this->entities.push_back(Factory::create_text(1920/3 - 60, 180, 60, "Assets/ethnocentric_rg.otf", "search player :"));
    this->entities.push_back(Factory::create_text(1920/3 - 60, 480, 60, "Assets/ethnocentric_rg.otf", "search room :"));
    this->entities.push_back(Factory::create_text(1920/3 - 60, 780, 50, "Assets/ethnocentric_rg.otf", "display all rooms"));
    this->entities.push_back(Factory::create_text(1920/3 - 60, 260, 60, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_text(1920/3 - 60, 560, 60, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));
}

void my_system::MagicSystem::init_entities_solo_room()
{
    this->which_data = 0;
    if (!this->entities.empty())
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
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));

    for (int i = 0; i < 4; i++)
        this->entities.push_back(Factory::create_text(1920/3 - 80, 250 + (150 * i), 30,
        "Assets/ethnocentric_rg.otf", ""));
}

void my_system::MagicSystem::init_entities_all_rooms()
{
    this->which_data = 0;
    if (!this->entities.empty())
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
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));

    for (int i = 0; i < 10; i++)
        this->entities.push_back(Factory::create_text(1920/3 - 80, 250 + (150 * i), 30,
        "Assets/ethnocentric_rg.otf", ""));
}

void my_system::MagicSystem::init_entities_players_room()
{
    this->which_data = 0;
    if (!this->entities.empty())
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
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));

    for (int i = 0; i < 8; i++)
        this->entities.push_back(Factory::create_text(1920/3 - 80, 250 + (150 * i), 30,
        "Assets/ethnocentric_rg.otf", ""));
}

void my_system::MagicSystem::init_entities_solo_player_room(void)
{
    this->which_data = 0;
    if (!this->entities.empty())
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

    this->entities.push_back(Factory::create_text(1920/3, 180, 50, "Assets/ethnocentric_rg.otf", this->test_for_player_search.at(0)));
    this->entities.push_back(Factory::create_text(1920/3, 260, 50, "Assets/ethnocentric_rg.otf", this->test_for_player_search.at(1)));
    this->entities.push_back(Factory::create_text(1920/3, 340, 50, "Assets/ethnocentric_rg.otf", this->test_for_player_search.at(2)));
    this->entities.push_back(Factory::create_text(1920/3, 520, 50, "Assets/ethnocentric_rg.otf", "speedy"));
    this->entities.push_back(Factory::create_text(1920/3, 600, 50, "Assets/ethnocentric_rg.otf", "ban"));
    this->entities.push_back(Factory::create_text(1920/3, 680, 50, "Assets/ethnocentric_rg.otf", "instant kill"));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 570, 0.75));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Close_BTN.png", 1920 / 5.5 + 730, 500, 0.5));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));
}

// pas encore créée
void my_system::MagicSystem::init_entities_spectate_room()
{
    this->which_data = 0;
    if (!this->entities.empty())
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
    this->entities.push_back(Factory::create_text(1920/3, 180, 80, "Assets/ethnocentric_rg.otf", "spectate :"));
    this->entities.push_back(Factory::create_text(1920/3, 480, 80, "Assets/ethnocentric_rg.otf", "IP :"));
    this->entities.push_back(Factory::create_text(1920/3, 780, 80, "Assets/ethnocentric_rg.otf", "PORT :"));
    this->entities.push_back(Factory::create_text(1920/3, 260, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_text(1920/3, 560, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_text(1920/3, 860, 80, "Assets/ethnocentric_rg.otf", "..."));
    this->entities.push_back(Factory::create_sprite("Assets/Images/Menu/Arrow.png", 1920 / 5.5, 180, 0.75));
    this->entities.push_back(Factory::create_text(1920/3 - 120, 50, 30, "Assets/ethnocentric_rg.otf", ""));
}