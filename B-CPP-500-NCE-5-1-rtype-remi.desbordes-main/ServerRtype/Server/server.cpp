#include "server.hpp"

Server::Server(int _port) : _socket(_io_service, udp::endpoint(udp::v4(), _port))
{
    _sent._posPlayer.resize(4);
    this->loopServer();
}

Server::~Server()
{

}

void Server::sendMessage()
{
    _socket.async_send_to(boost::asio::buffer(_archive_stream.str()), _endpoint, boost::bind(&Server::sendMessage_tmp, this,
                                                                                 boost::asio::placeholders::error, 
                                                                                 boost::asio::placeholders::bytes_transferred));
}

void Server::sendMessage_tmp(const boost::system::error_code& error, size_t bytes_recvd)
{
    _archive_stream.str("");
}


void Server::receiveMessage()
{
    _socket.async_receive_from(boost::asio::buffer(_receivedMessage, SIZE_PACKET), _endpoint, boost::bind(&Server::readMessage, this,
                                                                                              boost::asio::placeholders::error,
                                                                                              boost::asio::placeholders::bytes_transferred));
}

void Server::readMessage(const boost::system::error_code& error, size_t bytes_recvd)
{
    if (!error) {
        this->decryption(_receivedMessage, bytes_recvd);
        if (_received._action == 310)
            clientConnexion();
        if (_received._action == 320)
            createLobby();
        if (_received._action == 323)
            autoLobby();
        if (_received._action == 325)
            joinLobby();
        if (_received._action == 330)
            destroyLobby();
        if (_received._action == 335)
            infoLobby();
        if (_received._action == 340)
            actionPlayer();
        if (_received._action == 360)
            adminConnexion();
        if (_received._action == 370)
            searchPlayer();
        if (_received._action == 372)
            searchAllPlayer();
        if (_received._action == 374)
            searchRoom();
        if (_received._action == 376)
            searchAllRoom();
    }
}

void Server::structMessage(int action, std::string message)
{
    _sent._action = action;
    _sent._message = message;
    this->encryption();
}

void Server::structMessageAdmin(int action, std::string message)
{
    _sentAdmin._action = action;
    _sentAdmin._message = message;
    this->encryptionAdmin();
}

//admin Fonction

void Server::adminConnexion()
{
    structMessageAdmin(160, "OK");
}

void Server::searchPlayer()
{
    int a = findPlayer(_received._name);
    if (a == -1)
        structMessageAdmin(470, "Player Not Exist");
    else
        structMessageAdmin(170, "OK");
}

void Server::searchAllPlayer()
{
    int a = findPlayerIteration(_received._message);
    if (a == -1)
        structMessageAdmin(472, "Player Not Exist");
    else
        structMessageAdmin(172, "OK");
}

void Server::searchRoom()
{
    int a = getPlayerRoom(_received._message);
    if (a == -1)
        structMessageAdmin(474, "Room Dont Exist");
    else
        structMessageAdmin(174, "OK");
    _sentAdmin._playerRoom.clear();
}

void Server::searchAllRoom()
{
    int a = getAllRoom();
    if (a == -1)
        structMessageAdmin(476, "There Is No Room");
    else
        structMessageAdmin(176, "OK");
    _sentAdmin._room.clear();
}



//client Fonction

void Server::clientConnexion()
{
    PlayerEntity tmp;
    tmp.createClient(_endpoint, _received._name);
    _player.push_back(tmp);
    structMessage(110, "OK");
}

void Server::createLobby()
{
    if (checkCreateRoom(_received._message) == false) {
        structMessage(420, "ROOM EXIST\n");
        return;
    }
    int i = getPlayer(_endpoint);
    _player[i].connectLobbyClient(_received._message);
    createEnemy(_player[i]);
    LobbyEntity tmp;
    tmp.createLobbyEntity(_endpoint, _received._name, _received._message, _received._private);
    _sent._players = tmp.getPlayersNamesComponent();
    _lobby.push_back(tmp);
    structMessage(120, "CHANNEL CREATED");
    int v = getLobby(_received._message);
    setPositionPlayerMenu(_player[i], v);
}

void Server::joinLobby()
{
    if (checkJoinRoom(_received._message) == false) {
        structMessage(425, "ROOM DON'T EXIST OR PLAYER EXIST\n");
        return;
    }
    if (checkPlayerRoom(_received._name, _received._name) == false) {
        structMessage(425, "ROOM DON'T EXIST OR PLAYER EXIST\n");
        return;
    }
    int i = getPlayer(_endpoint);
     _player[i].connectLobbyClient(_received._message);
    int v = getLobby(_received._message);
    _lobby[v].joinLobbyEntity(_endpoint, _received._name);
    _sent._players = _lobby[v].getPlayersNamesComponent();
    structMessage(125, "CHANNEL JOINED");
    setPositionPlayerMenu(_player[i], v);
}

void Server::autoLobby()
{
    if (checkAutoJoin(_endpoint) == false)
        structMessage(323, "No Room Available");
    else
        structMessage(123, "Room Join");
}

void Server::destroyLobby()
{
    std::vector<FireEntity> tmp;
     for (int i = 0; i < _fire.size(); i++) {
        if (_fire[i].getPositionFireYComponent() <= 1080) {
             tmp.push_back(_fire[i]);
        }
     }
     _fire = tmp;
}

void Server::infoLobby()
{
    int i = getPlayer(_endpoint);
    int v = getLobby(_player[i].getLobbyNamePlayerComponent());
    _sent._players = _lobby[v].getPlayersNamesComponent();
    _sent._position = _player[i].getLobbyNumberPlayerComponent();
    _sent._infoEnemy = getEnemyFromLobby(_player[i].getLobbyNamePlayerComponent());
    structMessage(135, "OK");
    _sent._infoEnemy.clear();
}

void Server::actionPlayer()
{
    int i = getPlayer(_endpoint);
    int v = getLobby(_player[i].getLobbyNamePlayerComponent());
    _sent._players = _lobby[v].getPlayersNamesComponent();
    if (_received._message.compare("UP") == 0)
        setPositionPlayerGame(_player[i], _player[i].getPositionPlayerXComponent(), (_player[i].getPositionPlayerYComponent() - 10));
    if (_received._message.compare("DOWN") == 0)
        setPositionPlayerGame(_player[i], _player[i].getPositionPlayerXComponent(), (_player[i].getPositionPlayerYComponent() + 10));
    if (_received._message.compare("LEFT") == 0)
        setPositionPlayerGame(_player[i], (_player[i].getPositionPlayerXComponent() - 10), _player[i].getPositionPlayerYComponent());
    if (_received._message.compare("RIGHT") == 0)
        setPositionPlayerGame(_player[i], (_player[i].getPositionPlayerXComponent() + 10), _player[i].getPositionPlayerYComponent());
    if (_received._message.compare("FIRE") == 0)
        shootAlly(_player[i]);
    if (_received._message.compare("POS") == 0) {
        moovBullet(_player[i]);
        mooveEnemy(_player[i]);
        deleteBullet(_player[i]);
        _sent._posBullet.clear();
        _sent._infoEnemy.clear();
        _sent._die.clear();
        _sent._infoEnemy = getEnemyFromLobby(_player[i].getLobbyNamePlayerComponent());
        _sent._posBullet = getBulletLobbyGame(_player[i]);
        _sent._posPlayer = getPosPlayerGame(_player[i]);
        _sent._die = getDieEnemy(_player[i]);
        structMessage(140, "OK");
    }
}

void Server::deleteBullet(PlayerEntity _playerTmp)
{
    std::vector<FireEntity> tmp;
    for (int v = 0; v < _enemy.size(); v++) {
        for (int i = 0; i < _fire.size(); i++) {
            if (_enemy[v].getLobbyEnemyComponent().compare(_playerTmp.getLobbyNamePlayerComponent()) == 0) {
                if (checkColision(_fire[i], _enemy[v]) == 1) {
                    colisionBullet(i);
                    deleteEnemy(_enemy[v]);
                }
            }
        }
    }
    for (int i = 0; i < _fire.size(); i++) {
        if (_fire[i].getPositionFireXComponent() <= 2100)
        tmp.push_back(_fire[i]);
    }
    _fire = tmp;
}

void Server::mooveEnemy(PlayerEntity _playerTmp)
{
    std::vector<float> pos;
    int v = getLobby(_playerTmp.getLobbyNamePlayerComponent());
    for (int i = 0; i < _enemy.size(); i++) {
        if (_enemy[i].getLobbyEnemyComponent().compare(_lobby[v].getLobbyNameComponent()) == 0) {
            algoDVD(_enemy[i]);
            pos = _enemy[i].getPosEnemyComponent();
        }
    }
}

void Server::createEnemy(PlayerEntity _playerTmp)
{
    std::vector<EnemyEntity> tmp;
    tmp.resize(5);
    std::vector<std::vector<float> > numbers;
    for (int i = 0; i < 5; i++) {
        numbers = generateRandomNumber();
        tmp[i].AddEnemyComponent("jojo le pilote");
        tmp[i].setLeftEnemyComponent(true);
        tmp[i].setDownEnemyComponent(true);
        tmp[i].setMaxPlacementEnemyComponent(numbers[0]);
        tmp[i].setMinPlacementEnemyComponent(numbers[1]);
        tmp[i].setPosEnemyComponent(numbers[2]);
        tmp[i].setSpeedEnemyComponent(numbers[3]);
        tmp[i].setDammageEnemyComponent(10);
        tmp[i].setHpEnemyComponent(100);
        tmp[i].setLobbyEnemyComponent(_playerTmp.getLobbyNamePlayerComponent());
        tmp[i].setEndpointEnemyComponent(_playerTmp.getEndpointPlayerComponent());
        tmp[i].setIdEnemyComponent(i);
        tmp[i].setLifeEnemyComponent(true);
        _enemy.push_back(tmp[i]);
    }
}

void Server::moovBullet(PlayerEntity _playerTmp)
{
    int i = getLobby(_playerTmp.getLobbyNamePlayerComponent());
    std::vector<udp::endpoint> PLobby = _lobby[i].getEndpointPlayerComponent();
    for (i = 0; i < _fire.size(); i++) {
        for (int v = 0; v < PLobby.size(); v++) {
            if (_fire[i].getEndpointFireComponent() == PLobby[v]) {
                _fire[i].setPositionFireComponent(_fire[i].getPositionFireXComponent() + 10, _fire[i].getPositionFireYComponent());
            }
        }
    }
}

void Server::shootAlly(PlayerEntity _playerTmp)
{
    time_t finish;
    time (&finish);
    if (difftime(finish, _playerTmp.getTimeFirePlayerComponent()) > 0.5) {
        FireEntity tmp;
        tmp.AddFireComponent(_playerTmp.getEndpointPlayerComponent());
        tmp.setPositionFireComponent(_playerTmp.getPositionPlayerXComponent() + 195, _playerTmp.getPositionPlayerYComponent() + 65);
        tmp.setIdFireComponent(getNumberBullet(_playerTmp) + 1);
        _fire.push_back(tmp);
        structMessage(140, "FIRE_OK");
        _playerTmp.setTimeFirePlayerComponent();
    } else {
        _sent._posPlayer = getPosPlayerGame(_playerTmp);
        structMessage(140, "FIRE_KO");
    }
}

void Server::setPositionPlayerGame(PlayerEntity _playerTmp, float x, float y)
{
    if (x <= 0 || x > (1920 - 195) || y <= 0 || y > 1080 - (45 * 2)) {
        _sent._posPlayer = getPosPlayerGame(_playerTmp);
        structMessage(140, "OK");
        return;
    }
    _playerTmp.setPositionPlayerComponent(y, x);
    _sent._posPlayer = getPosPlayerGame(_playerTmp);
    structMessage(140, "OK");
    this->encryption();
}

void Server::refresh()
{
    _io_service.poll();
    _io_service.reset();
    _io_service.run();
}

void Server::loopServer()
{
    while (1) {
        this->receiveMessage();
        this->refresh();
        this->sendMessage();
        this->refresh();
    }
}