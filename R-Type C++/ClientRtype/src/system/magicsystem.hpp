#pragma once

#include "ISystem.hpp"
#include "../Event.hpp"
#include "../Network.hpp"

namespace my_system
{

    enum which_menus
    {
        welcome_menu,
        settings_menu,
        connection_menu,
        channel_menu,
        waiting_room,
        rtype_room,
        hunter_re
    };

    class MagicSystem : public Network
    {
        public:
            MagicSystem(const int &screenWidth, const int &screenHeight, const char *name);
            ~MagicSystem();
            void run();
            void initialization();
            void init_entities();
            void init_systems();

            void init_entities_welcome_menu();
            void init_entities_settings_menu();
            void init_entities_info_menu();
            void init_entities_connection_menu();
            void init_entities_channel_menu();
            void init_entities_waiting_room();
            void init_entities_game();
            void init_entities_game_test();
            void init_entities_hunter_re();
            void manage_inputs(void);
            void manage_entities(void);
            void manage_button_pressing(std::string button_name);
            void manage_button_info_menu(std::string button_name);
            void manage_button_settings_menu(std::string button_name);
            void manage_keyboard_connection_menu(void);
            void manage_button_connection_menu(std::string button_name);
            void manage_keyboard_channel_menu(void);
            void manage_keyboard_waiting_room(void);
            void manage_keyboard_game_room(void);
            void manage_keyboard_input(void);
            void get_enemies_info(void);
            int checkDie(int e);
            void get_enemies_pos(void);
            void enemies_dvd_movement(Entity enemy);
            void hunter_re_spawn(void);

            template <typename T, typename... Args>
            T &set(Args &&...args)
            {
                systems[typeid(T)] = std::make_shared<T>(std::forward<Args>(args)...);
                return get<T>();
            }

            template <typename T>
            bool has()
            {
                return systems.find(typeid(T)) != systems.end();
            }

            template <typename T>
            T &get()
            {
                if (has<T>())
                    return *std::static_pointer_cast<T>(systems[typeid(T)]).get();
                else
                    throw;
            }

            template <typename T>
            void remove()
            {
                systems.erase(typeid(T));
            }

        private:
            std::vector<Entity> entities;
            std::vector<Entity> bullets;
            std::vector<Entity> enemies;
            std::vector<Entity> musics_and_sounds;
            std::vector<std::vector<float>> tmp_enemy;
            std::map<std::type_index, std::shared_ptr<ISystem>> systems;
            sf::RenderWindow _win;
            int framerate;
            int which_keyboard;
            Event event_manager;
            sf::Event _event;
            sf::Mouse _mouse;
            sf::Clock _parallax_clock;
            sf::Time _parallax_time;
            sf::Clock _move_clock;
            sf::Time _move_time;
            sf::Clock _animation_clock;
            sf::Time _animation_time;
            sf::Clock _shoot_clock;
            sf::Time _shoot_time;
            sf::Clock _enemies_clock;
            sf::Time _enemies_time;
            sf::Clock _hunter_clock;
            sf::Time _hunter_time;

            which_menus whichMenus;
            int which_data;
            bool private_room;
            std::string name;

            std::vector<std::string> player_names;
    };
};