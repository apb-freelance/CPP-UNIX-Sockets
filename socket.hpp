#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <arpa/inet.h>
#include <unistd.h>

class Socket {
protected:
    int sockfd;                 // Descriptor del socket
    sockaddr_in address;        // Dirección del socket
    bool isConnected = false;   // Estado de la conexión

public:
    Socket();
    virtual ~Socket();

    bool is_connected() const;

    // Métodos virtuales para eventos
    virtual void on_send(const std::string& message);
    virtual void on_receive(const std::string& message);
    virtual void on_error(const std::string& error);

protected:
    void trigger_send(const std::string& message);
    void trigger_receive(const std::string& message);
    void trigger_error(const std::string& error);
};

#endif // SOCKET_HPP
