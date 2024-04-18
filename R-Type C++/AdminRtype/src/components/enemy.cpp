#include "../Entity.hpp"
#include "position.hpp"
#include "draw.hpp"
#include "sprite.hpp"
#include "collision.hpp"
#include "enemy.hpp"

void component::Enemy::kill_enemy(Entity e)
{
    e.remove<component::Position>();
    e.remove<component::Draw>();
    e.remove<component::Sprite>();
    e.remove<component::Collision>();
    e.remove<component::Enemy>();
}