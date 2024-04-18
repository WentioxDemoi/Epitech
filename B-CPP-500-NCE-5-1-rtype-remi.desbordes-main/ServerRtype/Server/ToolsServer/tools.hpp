#include "../../GameEntity/Player/PlayerEntity.hpp"
#include "../../GameEntity/Lobby/LobbyEntity.hpp"
#include "../../GameEntity/Fire/FireEntity.hpp"
#include "../../GameEntity/Enemy/EnemyEntity.hpp"
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <sstream>
#include <string>
#include <vector>

struct sendStruct {
    int _action;
    int _position;
    std::string _message;
    std::vector<std::string> _players;
    std::vector<std::vector<float> > _posPlayer;
    std::vector<std::vector<float> > _posBullet;
    std::vector<std::vector<std::vector<float>> > _infoEnemy;
    std::vector<int> _die;
    template<typename archive> void serialize(archive& tmp, const unsigned) {
        tmp &_action;
        tmp &_position;
        tmp &_message;
        tmp &_players;
        tmp &_posPlayer;
        tmp &_posBullet;
        tmp &_infoEnemy;
        tmp &_die;
    }
};

struct sendAdmin {
    int _action;
    std::string _message;
    std::vector<std::string> _player_search;
    std::vector<std::string> _room;
    std::vector<std::string> _playerRoom;
    template<typename archive> void serialize(archive& tmp, const unsigned) {
        tmp &_action;
        tmp &_message;
        tmp &_player_search;
        tmp &_room;
        tmp &_playerRoom;
    }
};

struct receiveStruct {
    int _action;
    int _private;
    std::string _name;
    std::string _message;

    template<typename archive> void serialize(archive& tmp, const unsigned) {
        tmp &_action;
        tmp &_private;
        tmp &_name;
        tmp &_message;
    }
};

class Tools {
    public:
        Tools();
        ~Tools();
        int getLobby(std::string message);
        int getPlayer(udp::endpoint endpoint);
        int getPlayerRoom(std::string name);
        int getAllRoom();
        int findPlayer(std::string player);
        int findPlayerIteration(std::string player);
        std::vector<std::vector<float> > getBulletLobbyGame(PlayerEntity _playerTmp);
        int getNumberBulletLobby(PlayerEntity _playerTmp);
        bool checkCreateRoom(std::string message);
        bool checkJoinRoom(std::string message);
        bool checkPlayerRoom(std::string name, std::string room);
        bool checkAutoJoin(udp::endpoint endpoint);
        std::vector<std::vector<float> > getPosPlayerGame(PlayerEntity _playerTmp);
        std::vector<std::vector<std::string> > getAllPlayerFromAllLobby();
        void setPositionPlayerMenu(PlayerEntity _playerTmp, int i);
        void structPositionPlayerMenu();
        void encryption();
        void encryptionAdmin();
        void colisionBullet(int del);
        std::vector<int> getDieEnemy(PlayerEntity _playerTmp);
        void deleteEnemy(EnemyEntity tmp);
        void decryption(char *message, size_t bytes_recvd);
        int checkColision(FireEntity fire, EnemyEntity enemy);
        int getNumberBullet(PlayerEntity _playerTmp);
        void algoDVD(EnemyEntity tmp);
        std::vector<std::vector<std::vector<float>> > getEnemyFromLobby(std::string name);
        std::vector<std::vector<float> > generateRandomNumber();
    protected:
        std::vector<PlayerEntity> _player;
        std::vector<LobbyEntity> _lobby;
        std::vector<FireEntity> _fire;
        std::vector<EnemyEntity> _enemy;
        std::ostringstream _archive_stream;
        receiveStruct _received;
        sendStruct _sent;
        sendAdmin _sentAdmin;
};