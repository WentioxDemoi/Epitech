#include <iostream>
#include <vector>
#include <thread>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::udp;

class ILobby {
    public:
        virtual ~ILobby() {}
        virtual void createLobby() {}
        virtual void setNumberPlayers(int x) {}
        virtual void setNamesPlayers(std::string name) {}
        virtual void setEndpointPlayer(udp::endpoint endpoint) {}
        virtual void setLobbyPrivate(int check) {}
        virtual bool getLobbyPrivate() { return (_private); }
        virtual int getNumberPlayers(void) { return (_number); }
        virtual std::vector<std::string> getPlayersNames(void) { return (_players); }
        virtual std::string getLobbyName(void) { return (_name); }
        virtual std::vector<udp::endpoint> getEndpointPlayer(void) { return (_endpoint); }
        virtual void deletePlayerName(std::string _name) {}
    private:
        int _number;
        bool _private;
        std::string _name;
        std::vector<std::string> _players;
        std::vector<udp::endpoint> _endpoint;

};

class LobbyComponent : public ILobby {
    public:
        LobbyComponent(std::string _name);
        ~LobbyComponent();
        void createLobby();
        //set
        void setNumberPlayers(int x);
        void setNamesPlayers(std::string name);
        void setEndpointPlayer(udp::endpoint endpoint);
        void setLobbyPrivate(int check);
        //get
        bool getLobbyPrivate();
        int getNumberPlayers(void);
        std::vector<std::string> getPlayersNames(void);
        std::string getLobbyName(void);
        std::vector<udp::endpoint> getEndpointPlayer(void);
        //delete
        void deletePlayerName(std::string name);
    private:
        int _nb_players;
        bool _ifPrivate;
        std::vector<std::string> _playersNames;
        std::vector<udp::endpoint> _endpoint;
        std::string _lobbyName;
};