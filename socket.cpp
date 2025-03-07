#include "socket.hpp"

Socket::Socket() : sockfd(-1) {}

Socket::~Socket() {
    if (sockfd != -1) {
        close(sockfd);
    }
}

bool Socket::is_connected() const {
    return isConnected;
}

void Socket::on_send(const std::string& message) {
    std::cout << "[Evento: Envío] " << message << std::endl;
}

void Socket::on_receive(const std::string& message) {
    std::cout << "[Evento: Recepción] " << message << std::endl;
}

void Socket::on_error(const std::string& error) {
    std::cerr << "[Evento: Error] " << error << std::endl;
}

void Socket::trigger_send(const std::string& message) {
    on_send(message);
}

void Socket::trigger_receive(const std::string& message) {
    on_receive(message);
}

void Socket::trigger_error(const std::string& error) {
    on_error(error);
}
