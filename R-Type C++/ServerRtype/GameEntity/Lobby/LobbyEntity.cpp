#include "LobbyEntity.hpp"

LobbyEntity::LobbyEntity()
{

}

LobbyEntity::~LobbyEntity()
{

}

void LobbyEntity::createLobbyEntity(udp::endpoint _endpoint, std::string _namePlayer, std::string _nameLobby, int _privateLobby)
{
    createLobbyComponent(_nameLobby);
    setEndpointPlayerComponent(_endpoint);
    setNamesPlayersComponent(_namePlayer);
    setNumberPlayersComponent(1);
    setLobbyPrivateComponent(_privateLobby);
}

void LobbyEntity::joinLobbyEntity(udp::endpoint _endpoint, std::string _namePlayer)
{
    setEndpointPlayerComponent(_endpoint);
    setNamesPlayersComponent(_namePlayer);
    setNumberPlayersComponent(1);
}

void LobbyEntity::createLobbyComponent(std::string _name)
{
    std::shared_ptr<LobbyComponent> _lobby = std::make_shared<LobbyComponent>(_name);
    m_components.push_back(_lobby);
}

void LobbyEntity::setNumberPlayersComponent(int x)
{
    m_components[0]->setNumberPlayers(x);
}

void LobbyEntity::setNamesPlayersComponent(std::string name)
{
    m_components[0]->setNamesPlayers(name);
}

void LobbyEntity::setEndpointPlayerComponent(udp::endpoint endpoint)
{
    m_components[0]->setEndpointPlayer(endpoint);
}

void LobbyEntity::setLobbyPrivateComponent(int check)
{
    m_components[0]->setLobbyPrivate(check);
}

bool LobbyEntity::getLobbyPrivateComponent(void)
{
    return (m_components[0]->getLobbyPrivate());
}

int LobbyEntity::getNumberPlayersComponent(void)
{
    return (m_components[0]->getNumberPlayers());
}

std::vector<std::string> LobbyEntity::getPlayersNamesComponent(void)
{
    return (m_components[0]->getPlayersNames());
}

std::string LobbyEntity::getLobbyNameComponent(void)
{
    return (m_components[0]->getLobbyName());
}

std::vector<udp::endpoint> LobbyEntity::getEndpointPlayerComponent()
{
    return (m_components[0]->getEndpointPlayer());
}

void LobbyEntity::deletePlayerNameComponent(std::string name)
{

}