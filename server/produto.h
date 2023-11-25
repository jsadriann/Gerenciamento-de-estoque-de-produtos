#ifndef ESTOQUE_H
#define ESTOQUE_H
#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <nlohmann/json.hpp>
#include <stdexcept>
using namespace std;
using json = nlohmann::json;

class Estoque {
public:
    //Construtor e inicializador de atributos
    Estoque();
    Estoque(int,string,string,string,string,string,int,float);

    //Metodos Getters
    int    getId();
    string getName();
    string getDescription();
    string getFornecedor();
    string getDataVal();
    string getDataFab();
    int    getQtd();
    float  getValue();

    //Metodos de manipulação
    int VendeEstoque(string);
    int CompraEstoque(string);
    int AlteraValue(string);
    int AlteraNome(string);
    int AlteraDescription(string);
    int AlteraFornecedor(string);
    int AdicionaProduto();
    vector<Estoque> ListaEstoque();
    json to_json();
    void from_json(json&, Estoque&);

private:
    int    id;
    string name;
    string description;
    string fornecedor;
    string dataval;
    string datafab;
    int qtd;
    float value;

    //Metodos Setters
    void setName(string);
    void setDescription(string);
    void setFornecedor(string);
    void setDataVal(string);
    void setDataFab(string);
    void setQtd(int);
    void setValue(float);

};

string ListaEstoqueSelialize(vector<Estoque>);

static std::unordered_map<std::string, function<int(Estoque&, string)>>estoqueMethodMap = {
    {"VendeEstoque", [](Estoque& e, string quantidade) { return e.VendeEstoque(quantidade); }},
    {"CompraEstoque", [](Estoque& e, string quantidade) { return e.CompraEstoque(quantidade); }},
    {"AlteraValue", [](Estoque& e, string novoValor) { return e.AlteraValue(novoValor); }},
    {"AlteraNome", [](Estoque& e, string novoNome) { return e.AlteraNome(novoNome); }},
    {"AlteraDescription", [](Estoque& e, string novaDescricao) { return e.AlteraDescription(novaDescricao); }},
    {"AlteraFornecedor", [](Estoque& e, string novoFornecedor) { return e.AlteraFornecedor(novoFornecedor); }},
    {"AdicionaProduto", [](Estoque& e,string a) { return e.AdicionaProduto(); }},
    // Adicione outros métodos conforme necessário...
};

#endif