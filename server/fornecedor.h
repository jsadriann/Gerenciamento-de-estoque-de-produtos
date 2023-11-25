#ifndef FORNECEDOR_H
#define FORNECEDOR_H
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <nlohmann/json.hpp>
#include <stdexcept>
using namespace std;
using json = nlohmann::json;


class Fornecedor {
public:
    Fornecedor();  // Construtor
    Fornecedor(int,string);
    int getId();
    string getNome();
    int AdicionaFornecedor();
    int RemoveFornecedor(string);
    vector<Fornecedor> ListaFornecedor();
    json to_json();
    void from_json(json&, Fornecedor&);


private:
    int id;
    string nome;
    void setId(int);
    void setNome(string);
};

string ListaFornecedorSelialize(vector<Fornecedor>);

static std::unordered_map<std::string, function<int(Fornecedor&, string)>>fornecedorMethodMap = {
    {"AdicionaFornecedor", [](Fornecedor& e, string quantidade) { return e.AdicionaFornecedor(); }},
    {"RemoveFornecedor", [](Fornecedor& e, string nome) { return e.RemoveFornecedor(nome); }},
};

#endif