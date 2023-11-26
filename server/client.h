#ifndef CLIENT_H
#define CLIENT_H
#include <sys/socket.h> 
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
using namespace std;

class ClientID {
public:
    sockaddr_in sock;
    socklen_t len;
    int id_p;
    string packet;
    ClientID();  // Construtor
    ClientID(sockaddr_in,socklen_t,int,string);
    void setSock(sockaddr_in);

};

bool compararSockAddrIn(const sockaddr_in& addr1, const sockaddr_in& addr2);

#endif