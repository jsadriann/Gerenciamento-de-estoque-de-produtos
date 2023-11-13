#include <iostream>
//#include "../model/login.h"
//#include "../model/estoque.h"
#include <stdlib.h>
#include "postgresql/libpq-fe.h"
#include <string.h>

using namespace std;

int main() {
    const char *conninfo;
    PGconn     *conn;
    conninfo = "user=postgres password=adrianec@123 dbname=projeto";
    conn = PQconnectdb(conninfo);

    string login = "admin";
    string aux = "SELECT * FROM Login where users='"+login+"'";
    const char *query = aux.c_str();
    PGresult *result = PQexec(conn, query);

    std::cout << "User: " << PQgetvalue(result, 0, PQfnumber(result, "users")) << ", Password: " << PQgetvalue(result, 0, PQfnumber(result, "password")) << std::endl;


   // Login login;
    //Estoque estoque;
    //estoque = Estoque("let","descrição aqui","lala","new kinika",10,8.1);
    //login = Login("aqui","ali");
    // MinhaClasse minha_instancia[2];  // Cria uma instância da classe MinhaClasse
    // minha_instancia[0] = MinhaClasse("aqui","acula");
    // minha_instancia[1] = MinhaClasse("ali","aqui");
    //std::cout << "senha: " << login.getSenha()<< std::endl;
    //std::cout << "email: " << login.getLogin()<< std::endl;

    //std::cout << "n: " << estoque.getName()<< std::endl;
    //std::cout << "d: " << estoque.getDescription()<< std::endl;
    //std::cout << "t: " << estoque.getTipo()<< std::endl;
    //std::cout << "f: " << estoque.getFornecedor()<< std::endl;
    //std::cout << "q: " << estoque.getQtd()<< std::endl;
    //std::cout << "v: " << estoque.getValue()<< std::endl;
    // std::cout << "senha: " << minha_instancia[1].getSenha()<< std::endl;
    // std::cout << "email: " << minha_instancia[1].getLogin()<< std::endl;


    return 0;
}


