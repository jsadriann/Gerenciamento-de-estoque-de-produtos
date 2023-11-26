#include <iostream>
#include <string>
#include <sys/socket.h> 
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include "client.h"
#include "despaxante.h"
#include "database.h"

ClientID cli = ClientID();
int id = 0;
//int id_client = -1;
string pacote;
int main() {

    int server_socket;
    char buffer[1024];
    struct sockaddr_in server_address, client_address;
    socklen_t addr_size = sizeof(client_address);
    cli = ClientID(client_address,addr_size,-1,pacote);

    // Criar o socket UDP
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

        //int recv_size = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_address, &addr_size);
        int recv_size = recvfrom(server_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_address, &addr_size);
        // Processar os dados recebidos
        std::string received_data(buffer, recv_size);

        if (!compararSockAddrIn(cli.sock,client_address)) {
            cli.setSock(client_address);
            cli.id_p = -1;
        }

        // Responder ao cliente (opcional)
        if(package_id(received_data) == cli.id_p){
            sendto(server_socket, pacote.c_str(), pacote.length(), 0, (struct sockaddr*)&client_address, addr_size);

        }else{
            cli.id_p = package_id(received_data);
            cli.packet = do_operation(received_data,id++);
            sendto(server_socket, cli.packet.c_str(), cli.packet.length(), 0, (struct sockaddr*)&client_address, addr_size);
        }
    }
    
    // Feche o socket do servidor (isso não será alcançado neste exemplo
    close(server_socket);

    return 0;
}