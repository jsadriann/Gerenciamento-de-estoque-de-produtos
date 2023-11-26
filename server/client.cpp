#include "client.h"

// Definição do construtor
ClientID::ClientID() {

}

ClientID::ClientID(sockaddr_in sock,socklen_t len,int id_p,string packet) {
    this->sock = sock;
    this->len = len;
    this->id_p = id_p;
    this->packet = packet;
}

void ClientID::setSock(sockaddr_in){
    this->sock = sock;
}
bool compararSockAddrIn(const sockaddr_in& addr1, const sockaddr_in& addr2) {
    return (
        addr1.sin_family == addr2.sin_family &&
        addr1.sin_port == addr2.sin_port &&
        addr1.sin_addr.s_addr == addr2.sin_addr.s_addr
    );
}