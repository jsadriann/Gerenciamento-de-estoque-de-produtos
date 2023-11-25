#include "despaxante.h"
#include "skeleton.h"
using json = nlohmann::json;
int package_id(string pacote){
    json received_json = json::parse(pacote);
    int p_id = received_json["id"];
    return p_id;
}

std::string do_operation(std::string pacote,int idr){
    std::cout << pacote << std::endl;
    json received_json = json::parse(pacote);
    std::string args = received_json["args"];
    std::string objref = received_json["objref"];
    std::string operation = received_json["operation"];
    string packet;

    if(objref.compare("Login")==0){
        packet = skeletonLogin(args,operation,idr);
    }else if(objref.compare("Estoque")==0){
        packet = skeletonProduto(args,operation,idr);
    }else if(objref.compare("Venda")==0){

    }else if(objref.compare("Fornecedor")==0){
        cout<<"forn"<<endl;
        packet = skeletonFornecedor(args,operation,idr);
    }

    std::cout << packet << std::endl;
    return packet;

}