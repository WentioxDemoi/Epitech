#include "magicsystem.hpp"
#include "../factory/factory.hpp"
#include "../system/draw.hpp"

void my_system::MagicSystem::manage_button_pressing(std::string button_name)
{

}

// permet la sélection de la bonne fonction
void my_system::MagicSystem::manage_keyboard(void)
{
    if (whichMenus == connection_room)
        manage_keyboard_connection_menu();
    else if (whichMenus == players_room)
        manage_keyboard_player_iteration();
    else if (whichMenus == all_rooms_room)
        manage_keyboard_all_rooms();
    else if (whichMenus == solo_room_room)
        manage_keyboard_solo_room();
    else if (whichMenus == solo_player_room)
        manage_keyboard_solo_player();
    else if (whichMenus == selection_room)
        manage_selection_menu();
}

// room d'interaction avec le joueur
void my_system::MagicSystem::manage_keyboard_solo_player()
{
    // ici, la ligne 35 est à remplacer avec les bonnes values (NB : nom du joueur, etc...)

    this->test_for_player_search.clear();
    //this->allRoom();
    for (int i = 0; i < _received._room.size(); i++)
        this->test_for_player_search.push_back(_received._player_search[i]);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->whichMenus = selection_room;
        init_entities_selection_room();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->which_data < 2)
            this->which_data++;
        else
            this->which_data = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->which_data > 0)
            this->which_data--;
        else
            this->which_data = 2;
    }
    if (entities[15].has<component::Sprite>())
        entities[15].get<component::Sprite>().set_pos(1920 / 5.5, 490 + (75 * which_data));

    // ici est à rajouter les interactions. Pour speedy, je propose d'envoyer en continu s'il est speedy ou non
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Enter && this->which_data == 0) {
        if (this->speedy) {
            entities[16].get<component::Sprite>().update_texture("Assets/Images/Menu/Close_BTN.png");
            this->speedy = false;
        }
        else {
            entities[16].get<component::Sprite>().update_texture("Assets/Images/Menu/Ok_BTN.png");
            this->speedy = true;
        }
    }
}

// pour l'écran de recherche de room
void my_system::MagicSystem::manage_keyboard_solo_room()
{
//-----------------------------------------------------------------------------//
    //AJOUT DES NOMS DES JOUEURS DANS TEST_FOR_ROOM_SEARCH
    this->test_for_room_search.clear();
    this->soloRoom(last_search);
    for (int i = 0; i < _received._playerRoom.size(); i++) {
        this->test_for_room_search.push_back(_received._playerRoom[i]);
    }
    for (int i = 0; i < this->test_for_room_search.size(); i++)
        this->entities[11 + i].get<component::Text_R>().update_text(_received._playerRoom[i]);
//-----------------------------------------------------------------------------//

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->whichMenus = selection_room;
        init_entities_selection_room();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->which_data < this->test_for_room_search.size() - 1)
            this->which_data++;
        else
            this->which_data = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->which_data > 0)
            this->which_data--;
        else
            this->which_data = this->test_for_room_search.size() - 1;
    }
    if (entities[9].has<component::Sprite>())
        entities[9].get<component::Sprite>().set_pos(1920 / 5.5, 200 + (which_data * 150));

    // sélection d'un joueur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        this->whichMenus = solo_player_room;
        init_entities_solo_player_room();
    }
}

// pour l'écran d'affichage de toutes les rooms
void my_system::MagicSystem::manage_keyboard_all_rooms()
{
//-----------------------------------------------------------------------------//
    //AJOUT DES NOMS DES ROOMS DANS Test_for_room_display
    this->test_for_room_display.clear();
    this->allRoom();
    for (int i = 0; i < _received._room.size(); i++) {
        this->test_for_room_display.push_back(_received._room[i]);
    }
    for (int i = 0; i < this->test_for_room_display.size(); i++)
        this->entities[11 + i].get<component::Text_R>().update_text(_received._room[i]);
//-----------------------------------------------------------------------------//
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->whichMenus = selection_room;
        init_entities_selection_room();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->which_data < this->test_for_room_display.size() - 1)
            this->which_data++;
        else
            this->which_data = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->which_data > 0)
            this->which_data--;
        else
            this->which_data = this->test_for_room_display.size() - 1;
    }
    // sélection d'une room
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        this->whichMenus = solo_room_room;
        init_entities_solo_room();
    }
    if (entities[9].has<component::Sprite>())
        entities[9].get<component::Sprite>().set_pos(1920 / 5.5, 200 + (which_data * 150));
}

// pour l'écran d'affichage des itérations de pseudos
void my_system::MagicSystem::manage_keyboard_player_iteration()
{
    this->test_for_player_iteration_search.clear();
    this->allRoom();
    for (int i = 0; i < _received._room.size(); i++)
        this->test_for_player_iteration_search.push_back(_received._player_search[i]);
    for (int i = 0; i < this->test_for_player_iteration_search.size(); i++)
        this->entities[11 + i].get<component::Text_R>().update_text(_received._player_search[i]);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        this->whichMenus = selection_room;
        init_entities_selection_room();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->which_data < this->test_for_player_iteration_search.size() - 1)
            this->which_data++;
        else
            this->which_data = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->which_data > 0)
            this->which_data--;
        else
            this->which_data = this->test_for_player_iteration_search.size() - 1;
    }
    // sélection d'un joueur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        // ici, je dois t'envoyer "le numéro" du joueur de la liste que tu m'envoies. Exemple : howa, kd, remy ==> je veux kd, je t'envoie 1
        this->whichMenus = solo_player_room;
        init_entities_solo_player_room();
    }
    if (entities[9].has<component::Sprite>())
        entities[9].get<component::Sprite>().set_pos(1920 / 5.5, 200 + (which_data * 150));
}

// pour l'écran de connexion
void my_system::MagicSystem::manage_keyboard_connection_menu(void)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->which_data < 1)
            this->which_data++;
        else
            this->which_data = 0;
    } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->which_data > 0)
            this->which_data--;
        else
            this->which_data = 1;
    }

    if (which_data == 0) {
        entities[11].get<component::Text_R>().input_text(_event, 12, 0.33, false, false);
        entities[13].get<component::Sprite>().set_pos(1920 / 5.5, 180);
    }
    if (which_data == 1) {
        entities[12].get<component::Text_R>().input_text(_event, 14, 0.4, true, true);
        entities[13].get<component::Sprite>().set_pos(1920 / 5.5, 480);
    }

    if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Enter) {
        if (entities[12].get<component::Text_R>().get_string().size() != 0 &&
            entities[11].get<component::Text_R>().get_string().size() != 0) {
            boost::system::error_code ec;
            ip_address = boost::asio::ip::address::from_string(entities[11].get<component::Text_R>().get_string(), ec);
            if (!ec && !_player._connected)
                this->connection(entities[12].get<component::Text_R>().get_string());
            else
                return;
        
        }
    }
    if (_player._connected) {
        this->whichMenus = selection_room;
        init_entities_selection_room();
    }
}

// pour l'écran de sélection de recherche
void my_system::MagicSystem::manage_selection_menu(void)
{
    // curseur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (this->which_data < 2)
            this->which_data++;
        else
            this->which_data = 0;
    } if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (this->which_data > 0)
            this->which_data--;
        else
            this->which_data = 2;
    }
    if (which_data == 0) {
        entities[12].get<component::Text_R>().input_text(_event, 12, 0.33, false, false);
        entities[14].get<component::Sprite>().set_pos(1920 / 5.5, 180);
    }
    if (which_data == 1) {
        entities[13].get<component::Text_R>().input_text(_event, 14, 0.33, false, false);
        entities[14].get<component::Sprite>().set_pos(1920 / 5.5, 480);
    }
    if (which_data == 2) {
        entities[14].get<component::Sprite>().set_pos(1920 / 5.5, 730);
    }
    // changements de room
    std::string error_case = "worked";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (which_data == 0) {
            error_case = this->playerIteration(entities[12].get<component::Text_R>().get_string());
            if (error_case.compare("OK") == 0) {
                this->whichMenus = players_room; // itération de joueur
                init_entities_players_room();
            }
            else
                this->entities[15].get<component::Text_R>().update_text(error_case);
        }
        if (which_data == 1) {
            error_case = this->soloRoom(entities[13].get<component::Text_R>().get_string());
            if (error_case.compare("OK") == 0) {
                this->whichMenus = solo_room_room; // recherche de room seule
                init_entities_solo_room();
            }
            else
                this->entities[15].get<component::Text_R>().update_text(error_case);
        }
        if (which_data == 2) {
            error_case = this->allRoom();
            if (error_case.compare("OK") == 0) {
                this->whichMenus = all_rooms_room; // toutes les rooms
                init_entities_all_rooms();
            }
            else
                this->entities[15].get<component::Text_R>().update_text(error_case);
        }
    }
}

my_system::MagicSystem::MagicSystem(const int &screenWidth, const int &screenHeight, const char *name)
{
    _win.create(sf::VideoMode(screenWidth, screenHeight), name);
    _win.setPosition(sf::Vector2i(0, 0)); 
    _win.setFramerateLimit(60);

    this->whichMenus = connection_room;
    this->which_data = 0;
    this->speedy = false;

    _player._connected = false;
    _player._inLobby = false;

    // sont ici les variables que j'utilise pour simuler les envois du server

    this->test_for_player_iteration_search.push_back("harold | room : mango | hp : 30");
    this->test_for_player_iteration_search.push_back("harold | room : butter | hp : 12");
    this->test_for_player_iteration_search.push_back("harold | room : potato | hp : 30");
    this->test_for_player_iteration_search.push_back("harold | room : diavolo | hp : 12");

    this->test_for_player_search.push_back("harold");
    this->test_for_player_search.push_back("room : mango");
    this->test_for_player_search.push_back("30 HP");

    this->test_for_room_display.push_back("mango | 4 players");
    this->test_for_room_display.push_back("potato | 2 players");
    this->test_for_room_display.push_back("porto | 1 players");
    this->test_for_room_display.push_back("diavolo | 3 players");

    this->test_for_room_search.push_back("first_player");
    this->test_for_room_search.push_back("second_player");
    this->test_for_room_search.push_back("third_player");
    this->test_for_room_search.push_back("fourth_player");
}

my_system::MagicSystem::~MagicSystem(void)
{
    _win.close();
    this->entities.clear();
    this->systems.clear();
}

void my_system::MagicSystem::init_systems(void)
{
    this->set<my_system::Draw>();
}

void my_system::MagicSystem::initialization()
{
    this->init_systems();
    this->init_entities_connection_menu();
}

void my_system::MagicSystem::run(void)
{
    /*for (long unsigned int i = 0; i < this->entities.size(); i++)
        if (entities[i].has<component::Music>())
            entities[i].get<component::Music>().play_music();*/
    while (_win.isOpen()) {
        _move_time = _move_clock.getElapsedTime();
        _animation_time = _animation_clock.getElapsedTime();
        _parallax_time = _parallax_clock.getElapsedTime();
        _shoot_time = _shoot_clock.getElapsedTime();
        while (_win.pollEvent(_event)) {
            this->manage_keyboard();
            if (_event.type == sf::Event::Closed)
                _win.close();
            for (auto it = this->systems.begin(); it != this->systems.end(); it++)
                for (long unsigned int i = 0; i < this->entities.size(); i++) {
                    if (event_manager.check_click(entities[i], _event, _mouse))
                        manage_button_pressing(entities[i].get<component::Clickable>().get_button_name());
                    if (entities[i].has<component::Movement>() && _move_time.asMilliseconds() >= 0.25) {
                        entities[i].get<component::Movement>().manage_input(entities[i], entities, i);
                        _move_clock.restart();
                    }
                }
        }
        _win.clear(sf::Color::Black);
        for (auto it = this->systems.begin(); it != this->systems.end(); it++) {
            for (long unsigned int i = 0; i < this->entities.size(); i++) {
                it->second->process(entities[i]);
                if (entities[i].has<component::Animation>()
                    && _animation_time.asMilliseconds() >= 0.3) {
                    entities[i].get<component::Animation>().animate(entities[i]);
                    _animation_clock.restart();
                }
                if (entities[i].has<component::Parallax>()
                    && _parallax_time.asMilliseconds() >= 0.15) {
                    float p = entities[i].get<component::Parallax>().get_parallax();
                    entities[i].get<component::Sprite>().update_pos(sf::Vector2f(-3 * p, 0)); 
                    if (entities[i].get<component::Sprite>().get_pos().x <= -1920)
                        entities[i].get<component::Sprite>().set_pos(1920, 0);
                    _parallax_clock.restart();
                }
                if (bullets.size() != 0) {
                    for (int j = 0; j < bullets.size(); j++) {
                        if (bullets[j].has<component::Shoot>())
                            _win.draw(bullets[j].get<component::Shoot>().get_sprite());
                    }
                }
                if (entities[i].has<component::Sprite>()) {
                    sf::Sprite s = entities[i].get<component::Sprite>().get_spr();
                    _win.draw(s);
                }
                else if (entities[i].has<component::Text_R>()) {
                    sf::Text t = entities[i].get<component::Text_R>().get_text();
                    _win.draw(t);
                }
            }
        }
        _win.display();
    }
}