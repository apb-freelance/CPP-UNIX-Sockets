#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "socket.hpp"

class Client : public Socket {
public:
    Client(const std::string& server_ip, int port);
    ~Client() = default;

    std::string receive_message();
};

#endif // CLIENT_HPP
