#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <time.h>
#include <iostream>

using boost::asio::ip::udp;

class IPlayer {
    public:
        virtual ~IPlayer() {}
        virtual void setPositionPlayer(float x, float y) {}
        virtual void setConnectionPlayer(bool connected) {}
        virtual void setConnectionLobbyPlayer(bool connected) {}
        virtual void setLobbyNamePlayer(std::string _nameLobby) {}
        virtual void setLobbyNumberPlayer(int number) {}
        virtual void setTimeFirePlayer() {}
        void setHpPlayer(int hp) {}
        int getHpPlayer() { return (_hp); }
        virtual time_t getTimeFirePlayer() { return (_start); }
        virtual udp::endpoint getEndpointPlayer() { return (_endpoint); }
        virtual bool getConnectionPlayer() { return (_connected); }
        virtual bool getConnectionLobbyPlayer() { return (_connected); }
        virtual std::string getLobbyNamePlayer() { return (_name); }
        virtual std::string getNamePlayer() { return (_name); }
        virtual int getLobbyNumberPlayer() { return (_playerNumber); }
        virtual float getPositionPlayerX() { return (_pos); }
        virtual float getPositionPlayerY() { return (_pos); }
    private:
        udp::endpoint _endpoint;
        std::string _name;
        time_t _start;
        bool _connected;
        int _playerNumber;
        float _pos;
        int _hp;
    
};

class PlayerComponent : public IPlayer {
    public:
        PlayerComponent(udp::endpoint _endpoint, std::string _name);
        ~PlayerComponent();
        void setPositionPlayer(float x, float y);
        void setConnectionPlayer(bool connected);
        void setConnectionLobbyPlayer(bool connected);
        void setLobbyNamePlayer(std::string _lobbyNameTmp);
        void setLobbyNumberPlayer(int number);
        void setTimeFirePlayer();
        void setHpPlayer(int hp);
        int getHpPlayer();
        time_t getTimeFirePlayer();
        udp::endpoint getEndpointPlayer();
        bool getConnectionPlayer();
        bool getConnectionLobbyPlayer();
        int getLobbyNumberPlayer();
        float getPositionPlayerX();
        float getPositionPlayerY();
        std::string getLobbyNamePlayer();
        std::string getNamePlayer();
    private:
        std::string _name;
        std::string _lobbyName;
        udp::endpoint _endpoint;
        time_t _start;
        bool _connected;
        bool _connectedLobby;
        int _scene;
        int _playerNumber;
        int _hp;
        float _x;
        float _y;
};