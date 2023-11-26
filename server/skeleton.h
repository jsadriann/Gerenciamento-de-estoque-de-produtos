#ifndef SKELETON_H
#define SKELETON_H
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "message.h"
#include "login.h"
#include "produto.h"
#include "vendas.h"
#include "fornecedor.h"
using namespace std;

string skeletonLogin(string,string,int);
string skeletonProduto(string,string,int);
string skeletonFornecedor(string,string,int);
string skeletonVendas(string,string,int);


#endif