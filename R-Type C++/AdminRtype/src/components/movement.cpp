#include "movement.hpp"
#include "sprite.hpp"
#include "collision.hpp"

component::Movement::Movement()
{
    _v = 2.5;
    _a = 1;
    /*key_tab.push_back(sf::Keyboard::Z);
    key_tab.push_back(sf::Keyboard::S);
    key_tab.push_back(sf::Keyboard::Q);
    key_tab.push_back(sf::Keyboard::D);*/
    key_tab.push_back(sf::Keyboard::Up);
    key_tab.push_back(sf::Keyboard::Down);
    key_tab.push_back(sf::Keyboard::Left);
    key_tab.push_back(sf::Keyboard::Right);
}

void component::Movement::move_x(Entity e, int dir)
{
    e.get<component::Sprite>().update_move(sf::Vector2f((_v * _a) * dir, 0));
}

void component::Movement::move_y(Entity e, int dir)
{
    e.get<component::Sprite>().update_move(sf::Vector2f(0, (_v * _a) * dir));
}

void component::Movement::manage_input(Entity e, std::vector<Entity> tab_e, int e_count)
{
    for (int i = e_keys::k_up; i != e_keys::k_d; i++) {
        if ((sf::Keyboard::isKeyPressed(key_tab[0]))
            && !e.get<component::Collision>().check_collision_up(e.get<component::Sprite>().get_pos(), e.get<component::Sprite>().get_size(), tab_e, e_count)
            && e.get<component::Sprite>().get_pos().y > 50)
            this->move_y(e, -1);
        if ((sf::Keyboard::isKeyPressed(key_tab[1]))
            && !e.get<component::Collision>().check_collision_down(e.get<component::Sprite>().get_pos(), e.get<component::Sprite>().get_size(), tab_e, e_count)
            && e.get<component::Sprite>().get_pos().y + e.get<component::Sprite>().get_size().y < 970)
            this->move_y(e, 1);
        if ((sf::Keyboard::isKeyPressed(key_tab[2]))
            && !e.get<component::Collision>().check_collision_left(e.get<component::Sprite>().get_pos(), e.get<component::Sprite>().get_size(), tab_e, e_count)
            && e.get<component::Sprite>().get_pos().x > 50)
            this->move_x(e, -1);
        if ((sf::Keyboard::isKeyPressed(key_tab[3]))
            && !e.get<component::Collision>().check_collision_right(e.get<component::Sprite>().get_pos(), e.get<component::Sprite>().get_size(), tab_e, e_count)
            && e.get<component::Sprite>().get_pos().x + e.get<component::Sprite>().get_size().x < 1820)
            this->move_x(e, 1);
    }
}