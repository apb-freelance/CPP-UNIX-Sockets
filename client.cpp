#include "client.hpp"
#include <cstring>

Client::Client(const std::string& server_ip, int port) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        trigger_error("Error al crear el socket del cliente");
        throw std::runtime_error("Error al crear el socket del cliente");
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip.c_str(), &address.sin_addr) <= 0) {
        trigger_error("Dirección IP inválida");
        throw std::runtime_error("Dirección IP inválida");
    }

    if (connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        trigger_error("Error al conectar al servidor");
        throw std::runtime_error("Error al conectar al servidor");
    }

    isConnected = true;
    trigger_receive("Conectado al servidor " + server_ip);
}

std::string Client::receive_message() {
    char buffer[1024] = {0};
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        trigger_error("Error al recibir el mensaje");
        throw std::runtime_error("Error al recibir el mensaje");
    }

    std::string message(buffer, bytes_received);
    trigger_receive("Mensaje recibido: " + message);
    return message;
}
