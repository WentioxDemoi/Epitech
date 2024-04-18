#include "magicsystem.hpp"
#include "../factory/factory.hpp"
#include "../system/draw.hpp"

// KEYBOARDS INPUTS

void my_system::MagicSystem::manage_inputs()
{
        if (whichMenus == welcome_menu && sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
            whichMenus = hunter_re;
            this->init_entities_hunter_re();
        }
        if (whichMenus == hunter_re && sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            whichMenus = welcome_menu;
            this->init_entities_welcome_menu();
        }
    if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        entities.clear();
        _win.close();
        exit(0);
    }
    // à retirer, permet aux mac de passer les menus
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && whichMenus == welcome_menu) {
        whichMenus = connection_menu;
        this->init_entities_connection_menu();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && whichMenus == welcome_menu)
        this->init_entities_game_test();
    // c'est bon
    if (whichMenus == connection_menu)
        manage_keyboard_connection_menu();
    if (whichMenus == channel_menu)
        manage_keyboard_channel_menu();
    for (auto it = this->systems.begin(); it != this->systems.end(); it++)
        for (long unsigned int i = 0; i < this->entities.size(); i++) {
            if (event_manager.check_click(entities[i], _event, _mouse)) {
                if (whichMenus == welcome_menu && entities[i].get<component::Clickable>().get_button_name() == "exit") {
                    _win.close();
                    exit(0);
                }
                if (whichMenus == hunter_re and entities[i].get<component::Clickable>().get_button_name() == "hunter_re") {
                    entities.erase(entities.begin() + i);
                    hunter_re_spawn();
                }
                if (whichMenus == welcome_menu)
                    manage_button_pressing(entities[i].get<component::Clickable>().get_button_name());
                if (whichMenus == settings_menu && entities[i].has<component::Clickable>())
                    manage_button_settings_menu(entities[i].get<component::Clickable>().get_button_name());
                if (whichMenus == connection_menu && entities[i].has<component::Clickable>())
                    manage_button_connection_menu(entities[i].get<component::Clickable>().get_button_name());
            }
            if (entities[i].has<component::Movement>() && _move_time.asMilliseconds() >= 0.25) {
                entities[i].get<component::Movement>().manage_input(entities[i], entities, i, which_keyboard);
                _move_clock.restart();
            }
        }
}

//Welcome menu
void my_system::MagicSystem::manage_button_pressing(std::string button_name)
{
    if (button_name == "start" && this->whichMenus == welcome_menu) {
        whichMenus = connection_menu;
        this->init_entities_connection_menu();
    }
    if (button_name == "info" && this->whichMenus == welcome_menu) {
        //xdg-open --> Linux
        //start    --> Windows
        std::string op = std::string("xdg-open ").append("https://antoinerovini0.wixsite.com/r-type");
        system(op.c_str());
    }
    if (button_name == "settings" && this->whichMenus == welcome_menu) {
        whichMenus = settings_menu;
        this->init_entities_settings_menu();
    }
}

void my_system::MagicSystem::manage_button_settings_menu(std::string button_name)
{
    if (button_name == "back" && this->whichMenus == settings_menu) {
        whichMenus = welcome_menu;
        this->init_entities_welcome_menu();
    }
    if (button_name == "sound_down" && this->whichMenus == settings_menu)
        for (long unsigned int i = 0; i < this->musics_and_sounds.size(); i++)
            if (musics_and_sounds[i].has<component::Music>())
                musics_and_sounds[i].get<component::Music>().volume_down();
    if (button_name == "sound_up" && this->whichMenus == settings_menu)
        for (long unsigned int i = 0; i < this->musics_and_sounds.size(); i++)
            if (musics_and_sounds[i].has<component::Music>())
                musics_and_sounds[i].get<component::Music>().volume_up();
                
    if (button_name == "fps_down" && this->whichMenus == settings_menu
        and framerate > 30) {
        framerate -= 30;
        _win.setFramerateLimit(framerate);
    }
    if (button_name == "fps_up" && this->whichMenus == settings_menu
        and framerate < 120) {
        framerate += 30;
        _win.setFramerateLimit(framerate);
    }
    if ((button_name == "kb_down" or button_name == "kb_up") and this->whichMenus == settings_menu) {
        if (which_keyboard == 0)
            which_keyboard = 1;
        else if (which_keyboard == 1)
            which_keyboard = 0;
    }
}
//Connection to server
void my_system::MagicSystem::manage_keyboard_connection_menu(void)
{
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
        entities[15].get<component::Sprite>().set_pos(1920 / 5.5, 180);
    }
    if (which_data == 1) {
        entities[13].get<component::Text_R>().input_text(_event, 14, 0.4, true, true);
        entities[15].get<component::Sprite>().set_pos(1920 / 5.5, 480);
    }
    if (which_data == 2) {
        entities[14].get<component::Text_R>().input_text(_event, 4, 100, true, true);
        entities[15].get<component::Sprite>().set_pos(1920 / 5.5, 780);
    }
    if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Enter) {
        if (entities[14].get<component::Text_R>().get_string().size() != 0 &&
            entities[13].get<component::Text_R>().get_string().size() != 0 &&
            entities[12].get<component::Text_R>().get_string().size() != 0) {
            _player.name = entities[12].get<component::Text_R>().get_string();
            boost::system::error_code ec;
            ip_address = boost::asio::ip::address::from_string(entities[13].get<component::Text_R>().get_string(), ec);
            if (!ec && !_player._connected)
                entities[16].get<component::Text_R>().update_text(this->connection(entities[12].get<component::Text_R>().get_string(), entities[14].get<component::Text_R>().get_string()));
            else
                return;
        }
    }
    if (_player._connected) {
        this->whichMenus = channel_menu;
        this->init_entities_channel_menu();
    }
}

void my_system::MagicSystem::manage_button_connection_menu(std::string button_name)
{
    if (button_name == "back" and whichMenus == connection_menu) {
        this->whichMenus = welcome_menu;
        this->init_entities_welcome_menu();
    }
}

//Join or create lobby
void my_system::MagicSystem::manage_keyboard_channel_menu(void)
{
    if (this->private_room)
        _sent._private = 1;
    // ARROW
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Down) {
        if (this->which_data < 3)
            this->which_data++;
        else
            this->which_data = 0;
    } if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Up) {
        if (this->which_data > 0)
            this->which_data--;
        else
            this->which_data = 3;
    }
    // DATA MANAGEMENT
    if (which_data == 0) {
        entities[11].get<component::Text_R>().input_text(_event, 12, 0.33, false, false);
        entities[13].get<component::Sprite>().set_pos(1920 / 5.5, 180);
    }
    if (which_data == 1)
        entities[13].get<component::Sprite>().set_pos(1920 / 5.5, 350);
    if (which_data == 2) {
        entities[12].get<component::Text_R>().input_text(_event, 12, 0.33, false, false);
        entities[13].get<component::Sprite>().set_pos(1920 / 5.5, 580);
    }
    if (which_data == 3) {
        entities[13].get<component::Sprite>().set_pos(1920 / 5.5, 810);
    }
    if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Enter && this->which_data == 1) {
        if (this->private_room) {
            entities[16].get<component::Sprite>().update_texture("Assets/Images/Menu/Close_BTN.png");
            this->private_room = false;
            _sent._private = 0;
        }
        else {
            entities[16].get<component::Sprite>().update_texture("Assets/Images/Menu/Ok_BTN.png");
            this->private_room = true;
            _sent._private = 1;
        }
    }
    // DATA CHECKNG AND CONNECTION
    if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Enter && !_player._inLobby) {
        if (which_data == 0 && entities[11].get<component::Text_R>().get_string().size() != 0)
            this->create_room(entities[11].get<component::Text_R>().get_string());
        else if (which_data == 2 && entities[12].get<component::Text_R>().get_string().size() != 0)
            entities[14].get<component::Text_R>().update_text(this->join_room(entities[12].get<component::Text_R>().get_string()));
        else if (which_data == 3)
            this->autoRoom();
        if (_player._inLobby) {
            whichMenus = waiting_room;
            init_entities_waiting_room();
        }
    }
}

//Waiting room
void my_system::MagicSystem::manage_keyboard_waiting_room(void)
{
    std::string waiting_text = "Waiting for ";
    waiting_text += std::to_string(4 - _received._names4waitingroom.size());
    waiting_text += " player(s)...";
    entities[9].get<component::Text_R>().update_text(waiting_text);
    for (int i = 0; i < _received._names4waitingroom.size(); i++) {
        entities[11 + i].get<component::Text_R>().update_text(_received._names4waitingroom.at(i));
    }
    this->info_room(entities[12].get<component::Text_R>().get_string());
    if (_received._names4waitingroom.size() == 4) {
        _player.number = _received._position;
        whichMenus = rtype_room;
        init_entities_game();
    }
}

void my_system::MagicSystem::manage_keyboard_game_room()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->game_room(340, "UP");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->game_room(340, "DOWN");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->game_room(340, "LEFT");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->game_room(340, "RIGHT");

    for (int i = 0; i < 4; i++)
            entities[8 + i].get<component::Sprite>().set_pos(_received._posPlayer[i][0], _received._posPlayer[i][1]);
    for (int i = 0; i <= 3; i++) {
        this->entities[12 + i].get<component::Text_R>().update_pos
                (this->entities[8 + i].get<component::Sprite>().get_pos().x + 100,
                 this->entities[8 + i].get<component::Sprite>().get_pos().y - 2);
    }

    this->game_room(340, "POS");
    for (int i = 0; i < tmp_enemy.size(); i++) {
        tmp_enemy.at(i).at(0) = _received._infoEnemy[i][2][0];
        tmp_enemy.at(i).at(1) = _received._infoEnemy[i][2][1];
    }

    for (int i = 0; i < _received._die.size(); i++) {
        std::cout << "ENEMY DIE = " << _received._die[i] << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->game_room(340, "FIRE");
    if (this->bullets.size() != 0)
        this->bullets.clear();
    if (_received._posBullet.size() > 1) {
        for (int i = 0; i < _received._posBullet.size(); i++)
                this->bullets.push_back(Factory::create_shoot("Assets/Images/Shot/purple_shot.png"));
        for (int j = 0; j < _received._posBullet.size(); j++) {
            if (this->bullets[j].has<component::Shoot>())
                this->bullets[j].get<component::Shoot>().create_bullet(_received._posBullet[j]);
        }
    }
}

void my_system::MagicSystem::get_enemies_pos(void)
{
    for (int i = 0; i < this->enemies.size(); i++) {
        this->enemies[i].get<component::Enemy>().set_origin_pos(_received._infoEnemy[i][2]);
        this->enemies[i].get<component::Sprite>().set_pos(_received._infoEnemy[i][2][0], _received._infoEnemy[i][2][1]);
    }
}

void my_system::MagicSystem::get_enemies_info(void)
{
    if (this->_received._infoEnemy.size() != 0 && this->enemies.size() == 0) {
        for (int i = 0; i != this->_received._infoEnemy.size(); i++) {
            this->enemies.push_back(Factory::create_enemy(this->_received._infoEnemy[i]));
            tmp_enemy.push_back(this->_received._infoEnemy[i][2]);
        }
    }
}

void my_system::MagicSystem::enemies_dvd_movement(Entity enemy)
{
    if (enemy.get<component::Enemy>().get_origin_pos()[0] >
        enemy.get<component::Enemy>().get_min_placement()[0]
        and enemy.get<component::Enemy>().get_go_letf()) {
        enemy.get<component::Enemy>().update_pos_x(enemy.get<component::Enemy>().get_speed()[0] * -1);
        if (enemy.get<component::Enemy>().get_origin_pos()[0] <=
            enemy.get<component::Enemy>().get_min_placement()[0])
            enemy.get<component::Enemy>().set_go_letf(false);
    }    
    if (enemy.get<component::Enemy>().get_origin_pos()[1] <
        enemy.get<component::Enemy>().get_max_placement()[1]
        and enemy.get<component::Enemy>().get_go_down()) {
        enemy.get<component::Enemy>().update_pos_y(enemy.get<component::Enemy>().get_speed()[1]);
        if (enemy.get<component::Enemy>().get_origin_pos()[1] >=
            enemy.get<component::Enemy>().get_max_placement()[1])
            enemy.get<component::Enemy>().set_go_down(false);
    }    
    if (enemy.get<component::Enemy>().get_origin_pos()[0] <
        enemy.get<component::Enemy>().get_max_placement()[0]
        and !enemy.get<component::Enemy>().get_go_letf()) {
        enemy.get<component::Enemy>().update_pos_x(enemy.get<component::Enemy>().get_speed()[0]);
        if (enemy.get<component::Enemy>().get_origin_pos()[0] >=
            enemy.get<component::Enemy>().get_max_placement()[0])
            enemy.get<component::Enemy>().set_go_letf(true);
    }
    if (enemy.get<component::Enemy>().get_origin_pos()[1] >
        enemy.get<component::Enemy>().get_min_placement()[1]
        and !enemy.get<component::Enemy>().get_go_down()) {
        enemy.get<component::Enemy>().update_pos_y(enemy.get<component::Enemy>().get_speed()[1] * -1);
        if (enemy.get<component::Enemy>().get_origin_pos()[1] <=
            enemy.get<component::Enemy>().get_min_placement()[1])
            enemy.get<component::Enemy>().set_go_down(true);
    }
    enemy.get<component::Sprite>().set_pos(enemy.get<component::Enemy>().get_origin_pos()[0], enemy.get<component::Enemy>().get_origin_pos()[1]);
}

void my_system::MagicSystem::hunter_re_spawn(void)
{
    int side;
    float x;
    float y = rand() % (900 - 200 + 1) + 100;

    side = rand() % 2;
    if (side == 0) {
        x = 2020;
        this->entities.push_back(Factory::create_hunter_re("Assets/Images/Enemies/Ship_01.png", x, y, 0.15));
    }
    else {
        x = -100;
        this->entities.push_back(Factory::create_hunter_re("Assets/Images/Enemies/Ship_02.png", x, y, 0.15));
    }
}

my_system::MagicSystem::MagicSystem(const int &screenWidth, const int &screenHeight, const char *name)
{
    _win.create(sf::VideoMode(screenWidth, screenHeight), name);
    _win.setPosition(sf::Vector2i(0, 0)); 
    _win.setFramerateLimit(60);
    this->framerate = 60;

    this->which_keyboard = 0;
    this->whichMenus = welcome_menu;
    this->which_data = 0;
    this->private_room = true;

    _player._connected = false;
    _player._inLobby = false;
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
    this->init_entities_welcome_menu();
    this->musics_and_sounds.push_back(Factory::create_music("Assets/Music/music_random.ogg", true));
}

void my_system::MagicSystem::manage_entities()
{
    bool unreceived = true;
    for (auto it = this->systems.begin(); it != this->systems.end(); it++) {
        for (long unsigned int i = 0; i < this->entities.size(); i++) {
            it->second->process(entities[i]);
            if (entities[i].has<component::Animation>()
                && _animation_time.asMilliseconds() >= 1) {
                entities[i].get<component::Animation>().animate(entities[i]);
                _animation_clock.restart();
            }
            if (whichMenus == hunter_re and entities[i].has<component::Sprite>()
                and entities[i].has<component::Clickable>() and _hunter_time.asMilliseconds() >= 0.35) {
                    if (entities[i].get<component::Sprite>().get_spritepath() == "Assets/Images/Enemies/Ship_01.png")
                        entities[i].get<component::Sprite>().set_pos(entities[i].get<component::Sprite>().get_pos().x - 10, entities[i].get<component::Sprite>().get_pos().y);
                    else
                        entities[i].get<component::Sprite>().set_pos(entities[i].get<component::Sprite>().get_pos().x + 10, entities[i].get<component::Sprite>().get_pos().y);
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
                if (whichMenus == settings_menu and entities[i].get<component::Text_R>().get_pos().y == 200)
                    for (long unsigned int j = 0; j < this->musics_and_sounds.size(); j++)
                        if (musics_and_sounds[j].has<component::Music>()) {
                            int v = musics_and_sounds[j].get<component::Music>().get_volume();
                            std::string s = std::to_string(v);
                            entities[i].get<component::Text_R>().set_string(s);
                        }
                if (whichMenus == settings_menu and entities[i].get<component::Text_R>().get_pos().y == 400
                    and entities[i].get<component::Text_R>().get_pos().x == 750) {
                    std::string s = std::to_string(framerate);
                    entities[i].get<component::Text_R>().set_string(s);
                }
                if (whichMenus == settings_menu and entities[i].get<component::Text_R>().get_pos().y == 600) {
                    if (which_keyboard == 0)
                        entities[i].get<component::Text_R>().set_string("^<>v");
                    else if (which_keyboard == 1)
                        entities[i].get<component::Text_R>().set_string("ZQSD");
                }
                sf::Text t = entities[i].get<component::Text_R>().get_text();
                _win.draw(t);
            }
        }

        if (enemies.size() != 0 and whichMenus != waiting_room) {
            for (int e = 0; e != enemies.size(); e++) {
                if (enemies[e].has<component::Enemy>()
                    and _enemies_time.asMilliseconds() >= 0.3) {
                    // l'un ou l'autre
                    enemies_dvd_movement(enemies[e]);
                    for (int i = 0; i < tmp_enemy.size(); i++) {
                        if (tmp_enemy.at(i).at(0) != _received._infoEnemy[i][2][0] || tmp_enemy.at(i).at(1) != _received._infoEnemy[i][2][1])
                            unreceived = false;
                    }
                    if (!unreceived)
                        get_enemies_pos();
                    for (int i = 0; i < tmp_enemy.size(); i++) {
                        tmp_enemy.at(i).at(0) = enemies[e].get<component::Enemy>().get_origin_pos().at(0);
                        tmp_enemy.at(i).at(1) = enemies[e].get<component::Enemy>().get_origin_pos().at(0);
                    }
                    _enemies_clock.restart();
                }
                if (enemies[e].has<component::Sprite>()) {
                    if (checkDie(e) == 0) {
                        sf::Sprite s = enemies[e].get<component::Sprite>().get_spr();
                        _win.draw(s);
                    }
                }
            }
        }
    }
}

int my_system::MagicSystem::checkDie(int e)
{
    if (_received._die.size() == 0)
        return (0);
    for (int i = 0; i < _received._die.size(); i++) {
        if (_received._die[i] == e)
            return (1);
    }
    return (0);
}

void my_system::MagicSystem::run(void)
{
    for (long unsigned int i = 0; i < this->musics_and_sounds.size(); i++)
        if (musics_and_sounds[i].has<component::Music>())
            musics_and_sounds[i].get<component::Music>().play_music();
    while (_win.isOpen()) {
        // here for fluidity issues (not blocked by event)
        if (whichMenus == waiting_room) {
            manage_keyboard_waiting_room();
            get_enemies_info();
        }
        if (whichMenus == rtype_room)
            manage_keyboard_game_room();
        _move_time = _move_clock.getElapsedTime();
        _animation_time = _animation_clock.getElapsedTime();
        _parallax_time = _parallax_clock.getElapsedTime();
        _enemies_time = _enemies_clock.getElapsedTime();
        _hunter_time = _hunter_clock.getElapsedTime();
        while (_win.pollEvent(_event)) {
            manage_inputs();
        }
        _win.clear(sf::Color::Black);
        manage_entities();
        _win.display();
    }
}