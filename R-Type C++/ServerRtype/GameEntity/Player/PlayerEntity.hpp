#include "../../Components/Player/Player.hpp"
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <thread>

using boost::asio::ip::udp;

class PlayerEntity {
    public:
        PlayerEntity();
        ~PlayerEntity();
        void createClient(udp::endpoint _endpoint, std::string _name);
        void connectLobbyClient(std::string _nameLobby);
        void AddPlayerComponent(udp::endpoint _endpoint, std::string _name);

        //set
        void setConnectionPlayerComponent(bool connected);
        void setConnectionLobbyPlayerComponent(bool connected);
        void setLobbyNamePlayerComponent(std::string _nameLobby);
        void setPositionPlayerComponent(float x, float y);
        void setLobbyNumberPlayerComponent(int number);
        void setTimeFirePlayerComponent();
        void setHpPlayerComponent(int hp);
        //get
        int getHpPlayerComponent();
        time_t getTimeFirePlayerComponent();
        udp::endpoint getEndpointPlayerComponent();
        bool getConnectionPlayerComponent();
        bool getConnectionLobbyPlayerComponent();
        std::string getLobbyNamePlayerComponent();
        std::string getNamePlayerComponent();
        int getLobbyNumberPlayerComponent();
        float getPositionPlayerXComponent();
        float getPositionPlayerYComponent();
    private:
        std::vector<std::shared_ptr<IPlayer> > m_components;
};