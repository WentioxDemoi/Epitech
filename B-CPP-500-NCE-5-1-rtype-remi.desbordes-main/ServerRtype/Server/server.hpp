#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/asio/ip/address.hpp>
#include "ToolsServer/tools.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <ctime>

using boost::asio::ip::udp;

#define SIZE_PACKET 1000

class Server : public Tools {
    public:
        Server(int _port);
        ~Server();
        void loopServer();
        void receiveMessage();   
        void readMessage(const boost::system::error_code& error, size_t bytes_recvd);
        void sendMessage();
        void sendMessage_tmp(const boost::system::error_code& error, size_t bytes_recvd);
        void refresh();
        void structMessage(int action, std::string message);
        void structMessageAdmin(int action, std::string message);
        void setPositionPlayerGame(PlayerEntity _playerTmp, float x, float y);
        void clientConnexion();
        void createLobby();
        void autoLobby();
        void joinLobby();
        void destroyLobby();
        void infoLobby();
        void actionPlayer();
        void adminConnexion();
        void searchPlayer();
        void searchAllPlayer();
        void searchRoom();
        void searchAllRoom();
        void shootAlly(PlayerEntity _playerTmp);
        void moovBullet(PlayerEntity _playerTmp);
        void deleteBullet(PlayerEntity _playerTmp);
        void createEnemy(PlayerEntity _playerTmp);
        void mooveEnemy(PlayerEntity _playerTmp);
    private:
        boost::asio::io_service _io_service;
        udp::endpoint _endpoint;
        udp::socket _socket;
        char _receivedMessage[SIZE_PACKET];
};