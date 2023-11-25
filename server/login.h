#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;


class Login {
public:
    Login();  // Construtor
    Login(string,string);
    string getLogin();
    string getSenha();
    int verificaLogin();
    void setLoginWrapper(const std::string& login) {
        setLogin(login);
    }

    void setSenhaWrapper(const std::string& senha) {
        setSenha(senha);
    }


private:
    string login;
    string senha;
    void setLogin(string);
    void setSenha(string);
};

int add_login(string,string);
int remove_login(string);

static std::unordered_map<std::string, std::function<int(Login&)>> loginMethodMap = {
    {"verificaLogin", [](Login& loginObj) {
        return loginObj.verificaLogin();
    }},
    {"add_login", [](Login& loginObj) {
        return add_login(loginObj.getLogin(), loginObj.getSenha());
    }},
    {"remove_login", [](Login& loginObj) {
        return remove_login(loginObj.getLogin());
    }}
};


#endif