#ifndef ESTOQUE_H
#define ESTOQUE_H
#include <string>
using namespace std;

class Estoque {
public:
    //Construtor e inicializador de atributos
    Estoque();
    Estoque(string,string,string,string,int,float);

    //Metodos Getters
    string getName();
    string getDescription();
    string getTipo();
    string getFornecedor();
    int    getQtd();
    float  getValue();

    //Metodos de manipulação
    void VendeEstoque(int);
    void CompraEstoque(int);
    void AlteraValue(float);
    void AlteraNome(string);
    void AlteraDescription(string);
    void AlteraTipo(string);
    void AlteraFornecedor(string);


private:
    string name;
    string description;
    string tipo;
    string fornecedor;
    int qtd;
    float value;

    //Metodos Setters
    void setName(string);
    void setDescription(string);
    void setTipo(string);
    void setFornecedor(string);
    void setQtd(int);
    void setValue(float);

};

#endif