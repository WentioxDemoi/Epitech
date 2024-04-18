#include "EnemyEntity.hpp"

EnemyEntity::EnemyEntity()
{

}

EnemyEntity::~EnemyEntity()
{

}

void EnemyEntity::AddEnemyComponent(std::string name)
{
    std::shared_ptr<EnemyComponent> _enemy = std::make_shared<EnemyComponent>(name);
    m_components.push_back(_enemy);
}

void EnemyEntity::setDammageEnemyComponent(int damage)
{
    m_components[0]->setDammageEnemy(damage);
}

void EnemyEntity::setHpEnemyComponent(int hp)
{
    m_components[0]->setHpEnemy(hp);
}

void EnemyEntity::setEndpointEnemyComponent(udp::endpoint endpoint)
{
    m_components[0]->setEndpointEnemy(endpoint);
}

void EnemyEntity::setLobbyEnemyComponent(std::string name)
{
    m_components[0]->setLobbyEnemy(name);
}

void EnemyEntity::setMaxPlacementEnemyComponent(std::vector<float> max_placement)
{
    m_components[0]->setMaxPlacementEnemy(max_placement);
}

void EnemyEntity::setMinPlacementEnemyComponent(std::vector<float> min_placement)
{
    m_components[0]->setMinPlacementEnemy(min_placement);
}

void EnemyEntity::setPosEnemyComponent(std::vector<float> pos)
{
    m_components[0]->setPosEnemy(pos);
}

void EnemyEntity::setSpeedEnemyComponent(std::vector<float> speed)
{
    m_components[0]->setSpeedEnemy(speed);
}

void EnemyEntity::setLeftEnemyComponent(bool left)
{
    m_components[0]->setLeftEnemy(left);
}

void EnemyEntity::setDownEnemyComponent(bool down)
{
    m_components[0]->setDownEnemy(down);
}

void EnemyEntity::setIdEnemyComponent(int id)
{
    m_components[0]->setIdEnemy(id);
}

void EnemyEntity::setLifeEnemyComponent(bool life)
{
    m_components[0]->setLifeEnemy(life);
}

bool EnemyEntity::getLifeEnemyComponent()
{
    return (m_components[0]->getLifeEnemy());
}

int EnemyEntity::getIdEnemyComponent()
{
    return (m_components[0]->getIdEnemy());
}

bool EnemyEntity::getLeftEnemyComponent()
{
    return (m_components[0]->getLeftEnemy());
}

bool EnemyEntity::getDownEnemyComponent()
{
    return (m_components[0]->getDownEnemy());
}

std::vector<float> EnemyEntity::getMaxPlacementEnemyComponent()
{
    return (m_components[0]->getMaxPlacementEnemy());
}

std::vector<float> EnemyEntity::getMinPlacementEnemyComponent()
{
    return (m_components[0]->getMinPlacementEnemy());
}

std::vector<float> EnemyEntity::getPosEnemyComponent()
{
    return (m_components[0]->getPosEnemy());
}

std::vector<float> EnemyEntity::getSpeedEnemyComponent()
{
    return (m_components[0]->getSpeedEnemy());
}

std::string EnemyEntity::getLobbyEnemyComponent()
{
    return (m_components[0]->getLobbyEnemy());
}

int EnemyEntity::getDamageEnemyComponent()
{
    return (m_components[0]->getDamageEnemy());
}

int EnemyEntity::getHpEnemyComponent()
{
    return (m_components[0]->getHpEnemy());
}