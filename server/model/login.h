#ifndef MINHACLASSE_H
#define MINHACLASSE_H
#include <string>
using namespace std;

class MinhaClasse {
public:
    MinhaClasse();  // Construtor
    MinhaClasse(string,string);
    string getLogin();
    string getSenha();

private:
    int numero;  // Membro de dados
    string login;
    string senha;
};

#endif