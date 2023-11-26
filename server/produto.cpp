#include "produto.h"
#include "database.h"

extern std::unordered_map<std::string, function<int(Estoque&, string)>>estoqueMethodMap;
 //Construtor e inicializador de atributos
Estoque::Estoque(){
    name="";
    description="";
    fornecedor="";
    dataval = "";
    datafab = "";
    qtd=0;
    value=0.0;
}

Estoque::Estoque(int id,string name,string description,string fornecedor,string dataval,string datafab,int qtd,float value){
    this->id = id;
    this->name = name;
    this->description = description;
    this->fornecedor = fornecedor;
    this->dataval = dataval;
    this->datafab = datafab;
    this->qtd = qtd;
    this->value = value;
}

//Metodos Getters
int Estoque::getId(){
    return id;
}
string Estoque::getName(){
    return name;
}
string Estoque::getDescription(){
    return description;
}
string Estoque::getFornecedor(){
    return fornecedor;
}
string Estoque::getDataVal(){
    return dataval;
}
string Estoque::getDataFab(){
    return datafab;
}
int    Estoque::getQtd(){
    return qtd;
}
float  Estoque::getValue(){
    return value;
}

//Metodos de manipulação

int Estoque::VendeEstoque(string value){
  
    return 1;
}

int Estoque::CompraEstoque(string value){

    return 1;
}

int Estoque::AlteraValue(string value){

    return 1;
}

int Estoque::AlteraNome(string nome){
    setName(nome);
    return 1;
}

int Estoque::AlteraDescription(string description){
    setDescription(description);
    return 1;
}

int Estoque::AlteraFornecedor(string fornecedor){
    setFornecedor(fornecedor);
    return 1;
}

int Estoque::AdicionaProduto(){
    cout << "RUN(): AdicionaProduto()"<<endl;
    PGconn *database = connectDB();
    string aux = "SELECT * FROM fornecedor WHERE nome='"+getFornecedor()+ "'";
    const char *query1 = aux.c_str();
    PGresult *result = consultDB(database,query1);

    if (countTupleDB(result) == 0){
        PQclear(result);
        PQfinish(database);
        return -1;
    }
    string a = getValueDB(result,0,"id");

    PQclear(result);
    aux = "INSERT INTO produto(nome,descricao,data_fab,data_val,fornecedor_id,quantidade,valor) VALUES('"+name+"',"+"'"+description+"',"+"'"+datafab+"',"+"'"+dataval+"',"+"'"+a+"',"+"'"+to_string(qtd)+"',"+"'"+to_string(value)+"')";
    const char *query = aux.c_str();
    result = consultDB(database,query);
    if (PQresultStatus(result) != PGRES_COMMAND_OK) {
        PQclear(result);
        PQfinish(database);
        return 0;
    }
    PQclear(result);
    PQfinish(database);
    return 1;
}

vector<Estoque> Estoque::ListaEstoque(string busca){
    PGconn *database = connectDB();
    string aux = "SELECT * FROM produto WHERE nome ILIKE '%"+busca+"%'";
    const char *query = aux.c_str();
    PGresult *result = consultDB(database,query);
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        PQclear(result);
        PQfinish(database);
        throw::runtime_error("error");
    }

    vector<Estoque> estoque;
    int numRows = PQntuples(result);
    for(int row = 0; row < numRows; row++){
        string t = getValueDB(result,row,"fornecedor_id");
        string aux1 = "SELECT * FROM fornecedor where id='"+t+"'";
        const char *query1 = aux1.c_str();

        PGresult *result1 = consultDB(database,query1);
        if(countTupleDB(result1) == 0){
            PQclear(result1);
            PQfinish(database);
            throw::runtime_error("error");
        }
        string x = getValueDB(result1,0,"nome");
        Estoque aux = Estoque(stoi(getValueDB(result,row,"id")),getValueDB(result,row,"nome"),getValueDB(result,row,"descricao"),x,getValueDB(result,row,"data_val"),getValueDB(result,row,"data_fab"),stoi(getValueDB(result,row,"quantidade")),stof(getValueDB(result,row,"valor")));
        estoque.push_back(aux);
    }
    PQclear(result);
    PQfinish(database);
    return estoque;

}

string ListaEstoqueSelialize(vector<Estoque> estoque){
    cout << "RUN(): ListaEstoque()"<<endl;
    json j;
    for ( auto& item : estoque) {
        j.push_back(item.to_json());
    }
    return j.dump();
}

json Estoque::to_json() {
    json j = json{
        {"id",getId()},
        {"name", getName()},
        {"description", getDescription()},
        {"fornecedor", getFornecedor()},
        {"dataval", getDataVal()},
        {"datafab", getDataFab()},
        {"qtd", getQtd()},
        {"value", getValue()}
    };
    cout << j.dump() << endl;
    return j;
}

// Adicione o método from_json se precisar desserializar JSON para um objeto Estoque
void Estoque::from_json( json& j, Estoque& estoque) {
    estoque.setName(j.at("name").get<std::string>());
    estoque.setDescription(j.at("description").get<std::string>());
    estoque.setFornecedor(j.at("fornecedor").get<std::string>());
    estoque.setDataVal(j.at("dataval").get<std::string>());
    estoque.setDataFab(j.at("datafab").get<std::string>());
    estoque.setQtd(j.at("qtd").get<int>());
    estoque.setValue(j.at("value").get<float>());
}
//Metodos Setters
void Estoque::setName(string name){
    this->name = name;
}
void Estoque::setDescription(string description){
    this->description = description;
}

void Estoque::setFornecedor(string fornecedor){
    this->fornecedor = fornecedor;
}
void Estoque::setDataVal(string dataval){
    this->dataval = dataval;
}
void Estoque::setDataFab(string datafab){
    this->datafab = datafab;
}
void Estoque::setQtd(int qtd){
    this->qtd = qtd;
}

void Estoque::setValue(float value){
    this->value = value;
}