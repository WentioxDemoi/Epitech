#include "Enemy.hpp"

EnemyComponent::EnemyComponent(std::string name)
{

}

EnemyComponent::~EnemyComponent()
{

}

void EnemyComponent::setPositionEnemy(float x, float y)
{
    _x = x;
    _y = y;
}

void EnemyComponent::setDammageEnemy(int damage)
{
    _dmg = damage;
}

void EnemyComponent::setHpEnemy(int hp)
{
    _hp = hp;
}

void EnemyComponent::setLobbyEnemy(std::string name)
{
    _name = name;
}

void EnemyComponent::setEndpointEnemy(udp::endpoint endpoint)
{
    _endpoint = endpoint;
}

void EnemyComponent::setMaxPlacementEnemy(std::vector<float> max_placement)
{
    _max_placement = max_placement;
}

void EnemyComponent::setMinPlacementEnemy(std::vector<float> min_placement)
{
    _min_placement = min_placement;
}

void EnemyComponent::setPosEnemy(std::vector<float> pos)
{
    _pos = pos;
}

void EnemyComponent::setSpeedEnemy(std::vector<float> speed)
{
    _speed = speed;
}

void EnemyComponent::setLeftEnemy(bool left)
{
    _left = left;
}

void EnemyComponent::setDownEnemy(bool down)
{
    _down = down;
}

void EnemyComponent::setIdEnemy(int id)
{
    _id = id;
}

void EnemyComponent::setLifeEnemy(bool life)
{
    _life = life;
}

bool EnemyComponent::getLifeEnemy()
{
    return (_life);
}

int EnemyComponent::getIdEnemy()
{
    return (_id);
}

bool EnemyComponent::getLeftEnemy()
{
    return (_left);
}

bool EnemyComponent::getDownEnemy()
{
    return (_down);
}

std::vector<float> EnemyComponent::getMaxPlacementEnemy()
{
    return (_max_placement);
}

std::vector<float> EnemyComponent::getMinPlacementEnemy()
{
    return (_min_placement);
}

std::vector<float> EnemyComponent::getPosEnemy()
{
    return (_pos);
}

std::vector<float> EnemyComponent::getSpeedEnemy()
{
    return (_speed);
}

udp::endpoint EnemyComponent::getEndpointEnemy()
{
    return (_endpoint);
}

double EnemyComponent::getPositionEnemyX()
{
    return (_x);
}

double EnemyComponent::getPositionEnemyY()
{
    return (_y);
}

int EnemyComponent::getDamageEnemy()
{
    return (_dmg);
}

int EnemyComponent::getHpEnemy()
{
    return (_hp);
}

std::string EnemyComponent::getLobbyEnemy()
{
    return (_name);
}