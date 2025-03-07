#include "server.hpp"
#include "client.hpp"

int main() {
    // Simulated main for the server
    Server server(8080);
    int client_sock = server.accept_client();
    server.send_message(client_sock, "Hola, cliente!");
    close(client_sock);

    // Simulated main for the client
    Client client("127.0.0.1", 8080);
    std::string message = client.receive_message();
    std::cout << "Mensaje recibido del servidor: " << message << std::endl;

    return 0;
}
