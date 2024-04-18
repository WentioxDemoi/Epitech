#pragma once

#include "ISystem.hpp"
#include "../Event.hpp"
#include "../Network.hpp"

namespace my_system {
    enum which_menus {
        connection_room,
        selection_room,
        solo_room_room,
        all_rooms_room,
        players_room,
        solo_player_room,
        spectate_room
    };

    class MagicSystem : public Network {
    public:
        MagicSystem(const int &screenWidth, const int &screenHeight, const char *name);

        ~MagicSystem();

        void run();

        void initialization();

        void init_entities();

        void init_systems();

        void init_entities_connection_menu();

        void manage_selection_menu();

        void init_entities_selection_room();

        void init_entities_solo_room();

        void init_entities_all_rooms();

        void init_entities_players_room();

        void init_entities_solo_player_room();

        void init_entities_spectate_room();

        void init_entities_game();

        void init_entities_game_test();

        void manage_button_pressing(std::string button_name);

        void manage_keyboard(void);

        void manage_keyboard_connection_menu(void);

        void manage_keyboard_selection_menu(void);

        void manage_keyboard_solo_player(void);

        void manage_keyboard_solo_room(void);

        void manage_keyboard_player_iteration(void);

        void manage_keyboard_all_rooms(void);

        template<typename T, typename... Args>
        T &set(Args &&...args) {
            systems[typeid(T)] = std::make_shared<T>(std::forward<Args>(args)...);
            return get<T>();
        }

        template<typename T>
        bool has() {
            return systems.find(typeid(T)) != systems.end();
        }

        template<typename T>
        T &get() {
            if (has<T>())
                return *std::static_pointer_cast<T>(systems[typeid(T)]).get();
            else
                throw;
        }

        template<typename T>
        void remove() {
            systems.erase(typeid(T));
        }

    private:
        std::vector <Entity> entities;
        std::vector <Entity> bullets;
        std::map <std::type_index, std::shared_ptr<ISystem>> systems;
        sf::RenderWindow _win;
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

        which_menus whichMenus;
        int which_data;
        bool speedy;
        std::string name;

        std::vector <std::string> player_names;

        // ici, les variables à déplacer
        std::vector <std::string> test_for_player_iteration_search; // pour les itérations
        std::vector <std::string> test_for_room_display; // pour toutes les rooms
        std::vector <std::string> test_for_player_search; // la recherche d'un seul joueur
        std::vector <std::string> test_for_room_search; // la recherche d'une seule room
    };
};