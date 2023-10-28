#ifndef LOGIN_H
#define LOGIN_H
#include <string>
using namespace std;

class Login {
public:
    Login();  // Construtor
    Login(string,string);
    string getLogin();
    string getSenha();

private:
    string login;
    string senha;
    void setLogin(string);
    void setSenha(string);
};

#endif