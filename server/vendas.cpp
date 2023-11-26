#include "vendas.h"
#include "database.h"
#include "produto.h"
#include <iomanip>
#include <chrono>
#include <ctime>

string obterDataAtual() {
    // Obter o tempo atual em segundos desde o epoch
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Converter o tempo para uma estrutura tm (struct tm)
    std::tm localTime = *std::localtime(&currentTime);

    // Formatar a data no formato "Ano-Mes-Dia"
    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d");
    cout << oss.str()<<endl;
    
    return oss.str();
}

// Definição do construtor
Vendas::Vendas() {

}

Vendas::Vendas(int id,string produto,int qtd,string data,float valor) {
    setId(id);
    setProduto(produto);
    setQtd(qtd);
    setData(data);
    setValor(valor);
}

int Vendas::getId(){
    return id;
}
string Vendas::getproduto(){
    return produto;
}
int Vendas::getQtd(){
    return qtd;
}
string Vendas::getData(){
    return data;
}
float Vendas::getValor(){
    return valor;
}

void Vendas::setId(int id){
    this->id = id;
}
void Vendas::setProduto(string produto){
    this->produto = produto;
}
void Vendas::setQtd(int qtd){
    this->qtd = qtd;
}
void Vendas::setData(string data){
    this->data = data;
}
void Vendas::setValor(float valor){
    this->valor = valor;
}


int Vendas::RealizaVenda(){
    cout << "RUN(): RealizaVenda()"<<endl;
    PGconn *database = connectDB();
    string aux = "SELECT * FROM produto where id='"+to_string(getId())+"'";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        PQfinish(database);
        return -1; 
    }

    if (atoi(PQcmdTuples(result)) == 0){
        PQclear(result);
        PQfinish(database);
        return 1;
    }
    int qtdd = stoi(getValueDB(result,0,"quantidade"));
    if(this->qtd > qtdd){
        PQclear(result);
        PQfinish(database);
        return 0;
    }

    string aux1 = "UPDATE produto set quantidade='"+to_string((qtdd-qtd))+"' where id='"+to_string(getId())+"'";
    const char *query1 = aux1.c_str();
    PGresult *result1 = consultDB(database,query1);
    if (PQresultStatus(result1) != PGRES_COMMAND_OK || qtd < 1) {
        PQclear(result1);
        PQfinish(database);
        return -1; 
    }
    if (atoi(PQcmdTuples(result1)) == 0){
        PQclear(result1);
        PQfinish(database);
        return -1;
    }
    PQclear(result1);
    //venda pode ser realizada
    setProduto(getValueDB(result,0,"nome"));
    setQtd(qtd);
    setData(obterDataAtual());
    setValor(atof(getValueDB(result,0,"valor")));

    PQclear(result);

    string aux2 = "INSERT INTO vendas(produto_id,qtd,data,valor) VALUES('"+to_string(getId())+"','"+to_string(qtd)+"','"+getData()+"','"+to_string(qtd*getValor())+"')";
    const char *query2 = aux2.c_str();
    PGresult *result2 = consultDB(database, query2);

    PQclear(result2);
    PQfinish(database);
    return 2;
}

vector<Vendas> Vendas::ListaVenda(){
    cout << "RUN(): ListaVenda()"<<endl;
    PGconn *database = connectDB();
    string aux = "SELECT * FROM vendas";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        PQfinish(database);
        throw::runtime_error("not acess database");
    }
    vector<Vendas> forn;
    int numRows = PQntuples(result);
    for(int row = 0; row < numRows; row++){
        int t = atoi(getValueDB(result,row,"produto_id"));
        string aux1 = "SELECT * FROM produto where id='"+to_string(t)+"'";
        const char *query1 = aux1.c_str();
        PGresult *result1 = consultDB(database,query1);
        if(countTupleDB(result1) == 0){
            PQclear(result1);
            PQfinish(database);
            throw::runtime_error("error");
        }
        string x = getValueDB(result1,0,"nome");
        Vendas aux = Vendas(atoi(getValueDB(result,row,"id")),x,atoi(getValueDB(result,row,"qtd")),getValueDB(result,row,"data"),atof(getValueDB(result,row,"valor")));
        forn.push_back(aux);
    }
    PQclear(result);
    PQfinish(database);
    return forn;
}

json Vendas::to_json(){
    json j = json{
        {"id",getId()},
        {"produto", getproduto()},
        {"data",getData()},
        {"qtd",getQtd()},
        {"valor",getValor()}
    };
    cout << j.dump() << endl;
    return j;
}

void Vendas::from_json(json& j, Vendas& forn){
    forn.setId(j.at("id").get<int>());
    forn.setProduto(j.at("produto").get<std::string>());
    forn.setData(j.at("data").get<std::string>());
    forn.setQtd(j.at("qtd").get<int>());
    forn.setValor(j.at("valor").get<float>());
}

string ListaVendasSelialize(vector<Vendas> forn){
    cout << "RUN(): ListaVenda()"<<endl;
    json j;
    for ( auto& item : forn) {
        j.push_back(item.to_json());
    }
    return j.dump();
}

string BuscaEstoque(string busca){
    cout << "RUN(): BuscaEstoque()"<<endl;
    Estoque aux;
    vector<Estoque> ret = aux.ListaEstoque(busca);

    json j;
    for ( auto& item : ret) {
        j.push_back(json{
        {"id",item.getId()},
        {"name", item.getName()},
        {"qtd", item.getQtd()},
        {"value",item.getValue()}});
    }
    return j.dump();    

}