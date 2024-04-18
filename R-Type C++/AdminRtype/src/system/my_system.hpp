#pragma once

#include "ISystem.hpp"
#include "../Network.hpp"

namespace my_system
{
    enum which_menus
    {
        welcome_menu,
        settings_menu,
        info_menu,
        connection_menu,
        channel_menu,
        waiting_room,
        rtype_room
    };

    class MagicSystem
    {
        public:
            MagicSystem(const int &screenWidth, const int &screenHeight, const char *name);
            ~MagicSystem();
            void run();
            void initialization();
            void init_entities();

            void init_entities_welcome_menu();
            void init_entities_settings_menu();
            void init_entities_info_menu();
            void init_entities_connection_menu();
            void init_entities_channel_menu();
            void init_entities_waiting_room();
            void init_entities_game();
            void init_systems();

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
            std::map<std::type_index, std::shared_ptr<ISystem>> systems;
            which_menus whichMenus;
            int which_data;
            sf::RenderWindow _win;
            sf::Event _event;
            sf::Mouse _mouse;
            std::string name;
    };
};