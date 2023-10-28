#include <iostream>
//#include "../model/login.h"
#include <stdlib.h>
#include "postgresql/libpq-fe.h"

int main() {
    const char *conninfo;
    PGconn     *conn;
    conninfo = "user=postgres password=adrianec@123 dbname=postgres";

    conn = PQconnectdb(conninfo);
    if(PQstatus(conn) == CONNECTION_OK){
        printf("conectou");
        PQfinish(conn);
    }

    // MinhaClasse minha_instancia[2];  // Cria uma instância da classe MinhaClasse
    // minha_instancia[0] = MinhaClasse("aqui","acula");
    // minha_instancia[1] = MinhaClasse("ali","aqui");
    // std::cout << "senha: " << minha_instancia[0].getSenha()<< std::endl;
    // std::cout << "email: " << minha_instancia[0].getLogin()<< std::endl;
    // std::cout << "senha: " << minha_instancia[1].getSenha()<< std::endl;
    // std::cout << "email: " << minha_instancia[1].getLogin()<< std::endl;


    return 0;
}


