#ifndef SERVER_HPP
#define SERVER_HPP

#include "socket.hpp"

class Server : public Socket {
public:
    Server(int port);
    ~Server() = default;

    int accept_client();
    void send_message(int client_sock, const std::string& message);
};

#endif // SERVER_HPP
