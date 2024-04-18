#include "tools.hpp"

Tools::Tools()
{
    _enemy.resize(0);
}

Tools::~Tools()
{

}

int Tools::getPlayer(udp::endpoint endpoint)
{
    for (int i = 0; i < _player.size(); i++) {
        if (_player[i].getEndpointPlayerComponent() == endpoint)
            return (i);
    }
    return (-1);
}

int Tools::getLobby(std::string message)
{
    for (int i = 0; i < _lobby.size(); i++) {
        if (_lobby[i].getLobbyNameComponent().compare(message) == 0)
            return (i);
    }
    return (-1);
}

int Tools::getAllRoom()
{
    std::string privateRoom;
    if (_lobby.size() == 0)
        return (-1);
    for (int i = 0; i < _lobby.size(); i++) {
        if (_lobby[i].getLobbyPrivateComponent() == true)
            privateRoom = "Private";
        else
            privateRoom = "Public";
        _sentAdmin._room.push_back(_lobby[i].getLobbyNameComponent() + " | " + std::to_string(_lobby[i].getNumberPlayersComponent()) + " | " + privateRoom);
    }
    return (1);
}

void Tools::colisionBullet(int del)
{
    std::vector<FireEntity> tmp;
    for (int i = 0; i < _fire.size(); i++) {
        if (i != del)
            tmp.push_back(_fire[i]);
    }
    _fire = tmp;
}

int Tools::getPlayerRoom(std::string name)
{
    std::vector<std::string> player;
    _sentAdmin._playerRoom.clear();
    for (int i = 0; i < _lobby.size(); i++) {
        if (_lobby[i].getLobbyNameComponent().compare(name) == 0) {
            player = _lobby[i].getPlayersNamesComponent();
            for (int v = 0; v < player.size(); v++) {
                _sentAdmin._playerRoom.push_back(player[v]);
            }
            return (1);
        }
    }
    return (-1);
}

void Tools::algoDVD(EnemyEntity tmp)
{
    std::vector<float> max_placement = tmp.getMaxPlacementEnemyComponent();
    std::vector<float> min_placement = tmp.getMinPlacementEnemyComponent();
    std::vector<float> pos = tmp.getPosEnemyComponent();
    std::vector<float> speed = tmp.getSpeedEnemyComponent();
    bool left = tmp.getLeftEnemyComponent();
    bool down = tmp.getDownEnemyComponent();

        if (pos[0] >= min_placement[0] && left) {
            pos[0] -= speed[0];
            tmp.setPosEnemyComponent(pos);
            if (pos[0] < min_placement[0]) {
                left = false;
                tmp.setLeftEnemyComponent(false);
            }
        }
        if (pos[1] < max_placement[1] && down) {
            pos[1] += speed[1];
            tmp.setPosEnemyComponent(pos);
            if (pos[1] > max_placement[1]) {
                down = false;
                tmp.setDownEnemyComponent(false);
            }
        }
        if (pos[0] < max_placement[0] && !left) {
            pos[0] += speed[0];
            tmp.setPosEnemyComponent(pos);
            if (pos[0] >= max_placement[0]) {
                tmp.setLeftEnemyComponent(true);
            }
        }
        if (pos[1] > min_placement[1] && !down) {
            pos[1] -= speed[1];
            tmp.setPosEnemyComponent(pos);
            if (pos[1] <= min_placement[1]) {
                tmp.setDownEnemyComponent(true);
            }
        }
}

int Tools::checkColision(FireEntity fire, EnemyEntity enemy)
{
    std::vector<float> pos = enemy.getPosEnemyComponent();
    int x = fire.getPositionFireXComponent() + (108 * 0.5);
    int y = fire.getPositionFireYComponent() + ((51 * 0.5) / 2);
    if (x >= pos[0] && x <= (pos[0] + (768 * 0.15)))
        if (y > pos[1] && y < (pos[1] + (813 * 0.15)))
            return 1;
    return (0); 
}

/*void Tools::getEnemyLive(PlayerEntity _playerTmp)
{
    int v = getLobby(_player[i].getLobbyNamePlayerComponent());
    for (int i = 0; i < _enemy.size(); i++) {
        if (_enemy[i].getLobbyNameComponent.compare(_lobby[v].getLobbyNameComponent()) == 0) {

        }
    }
}*/

void Tools::deleteEnemy(EnemyEntity tmp)
{
    std::cout << "ENEMY = " << tmp.getIdEnemyComponent() << std::endl;
    tmp.setLifeEnemyComponent(false);
}

std::vector<int> Tools::getDieEnemy(PlayerEntity _playerTmp)
{
    std::vector<int> tmp;
    for (int i = 0; i < _enemy.size(); i++) {
        if (_enemy[i].getLobbyEnemyComponent().compare(_playerTmp.getLobbyNamePlayerComponent()) == 0) {
            if (_enemy[i].getLifeEnemyComponent() == false)
                tmp.push_back(_enemy[i].getIdEnemyComponent());
        }
    }
    return (tmp);
}

int Tools::findPlayer(std::string player)
{
    for (int i = 0; i < _player.size(); i++) {
        if (_player[i].getNamePlayerComponent().compare(player) == 0) {
            _sentAdmin._player_search.push_back(player);
            if (_player[i].getConnectionLobbyPlayerComponent() == true) {
                _sentAdmin._player_search.push_back(_player[i].getLobbyNamePlayerComponent());
                _sentAdmin._player_search.push_back(std::to_string(100));
            } else {
                _sentAdmin._player_search.push_back("Not in Lobby");
                _sentAdmin._player_search.push_back("Not in game");
            }
            return (1);
        }
    }
    return (-1);
}

int Tools::findPlayerIteration(std::string player)
{
    std::string room;
    std::string hp;
    int count = 0;
    for (int i = 0; i < _player.size(); i++) {
        if (_player[i].getNamePlayerComponent().compare(player) == 0) {
            count++;
            if (_player[i].getConnectionLobbyPlayerComponent() == true)
                room = _player[i].getLobbyNamePlayerComponent();
            else
                room = "No Room";
            hp = std::to_string(100);
            _sentAdmin._player_search.push_back(player + " | " + room + " | " + hp);
        }
    }
    if (count == 0)
        return (-1);
    return (0);
}

bool Tools::checkCreateRoom(std::string message)
{
    if (getLobby(message) == -1)
        return (true);
    return (false);
}

bool Tools::checkJoinRoom(std::string message)
{
    int i = getLobby(message);
    if (i == -1)
        return (false);
    if (_lobby[i].getNumberPlayersComponent() >= 4)
        return (false);
    return (true);
}

bool Tools::checkPlayerRoom(std::string name, std::string room)
{
    int v = getLobby(room);
    std::vector<std::string> tmp = _lobby[v].getPlayersNamesComponent();
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i].compare(name) == 0)
            return (false);
    }
    return (true);
}

std::vector<std::vector<std::vector<float>> > Tools::getEnemyFromLobby(std::string name)
{
    std::vector<std::vector<std::vector<float>> > tmp;
    std::vector<float> pos;
    tmp.resize(5);
    int v = 0;
    //std::cout << "----------------------------" << std::endl;
    for (int i = 0; i < _enemy.size(); i++) {
        if (_enemy[i].getLobbyEnemyComponent().compare(name) == 0) {
            tmp[v].resize(4);
            pos = _enemy[i].getMaxPlacementEnemyComponent();
            tmp[v][0].push_back(pos[0]);
            tmp[v][0].push_back(pos[1]);
            pos = _enemy[i].getMinPlacementEnemyComponent();
            tmp[v][1].push_back(pos[0]);
            tmp[v][1].push_back(pos[1]);
            pos = _enemy[i].getPosEnemyComponent();
            tmp[v][2].push_back(pos[0]);
            tmp[v][2].push_back(pos[1]);
            pos = _enemy[i].getSpeedEnemyComponent();
            tmp[v][3].push_back(pos[0]);
            tmp[v][3].push_back(pos[1]);
            //std::cout << "Enemy number : " << v << " Pos = " << tmp[v][2][0] << " " << tmp[v][2][1] << std::endl;
            v++;
        }
    }
    //std::cout << "----------------------------" << std::endl;
    return (tmp);
}

std::vector<std::vector<float> > Tools::generateRandomNumber()
{
    std::vector<std::vector<float> > numbers;
    numbers.resize(4);

    int _maxPlacementX = 1920 - 195;
    int _maxPlacementY = 1080 - 45;
    numbers[0].push_back(_maxPlacementX);
    numbers[0].push_back(_maxPlacementY);
    int _minPlacementX = 0;
    int _minPlacementY = 0;
    numbers[1].push_back(_minPlacementX);
    numbers[1].push_back(_minPlacementY);
    int _posEnemyX = rand() % ((1920 * 5) - 1920 + 1) + 1920;
    int _posEnemyY = rand() % (980 - 100 + 1) + 100;
    numbers[2].push_back(_posEnemyX);
    numbers[2].push_back(_posEnemyY);
    int _speedX = rand() % (11 - 4 + 1) + 4;
    int _speedY = rand() % (7 - 3 + 1) + 3;
    numbers[3].push_back(_speedX);
    numbers[3].push_back(_speedY);
    return (numbers);
}

bool Tools::checkAutoJoin(udp::endpoint endpoint)
{
    int i = getPlayer(endpoint);
    for (int v = 0; v < _lobby.size(); v++) {
        if (_lobby[v].getLobbyPrivateComponent() == false && _lobby[v].getNumberPlayersComponent() < 4) {
            _player[i].setLobbyNamePlayerComponent(_lobby[v].getLobbyNameComponent());
            _player[i].setConnectionLobbyPlayerComponent(true);
            _lobby[v].setNamesPlayersComponent(_received._name);
            _lobby[v].setNumberPlayersComponent(1);
            _lobby[v].setEndpointPlayerComponent(endpoint);
            _sent._players = _lobby[v].getPlayersNamesComponent();
            setPositionPlayerMenu(_player[i], v);
            return (true);
        }
    }
    return (false);
}

std::vector<std::vector<float> > Tools::getPosPlayerGame(PlayerEntity _playerTmp)
{
    int v = getLobby(_playerTmp.getLobbyNamePlayerComponent());
    std::vector<std::vector<float> > _result;
    _result.resize(_lobby[v].getNumberPlayersComponent());
    for (int i = 0; i < _player.size(); i++) {
        if (_player[i].getLobbyNamePlayerComponent().compare(_playerTmp.getLobbyNamePlayerComponent()) == 0) {
            _result[_player[i].getLobbyNumberPlayerComponent()].push_back(_player[i].getPositionPlayerXComponent());
            _result[_player[i].getLobbyNumberPlayerComponent()].push_back(_player[i].getPositionPlayerYComponent());
        }
    }
    return (_result);
}

std::vector<std::vector<std::string> > Tools::getAllPlayerFromAllLobby()
{
    int i = 0;
    std::vector<std::vector<std::string> > room;
    room.resize(_lobby.size());
    std::vector<std::string> tmpPlayer;
    for (i = 0; i < _lobby.size(); i++) {
        room[i].push_back(_lobby[i].getLobbyNameComponent());
        tmpPlayer = _lobby[i].getPlayersNamesComponent();
        for (int x = 0; x < tmpPlayer.size(); i++) {
            for (int v = 0; v < _player.size(); v++) {
                if (tmpPlayer[x].compare(_player[v].getNamePlayerComponent())) {
                    room[i].push_back(tmpPlayer[x]);
                }
            }
        }
    }
    return (room);
}

int Tools::getNumberBulletLobby(PlayerEntity _playerTmp)
{
    int count = 0;
    int i = getLobby(_playerTmp.getLobbyNamePlayerComponent());
    std::vector<udp::endpoint> PLobby = _lobby[i].getEndpointPlayerComponent();
    for (i = 0; i < _fire.size(); i++) {
        for (int v = 0; v < PLobby.size(); v++) {
            if (_fire[i].getEndpointFireComponent() == PLobby[v]) {
                count++;
            }
        }
    }
    return (count);
}

std::vector<std::vector<float> > Tools::getBulletLobbyGame(PlayerEntity _playerTmp)
{
    std::vector<std::vector<float> > tmp;
    tmp.resize(getNumberBulletLobby(_playerTmp));
    int size = 0;
    int count = 0;
    int i = getLobby(_playerTmp.getLobbyNamePlayerComponent());
    std::vector<udp::endpoint> PLobby = _lobby[i].getEndpointPlayerComponent();
    for (i = 0; i < _fire.size(); i++) {
        for (int v = 0; v < PLobby.size(); v++) {
            if (_fire[i].getEndpointFireComponent() == PLobby[v]) {
                tmp[count].push_back(_fire[i].getPositionFireXComponent());
                tmp[count].push_back(_fire[i].getPositionFireYComponent());
            }
        }
        count += 1;
    }
    return (tmp);
}

int Tools:: getNumberBullet(PlayerEntity _playerTmp)
{
    int compt = 0;
    int i = getLobby(_playerTmp.getLobbyNamePlayerComponent());
    std::vector<udp::endpoint> PLobby = _lobby[i].getEndpointPlayerComponent();
    for (i = 0; i < _fire.size(); i++) {
        for (int v = 0; v < PLobby.size(); v++) {
            if (_fire[i].getEndpointFireComponent() == PLobby[v]) {
                compt++;
            }
        }
    }
    return (compt);
}

void Tools::structPositionPlayerMenu()
{
    _sent._posPlayer[0].push_back(100);
    _sent._posPlayer[0].push_back(100);
    _sent._posPlayer[1].push_back(100);
    _sent._posPlayer[1].push_back(350);
    _sent._posPlayer[2].push_back(100);
    _sent._posPlayer[2].push_back(600);
    _sent._posPlayer[3].push_back(100);
    _sent._posPlayer[3].push_back(850);
}

void Tools::setPositionPlayerMenu(PlayerEntity _playerTmp, int i)
{
    if (_lobby[i].getNumberPlayersComponent() == 1) {
        _playerTmp.setPositionPlayerComponent(100, 100);
        _playerTmp.setLobbyNumberPlayerComponent(_lobby[i].getNumberPlayersComponent() - 1);
        _sent._position =_playerTmp.getLobbyNumberPlayerComponent();
    }
    if (_lobby[i].getNumberPlayersComponent() == 2) {
        _playerTmp.setPositionPlayerComponent(350, 100);
        _playerTmp.setLobbyNumberPlayerComponent(_lobby[i].getNumberPlayersComponent() - 1);
        _sent._position =_playerTmp.getLobbyNumberPlayerComponent();
    }
    if (_lobby[i].getNumberPlayersComponent() == 3) {
        _playerTmp.setPositionPlayerComponent(600, 100);
        _playerTmp.setLobbyNumberPlayerComponent(_lobby[i].getNumberPlayersComponent() - 1);
        _sent._position =_playerTmp.getLobbyNumberPlayerComponent();
    }
    if (_lobby[i].getNumberPlayersComponent() == 4) {
        _playerTmp.setPositionPlayerComponent(850, 100);
        _playerTmp.setLobbyNumberPlayerComponent(_lobby[i].getNumberPlayersComponent() - 1);
        _sent._position =_playerTmp.getLobbyNumberPlayerComponent();
    }
    structPositionPlayerMenu();
}

void Tools::encryption()
{
    boost::archive::binary_oarchive archive(_archive_stream);
    archive << _sent;
}

void Tools::encryptionAdmin()
{
    boost::archive::binary_oarchive archive(_archive_stream);
    archive << _sentAdmin;
}

void Tools::decryption(char *message, size_t bytes_recvd)
{
    std::string buffer(message, bytes_recvd);
    std::istringstream archive_stream(buffer);
    boost::archive::binary_iarchive archive(archive_stream);
    archive >> _received;
}