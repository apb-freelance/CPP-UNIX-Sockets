#include "server.hpp"
#include <cstring>

Server::Server(int port) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        trigger_error("Error al crear el socket del servidor");
        throw std::runtime_error("Error al crear el socket del servidor");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        trigger_error("Error en bind()");
        throw std::runtime_error("Error en bind()");
    }

    if (listen(sockfd, 5) < 0) {
        trigger_error("Error en listen()");
        throw std::runtime_error("Error en listen()");
    }

    isConnected = true;
    trigger_send("Servidor configurado y escuchando en el puerto " + std::to_string(port));
}

int Server::accept_client() {
    sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);
    int client_sock = accept(sockfd, (struct sockaddr*)&client_address, &client_len);
    if (client_sock < 0) {
        trigger_error("Error al aceptar la conexión del cliente");
        throw std::runtime_error("Error al aceptar la conexión del cliente");
    }

    trigger_send("Cliente conectado");
    return client_sock;
}

void Server::send_message(int client_sock, const std::string& message) {
    if (send(client_sock, message.c_str(), message.size(), 0) < 0) {
        trigger_error("Error al enviar el mensaje");
        throw std::runtime_error("Error al enviar el mensaje");
    }
    trigger_send("Mensaje enviado: " + message);
}
