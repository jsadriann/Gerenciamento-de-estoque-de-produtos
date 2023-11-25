#include "fornecedor.h"
#include "database.h"
#include <iostream>
extern std::unordered_map<std::string, function<int(Fornecedor&, string)>>fornecedorMethodMap;
// Definição do construtor
Fornecedor::Fornecedor() {

}

Fornecedor::Fornecedor(int a, string b) {
    setId(a);
    setNome(b);
}

int Fornecedor::getId(){
    return id;
}

string Fornecedor::getNome(){
    return nome;
}

void Fornecedor::setId(int id){
    this->id = id;
}

void Fornecedor::setNome(string nome){
    this->nome = nome;
}

int Fornecedor::AdicionaFornecedor(){
    PGconn *database = connectDB();
    string aux = "INSERT INTO fornecedor(nome) VALUES('"+nome+"')";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);
    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        PQclear(result);
        PQfinish(database);
        return -1;
    }

    // if (PQresultStatus(result) == PGRES_FATAL_ERROR) {
    // // Um erro fatal ocorreu. Verifique o código de status para obter detalhes específicos.
    //     const char *errorStatus = PQresultErrorField(result, PG_DIAG_SQLSTATE);

    //     if (strcmp(errorStatus, "23505") == 0) {
    //         // Violou uma restrição única (código SQLSTATE 23505).
    //         // Lide com isso conforme necessário.
    //         return 0;
    //     }
    // }
    PQclear(result);
    PQfinish(database);
    return 1;
}

int Fornecedor::RemoveFornecedor(string nome){
    PGconn *database = connectDB();
    string aux = "DELETE FROM fornecedor WHERE nome='"+getNome()+"'";
    cout<<aux<<endl;
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);
    // if (PQresultStatus(result) != PGRES_TUPLES_OK) {
    //     PQclear(result);
    //     PQfinish(database);
    //     return -1;
    // }
    if (atoi(PQcmdTuples(result)) == 0){
        PQclear(result);
        PQfinish(database);
        return 0;
    }
    PQclear(result);
    PQfinish(database);
    return 1;
}
vector<Fornecedor> Fornecedor::ListaFornecedor(){
    PGconn *database = connectDB();
    string aux = "SELECT * FROM fornecedor";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        PQfinish(database);
        throw::runtime_error("not acess database");
    }
    vector<Fornecedor> forn;
    int numRows = PQntuples(result);
    for(int row = 0; row < numRows; row++){
        Fornecedor aux = Fornecedor(stoi(getValueDB(result,row,"id")),getValueDB(result,row,"nome"));
        forn.push_back(aux);
    }
    PQclear(result);
    PQfinish(database);
    return forn;
}
json Fornecedor::to_json(){
    json j = json{
        {"id",getId()},
        {"nome", getNome()}
    };
    cout << j.dump() << endl;
    return j;
}

void Fornecedor::from_json(json& j, Fornecedor& forn){
    forn.setId(j.at("id").get<int>());
    forn.setNome(j.at("nome").get<std::string>());
}

string ListaFornecedorSelialize(vector<Fornecedor> forn){
    json j;
    for ( auto& item : forn) {
        j.push_back(item.to_json());
    }
    return j.dump();
}