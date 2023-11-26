#ifndef VENDAS_H
#define VENDAS_H
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <iostream>
using namespace std;
using json = nlohmann::json;


class Vendas {
public:
    Vendas();  // Construtor
    Vendas(int,string,int,string,float);
    int getId();
    string getproduto();
    int getQtd();
    string getData();
    float getValor();

    int RealizaVenda();
    vector<Vendas> ListaVenda();
    json to_json();
    void from_json(json&, Vendas&);


private:
    int id;
    string produto;
    int qtd;
    string data;
    float valor;
    void setId(int);
    void setProduto(string);
    void setQtd(int);
    void setData(string);
    void setValor(float);
};

string ListaVendasSelialize(vector<Vendas>);
string BuscaEstoque(string);



#endif