#include "../Entity.hpp"
#include "position.hpp"
#include "draw.hpp"
#include "sprite.hpp"
#include "collision.hpp"
#include "enemy.hpp"

component::Enemy::Enemy(std::vector<std::vector<float>> info)
{
    this->go_left = true;
    this->go_down = true;
    this->max_placement.push_back(info[0][0]);
    this->max_placement.push_back(info[0][1]);
    this->min_placement.push_back(info[1][0]);
    this->min_placement.push_back(info[1][1]);
    this->origin_pos.push_back(info[2][0]);
    this->origin_pos.push_back(info[2][1]);
    this->speed.push_back(info[3][0]);
    this->speed.push_back(info[3][1]);
}

bool component::Enemy::get_go_letf(void) const
{
    return this->go_left;
}

bool component::Enemy::get_go_down(void) const
{
    return this->go_down;
}

void component::Enemy::set_go_letf(bool status)
{
    this->go_left = status;
}

void component::Enemy::set_go_down(bool status)
{
    this->go_down = status;
}

std::vector<float> component::Enemy::get_min_placement(void) const
{
    return this->min_placement;
}

std::vector<float> component::Enemy::get_max_placement(void) const
{
    return this->max_placement;
}

std::vector<float> component::Enemy::get_origin_pos(void) const
{
    return this->origin_pos;
}

std::vector<float> component::Enemy::get_speed(void) const
{
    return this->speed;
}

void component::Enemy::set_min_placement(std::vector<float> min_placement)
{
    this->min_placement = min_placement;
}

void component::Enemy::set_max_placement(std::vector<float> max_placement)
{
    this->max_placement = max_placement;
}

void component::Enemy::set_origin_pos(std::vector<float> pos)
{
    this->origin_pos = pos;
}

void component::Enemy::set_speed(std::vector<float> speed)
{
    this->speed = speed;
}

void component::Enemy::update_pos_x(float speed)
{
    this->origin_pos[0] += speed;
}

void component::Enemy::update_pos_y(float speed)
{
    this->origin_pos[1] += speed;
}

void component::Enemy::kill_enemy(Entity e)
{
    e.remove<component::Position>();
    e.remove<component::Draw>();
    e.remove<component::Sprite>();
    e.remove<component::Collision>();
    e.remove<component::Enemy>();
}