#include <iostream>
#include <string>
#include <sys/socket.h> 
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include "despaxante.h"

int main() {
    int server_socket;
    char buffer[1024];
    struct sockaddr_in server_address, client_address;
    socklen_t addr_size = sizeof(client_address);

    // Crie o socket UDP
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if (server_socket < 0) {
        perror("Erro ao criar o socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080); // Porta do servidor
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Faça o bind do socket à porta do servidor
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Erro ao fazer o bind");
        return 1;
    }

    while (true) {

        int recv_size = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_address, &addr_size);

        // if (recv_size < 0) {
        //     perror("Erro ao receber dados");
        //     return 1;
        // }
        // Processar os dados recebidos

        std::string received_data(buffer, recv_size);
        // try {
        //     json received_json = json::parse(received_data);
        //     std::string a = received_json["args"];
        //     json args = json::parse(a);

        // // Acesse os campos do JSON
        //     if (received_json.find("objref") != received_json.end()) {
        //         std::string obj = received_json["objref"];
        //         std::string oper = received_json["operation"];
        //         std::string user = args["user"];
        //         std::string passw = args["password"];
        //         std::cout << "objeto recebido: " << obj << std::endl;
        //         std::cout << "operação recebido: " << oper << std::endl;
        //         std::cout << "user recebido: " << user << std::endl;
        //         std::cout << "senha recebido: " << passw << std::endl;
        //     }
        // } catch (const json::parse_error& e) {
        //     std::cerr << "Erro ao analisar a mensagem JSON: " << e.what() << std::endl;
        // }

        // Responder ao cliente (opcional)
        std::string response = do_operation(received_data);
        sendto(server_socket, response.c_str(), response.length(), 0, (struct sockaddr*)&client_address, addr_size);
    }
    
    // Feche o socket do servidor (isso não será alcançado neste exemplo
    close(server_socket);

    return 0;
}