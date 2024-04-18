#include "../../Components/Lobby/Lobby.hpp"
#include <vector>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <thread>

using boost::asio::ip::udp;

class LobbyEntity {
    public:
        LobbyEntity();
        ~LobbyEntity();
        void createLobbyEntity(udp::endpoint _endpoint, std::string _namePlayer, std::string _nameLobby, int _privateLobby);
        void joinLobbyEntity(udp::endpoint _endpoint, std::string _namePlayer);
        void createLobbyComponent(std::string _name);
        
        //set
        void setNumberPlayersComponent(int x);
        void setNamesPlayersComponent(std::string name);
        void setEndpointPlayerComponent(udp::endpoint endpoint);
        void setLobbyPrivateComponent(int check);
        //get
        bool getLobbyPrivateComponent(void);
        int getNumberPlayersComponent(void);
        std::vector<std::string> getPlayersNamesComponent(void);
        std::string getLobbyNameComponent(void);
        std::vector<udp::endpoint> getEndpointPlayerComponent(void);
        //delete
        void deletePlayerNameComponent(std::string name);
    private:
        std::vector<std::shared_ptr<ILobby> > m_components;

};
