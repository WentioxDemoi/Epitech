#include "PlayerEntity.hpp"

PlayerEntity::PlayerEntity()
{

}

PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::createClient(udp::endpoint _endpoint, std::string _name)
{
    AddPlayerComponent(_endpoint, _name);
    setConnectionPlayerComponent(true);
    setHpPlayerComponent(100);
}

void PlayerEntity::connectLobbyClient(std::string _nameLobby)
{
    setLobbyNamePlayerComponent(_nameLobby);
    setConnectionLobbyPlayerComponent(true);
}

void PlayerEntity::AddPlayerComponent(udp::endpoint _endpoint, std::string _name)
{
    std::shared_ptr<PlayerComponent> _player = std::make_shared<PlayerComponent>(_endpoint, _name);
    m_components.push_back(_player);
}

void PlayerEntity::setConnectionPlayerComponent(bool connected)
{
    m_components[0]->setConnectionPlayer(connected);
}

void PlayerEntity::setConnectionLobbyPlayerComponent(bool connected)
{
    m_components[0]->setConnectionLobbyPlayer(connected);
}

void PlayerEntity::setLobbyNamePlayerComponent(std::string _nameLobby)
{
    m_components[0]->setLobbyNamePlayer(_nameLobby);
}

void PlayerEntity::setPositionPlayerComponent(float x, float y)
{
    m_components[0]->setPositionPlayer(x, y);
}

void PlayerEntity::setLobbyNumberPlayerComponent(int number)
{
    m_components[0]->setLobbyNumberPlayer(number);
}

void PlayerEntity::setTimeFirePlayerComponent()
{
    m_components[0]->setTimeFirePlayer();
}

void PlayerEntity::setHpPlayerComponent(int hp)
{
    m_components[0]->setHpPlayer(hp);
}

int PlayerEntity::getHpPlayerComponent()
{
    return (m_components[0]->getHpPlayer());
}

time_t PlayerEntity::getTimeFirePlayerComponent()
{
    return (m_components[0]->getTimeFirePlayer());
}

udp::endpoint PlayerEntity::getEndpointPlayerComponent()
{
    return (m_components[0]->getEndpointPlayer());
}

bool PlayerEntity::getConnectionPlayerComponent()
{
    return (m_components[0]->getConnectionPlayer());
}

std::string PlayerEntity::getLobbyNamePlayerComponent()
{
    return (m_components[0]->getLobbyNamePlayer());
}

std::string PlayerEntity::getNamePlayerComponent()
{
    return (m_components[0]->getNamePlayer());
}

bool PlayerEntity::getConnectionLobbyPlayerComponent()
{
    return (m_components[0]->getConnectionLobbyPlayer());
}

int PlayerEntity::getLobbyNumberPlayerComponent()
{
    return (m_components[0]->getLobbyNumberPlayer());
}

float PlayerEntity::getPositionPlayerXComponent()
{
    return (m_components[0]->getPositionPlayerX());
}

float PlayerEntity::getPositionPlayerYComponent()
{
    return (m_components[0]->getPositionPlayerY());
}