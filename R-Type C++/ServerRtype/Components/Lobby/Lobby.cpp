#include "Lobby.hpp"

LobbyComponent::LobbyComponent(std::string _name)
{
    _lobbyName = _name;
    _nb_players = 0;
}

LobbyComponent::~LobbyComponent()
{

}

void test()
{

}

void LobbyComponent::createLobby()
{

}

void LobbyComponent::setNumberPlayers(int x)
{
    this->_nb_players += x;
}

void LobbyComponent::setNamesPlayers(std::string name)
{
    this->_playersNames.push_back(name);
}

void LobbyComponent::setEndpointPlayer(udp::endpoint endpoint)
{
    _endpoint.push_back(endpoint);
}

void LobbyComponent::setLobbyPrivate(int check)
{
    if (check == 1)
        _ifPrivate = true;
    else
        _ifPrivate = false;
}

bool LobbyComponent::getLobbyPrivate()
{
    return (this->_ifPrivate);
}

int LobbyComponent::getNumberPlayers(void)
{
    return (this->_nb_players);
}

std::vector<std::string> LobbyComponent::getPlayersNames(void)
{
    return(this->_playersNames);
}

std::string LobbyComponent::getLobbyName(void)
{
    return(this->_lobbyName);
}

std::vector<udp::endpoint> LobbyComponent::getEndpointPlayer()
{
    return (this->_endpoint);
}

void LobbyComponent::deletePlayerName(std::string name)
{
    int i = 0;
    while (i < this->_playersNames.size()) {
        if (this->_playersNames.at(i).compare(name) == 0)
            this->_playersNames.erase(this->_playersNames.begin() + i) ;
    }
}