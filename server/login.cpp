#include "login.h"
#include "database.h"
extern std::unordered_map<std::string, std::function<int(Login&)>> loginMethodMap;
// Definição do construtor
Login::Login() {

}

Login::Login(string a, string b) {
    setLogin(a);
    setSenha(b);
}

string Login::getLogin(){
    return login;
}

string Login::getSenha(){
    return senha;
}

void Login::setLogin(string login){
    this->login = login;
}

void Login::setSenha(string senha){
    this->senha = senha;
}

int Login::verificaLogin(){
    cout << "RUN(): VerificaLogin()"<<endl;
    int ret;
    PGconn *database = connectDB();
    string aux = "SELECT * FROM Login where users='"+getLogin()+"'";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);

    if(countTupleDB(result) == 0){
        return 2;
    }

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        PQfinish(database);
        throw::runtime_error("not acess database");
    }

    string a = getValueDB(result,0,"users");
    string b = getValueDB(result,0,"password");
    
    if((login.compare(a) == 0) && (senha.compare(b) == 0))
        ret = 0;
    else if((login.compare(a) == 0) && (senha.compare(b) != 0))
        ret = 1;
    else 
        ret = 2;
    clearDB(result);
    closeDB(database);
    return ret;
}

int add_login(string user,string password){
    cout << "RUN(): AdicionaLogin()"<<endl;
    PGconn *database = connectDB();
    string aux = "INSERT INTO login(users,password) VALUES('"+user+"',"+"'"+password+"')";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);
    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        PQclear(result);
        PQfinish(database);
        return -1;
    }
    PQclear(result);
    PQfinish(database);
    return 1;

}

int remove_login(string user){
    cout << "RUN(): RemoveLogin()"<<endl;
    PGconn *database = connectDB();
    string aux = "DELETE FROM login WHERE users ='"+user+"'";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);
    if (atoi(PQcmdTuples(result)) == 0){
        PQclear(result);
        PQfinish(database);
        return -1;
    }
    PQclear(result);
    PQfinish(database);
    return 1;
}