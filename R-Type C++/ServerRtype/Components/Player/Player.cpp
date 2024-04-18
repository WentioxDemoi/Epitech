#include "Player.hpp"

PlayerComponent::PlayerComponent(udp::endpoint _endpoint, std::string _name)
{
    this->_name = _name;
    this->_endpoint = _endpoint;
    this->_scene = 1;
    this->_connectedLobby = false;
}

PlayerComponent::~PlayerComponent()
{

}

void PlayerComponent::setPositionPlayer(float x, float y)
{
    this->_x = x;
    this->_y = y;
}

void PlayerComponent::setConnectionLobbyPlayer(bool connected)
{
    _connectedLobby = connected;
}

void PlayerComponent::setConnectionPlayer(bool connected)
{
    _connected = connected;
}

void PlayerComponent::setLobbyNamePlayer(std::string _lobbyNameTmp)
{
    _lobbyName = _lobbyNameTmp;
}

void PlayerComponent::setLobbyNumberPlayer(int number)
{
    _playerNumber  = number;
}

void PlayerComponent::setTimeFirePlayer()
{
    _start = time(NULL);
}

void PlayerComponent::setHpPlayer(int hp)
{
    _hp = hp;
}

int PlayerComponent::getHpPlayer()
{
    return (_hp);
}

time_t PlayerComponent::getTimeFirePlayer()
{
    return (_start);
}

std::string PlayerComponent::getLobbyNamePlayer()
{
    return (_lobbyName);
}

std::string PlayerComponent::getNamePlayer()
{
    return (_name);
}

udp::endpoint PlayerComponent::getEndpointPlayer()
{
    return (this->_endpoint);
}

bool PlayerComponent::getConnectionPlayer()
{
    return (_connected);
}

bool PlayerComponent::getConnectionLobbyPlayer()
{
    return (_connectedLobby);
}

int PlayerComponent::getLobbyNumberPlayer()
{
    return (_playerNumber);
}

float PlayerComponent::getPositionPlayerY()
{
    return (_x);
}

float PlayerComponent::getPositionPlayerX()
{
    return (_y);
}