#include "despaxante.h"
#include "skeleton.h"
using json = nlohmann::json;
int package_id(string pacote){
    json received_json = json::parse(pacote);
    int p_id = received_json["id"];
    return p_id;
}

std::string do_operation(std::string pacote,int idr){
    cout << "Package_in: "<<pacote << endl;
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
        packet = skeletonVendas(args,operation,idr);
    }else if(objref.compare("Fornecedor")==0){
        packet = skeletonFornecedor(args,operation,idr);
    }

    cout << "Package_out: "<< packet << std::endl;
    return packet;

}