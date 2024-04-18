#include "Network.hpp"


boost::asio::io_context _io_context;
boost::asio::ip::udp::socket _socket(_io_context);

Network::Network()
{
    _socket_open = false;
    _sent._private = 0;
}

Network::~Network()
{
    _client[0].~thread();
}

void Network::decryption(char *message, size_t bytes_recvd)
{
    std::string buffer(message, bytes_recvd);
    std::istringstream archive_stream(buffer);
    boost::archive::binary_iarchive archive(archive_stream);
    archive >> _received;
}

void Network::encryption()
{
    boost::archive::binary_oarchive archive(_archive_stream);
    archive << _sent;
}

void Network::readMessage(const boost::system::error_code& error, size_t bytes_recvd)
{
    if (!error) {
        this->decryption(_receivedMessage, bytes_recvd);
    }
}

void Network::receiveMessage()
{
    while(1) {
        _socket.async_receive_from(boost::asio::buffer(_receivedMessage, SIZE_PACKET),
                                   _endpoint, boost::bind(&Network::readMessage, this,
                                   boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
        _io_context.poll();
        _io_context.reset();
        _io_context.run();
    }
}

void Network::sendMessageTmp(const boost::system::error_code& error, size_t bytes_recvd)
{

}

void Network::sendMessage()
{
    _socket.async_send_to(boost::asio::buffer(_archive_stream.str()), _endpoint, boost::bind(&Network::sendMessageTmp, this,
                                                                                 boost::asio::placeholders::error, 
                                                                                 boost::asio::placeholders::bytes_transferred));
    _archive_stream.str("");
}

bool Network::room_clock(int action)
{
    std::clock_t start = std::clock();
    double duration;
    while (_received._action != action) {
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        if (duration >= 0.2)
            return false;
    } return true;
}

std::string Network::connection(std::string name, std::string ip)
{
    for (int i = 0; i < name.size(); i++)
        name.at(i) = tolower(name.at(i));
    _sent._action = 310;
    _sent._name = name;
    _sent._message = "void";
    if (_socket_open == false) {
        _socket.open(boost::asio::ip::udp::v4());
        _client.push_back(std::move(std::thread(&Network::receiveMessage, this)));
    } _socket_open = true;
    _endpoint = udp::endpoint(this->ip_address, std::stoi(ip));
    
    this->encryption();
    this->sendMessage();
    if (room_clock(110) == true) {
        _player._connected = true;
        return("");
    } return("Error :\n---> Check IP or port <---");

}

std::string Network::create_room(std::string name)
{
    for (int i = 0; i < name.size(); i++)
        name.at(i) = tolower(name.at(i));
    _sent._name = _player.name;
    _sent._message = name;
    _sent._action = 320;
    this->encryption();
    this->sendMessage();
    if (room_clock(120) == true) {
        _player._inLobby = true;
        return("");
    } return("Error :\nName already used");
    
}

std::string Network::autoRoom()
{
    _sent._name = _player.name;
    _sent._action = 323;
    this->encryption();
    this->sendMessage();
    if (room_clock(123) == true) {
        _player._inLobby = true;
        return("");
    }
    return ("No Room Avaible");
}

std::string Network::join_room(std::string name)
{
    for (int i = 0; i < name.size(); i++)
        name.at(i) = tolower(name.at(i));
    _sent._name = _player.name;
    _sent._action = 325;
    _sent._message = name;
    this->encryption();
    this->sendMessage();
    if (room_clock(125) == true) {
        _player._inLobby = true;
        return("");
    }
    return("Can't join :\n--> Already exists / Verify name <--");
    
    //Voir pour vérification de la connexion au lobby demandé !!!
}

void Network::info_room(std::string name)
{
    _sent._name = _player.name;
    _sent._action = 335;
    _sent._message = name;
    this->encryption();
    this->sendMessage();
    while(_received._action != 135) {}
}

void Network::game_room(int action, std::string message)
{
    _sent._name = _player.name;
    _sent._action = action;
    _sent._message = message;
    this->encryption();
    this->sendMessage();

    while(_received._action != 140) {
        
    }
}