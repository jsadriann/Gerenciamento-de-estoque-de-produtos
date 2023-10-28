#include "login.h"

// Definição do construtor
MinhaClasse::MinhaClasse() {
    
    login = "";
    senha = "";
}

MinhaClasse::MinhaClasse(string a, string b) {
    login = a;
    senha = b;
}

string MinhaClasse::getLogin(){
    return senha;
}

string MinhaClasse::getSenha(){
    return login;
}