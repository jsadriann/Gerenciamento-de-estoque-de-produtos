#include "login.h"

// Definição do construtor
Login::Login() {
    
    login="";
    senha="";
}

Login::Login(string a, string b) {
    setLogin(a);
    setSenha(b);
}

string Login::getLogin(){
    return senha;
}

string Login::getSenha(){
    return login;
}

void Login::setLogin(string login){
    this->login = login;
}

void Login::setSenha(string senha){
    this->senha = senha;
}

int Login::verificaLogin(){
    if((login.compare("admin") == 0) && (senha.compare("admin") == 0))
        return 0;
    else if((login.compare("admin") == 0) && (senha.compare("admin") != 0))
        return 1;
    else if((login.compare("admin") != 0) && (senha.compare("admin") == 0))
        return 2;
    else 
        return 3;
}