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
    } else {
        std::cout << "WE GOT A PROBLEM" << std::endl;
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

std::string Network::connection(std::string ip)
{
    _sent._action = 360;
    _sent._message = "void";
    if (_socket_open == false) {
        _socket.open(boost::asio::ip::udp::v4());
        _client.push_back(std::move(std::thread(&Network::receiveMessage, this)));
    } _socket_open = true;
    _endpoint = udp::endpoint(this->ip_address, std::stoi(ip));
    
    this->encryption();
    this->sendMessage();
    if (room_clock(160) == true) {
        _player._connected = true;
        return("");
    } return("Error :\n---> Check IP or port <---");

}

std::string Network::soloRoom(std::string room)
{
    _sent._action = 374;
    for (int i = 0; i < room.size(); i++)
        room.at(i) = tolower(room.at(i));
    _sent._message = room;
    last_search = room;
    this->encryption();
    this->sendMessage();
    if (room_clock(174) == true) {
        return("OK");
    }
    return("Error :\n---> Room Dont Exist <---");
}

std::string Network::allRoom()
{
    _sent._action = 376;
    _sent._message = "void";
    this->encryption();
    this->sendMessage();
    if (room_clock(176) == true) {
        return("OK");
    } return("Error :\n---> There is no room <---");
}

std::string Network::playerIteration(std::string player)
{
    _sent._action = 372;
    for (int i = 0; i < player.size(); i++)
        player.at(i) = tolower(player.at(i));
    _sent._message = player;
    this->encryption();
    this->sendMessage();
    if (room_clock(172) == true) {
        return("OK");
    } return("Error :\n---> There is no player with this name <---");
}