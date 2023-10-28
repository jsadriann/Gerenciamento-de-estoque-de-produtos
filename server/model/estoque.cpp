#include "estoque.h"

 //Construtor e inicializador de atributos
Estoque::Estoque(){
    name="";
    description="";
    tipo="";
    fornecedor="";
    qtd=0;
    value=0.0;
}

Estoque::Estoque(string name,string description,string tipo,string fornecedor,int qtd,float value){
    this->name = name;
    this->description = description;
    this->tipo = tipo;
    this->fornecedor = fornecedor;
    this->qtd = qtd;
    this->value = value;
}

//Metodos Getters
string Estoque::getName(){
    return name;
}
string Estoque::getDescription(){
    return description;
}
string Estoque::getTipo(){
    return tipo;
}
string Estoque::getFornecedor(){
    return fornecedor;
}
int    Estoque::getQtd(){
    return qtd;
}
float  Estoque::getValue(){
    return value;
}

//Metodos de manipulação
void Estoque::VendeEstoque(int value){
    if( this->qtd - value >= 0)
        setQtd(this->qtd - value);
    else
        printf("estoque insuficiente\n");   
}

void Estoque::CompraEstoque(int value){
    setQtd(this->qtd + value);
}

void Estoque::AlteraValue(float value){
    if(value < 0)
        printf("valor incorreto\r");
    else
        setValue(value);
}

void Estoque::AlteraNome(string nome){
    setName(nome);
}

void Estoque::AlteraDescription(string description){
    setDescription(description);
}

void Estoque::AlteraTipo(string tipo){
    setTipo(tipo);
}

void Estoque::AlteraFornecedor(string fornecedor){
    setFornecedor(fornecedor);
}

//Metodos Setters
void Estoque::setName(string name){
    this->name = name;
}
void Estoque::setDescription(string description){
    this->description = description;
}

void Estoque::setTipo(string tipo){
    this->tipo = tipo;
}

void Estoque::setFornecedor(string fornecedor){
    this->fornecedor = fornecedor;
}

void Estoque::setQtd(int qtd){
    this->qtd = qtd;
}

void Estoque::setValue(float value){
    this->value = value;
}