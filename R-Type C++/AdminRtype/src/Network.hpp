#include "system/ISystem.hpp"
#include <vector>
#include <thread>
#include <boost/asio.hpp>
#include <sstream>
#include <string>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <boost/bind/bind.hpp>
#include <boost/array.hpp>
#include <cstdio>
#include <ctime>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <sstream>
#include <boost/asio/ip/udp.hpp>
#include <iostream>
#include <boost/system/config.hpp>
#include <boost/cstdint.hpp>
#include <boost/assert.hpp>
#include <boost/noncopyable.hpp>
#include <boost/utility/enable_if.hpp>
#include <ostream>
#include <stdexcept>
#include <functional>
#include <ctime>

using boost::asio::ip::udp;
#define SIZE_PACKET 1000

struct receiveStruct {
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

struct sendStruct {
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

struct Player {
    std::string name;
    std::string current_lobby;
    bool _connected;
    bool _inLobby;
    short number;
};

class Network 
{
    public :
        Network();
        ~Network();
        void manageClient();
        void receiveMessage();
        void readMessage(const boost::system::error_code& error, size_t bytes_recvd);
        void sendMessage();
        void sendMessageTmp(const boost::system::error_code& error, size_t bytes_recvd);
        void encryption();
        void decryption(char *message, size_t bytes_recvd);
        void refresh();
        std::string connection(std::string ip);
        std::string soloRoom(std::string room);
        std::string allRoom();
        std::string playerIteration(std::string player);
        void info_room(std::string name);
        void game_room(int action, std::string message);
        void receive_engine();
        bool room_clock(int action);


        sendStruct _sent;
        receiveStruct _received;
        std::ostringstream _archive_stream;
        std::vector<std::thread> _client;
        udp::endpoint _endpoint;
        Player _player;
        boost::asio::ip::address ip_address;
        
        bool _connected;
        bool _socket_open;
        char _receivedMessage[SIZE_PACKET];

        std::string last_search;
};

