#include "collision.hpp"
#include "sprite.hpp"

bool component::Collision::check_collision_up(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count)
{
    for (long unsigned int i = 0; i < tab_e.size(); i++)
        if (i != e_count && tab_e[i].has<component::Collision>()
            && tab_e[i].has<component::Sprite>() && pos.y - size.y < tab_e[i].get<component::Sprite>().get_pos().y
            && pos.y > tab_e[i].get<component::Sprite>().get_pos().y
            && pos.x + size.x >= tab_e[i].get<component::Sprite>().get_pos().x &&
            pos.x <= tab_e[i].get<component::Sprite>().get_pos().x + tab_e[i].get<component::Sprite>().get_size().x)
            return true;
    return false;
}

bool component::Collision::check_collision_down(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count)
{
    for (long unsigned int i = 0; i < tab_e.size(); i++)
        if (i != e_count && tab_e[i].has<component::Collision>()
            && tab_e[i].has<component::Sprite>() && pos.y + size.y > tab_e[i].get<component::Sprite>().get_pos().y
            && pos.y < tab_e[i].get<component::Sprite>().get_pos().y
            && pos.x + size.x >= tab_e[i].get<component::Sprite>().get_pos().x &&
            pos.x <= tab_e[i].get<component::Sprite>().get_pos().x + tab_e[i].get<component::Sprite>().get_size().x)
            return true;
    return false;
}

bool component::Collision::check_collision_left(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count)
{
    for (long unsigned int i = 0; i < tab_e.size(); i++)
        if (i != e_count && tab_e[i].has<component::Collision>()
            && tab_e[i].has<component::Sprite>() && pos.x < tab_e[i].get<component::Sprite>().get_pos().x + tab_e[i].get<component::Sprite>().get_size().x
            && pos.x > tab_e[i].get<component::Sprite>().get_pos().x
            && pos.y + size.y >= tab_e[i].get<component::Sprite>().get_pos().y &&
            pos.y <= tab_e[i].get<component::Sprite>().get_pos().y + tab_e[i].get<component::Sprite>().get_size().y)
            return true;
    return false;
}

bool component::Collision::check_collision_right(sf::Vector2f pos, sf::Vector2f size, std::vector<Entity> tab_e, int e_count)
{
    for (long unsigned int i = 0; i < tab_e.size(); i++)
        if (i != e_count && tab_e[i].has<component::Collision>()
            && tab_e[i].has<component::Sprite>() &&
            pos.x > tab_e[i].get<component::Sprite>().get_pos().x - (tab_e[i].get<component::Sprite>().get_size().x * 1.5)
            && pos.x < tab_e[i].get<component::Sprite>().get_pos().x
            && pos.y + size.y >= tab_e[i].get<component::Sprite>().get_pos().y &&
            pos.y <= tab_e[i].get<component::Sprite>().get_pos().y + tab_e[i].get<component::Sprite>().get_size().y)
            return true;
    return false;
}