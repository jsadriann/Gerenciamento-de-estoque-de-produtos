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