#include "skeleton.h"


string skeletonLogin(string arg,string method,int idr){
    json args = json::parse(arg);
    int result;
    try{
        auto it = loginMethodMap.find(method);
        std::string user = args["user"];
        std::string password = args["password"];
        Login login = Login(user,password);
        result = it->second(login);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Exceção: " << e.what() << std::endl;
        result = -1;
    } catch (const std::exception& e) {
        std::cerr << "Exceção: " << e.what() << std::endl;
        result = -1;
    }

    std::string resp = to_string(result);
    Message message = Message(idr,1,"Login",method,resp);
    return message.to_json();
}

string skeletonProduto(string arg,string method,int idr){
    json args = json::parse(arg);
    int result;
    string resp;
    Estoque a;
    if (method.compare("ListaEstoque")==0){
        try
        {
            vector<Estoque> estoque = a.ListaEstoque("");
            resp = ListaEstoqueSelialize(estoque);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exceção: log" << e.what() << std::endl;
            resp = "-1";
        }
    }else{
        try{
            auto it = estoqueMethodMap.find(method);
            int id = args["id"];
            string name = args["name"];
            string description = args["description"];
            string fornecedor = args["fornecedor"];
            string dataval = args["dataval"];
            string datafab = args["datafab"];
            string qtd = args["qtd"];
            string value = args["value"];
            Estoque produto = Estoque(id,name,description,fornecedor,dataval,datafab,stoi(qtd),stof(value));
            result = it->second(produto,"");
            resp = to_string(result);
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "Exceção: aqui" << e.what() << std::endl;
            result = -1;
            resp = to_string(result);
        } catch (const std::exception& e) {
            std::cerr << "Exceção: ali" << e.what() << std::endl;
            result = -1;
            resp = to_string(result);
        }
    }

    Message message = Message(idr,1,"Estoque",method,resp);
    return message.to_json();
}

string skeletonFornecedor(string arg,string method,int idr){
    json args = json::parse(arg);
    int result;
    string resp;
    Fornecedor a;
    if (method.compare("ListaFornecedor")==0){
        try
        {
            vector<Fornecedor> forn = a.ListaFornecedor();
            resp = ListaFornecedorSelialize(forn);
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << "Exceção: log" << e.what() << std::endl;
            resp = "-1";
        }
    }else{
        try{
            auto it = fornecedorMethodMap.find(method);
            string nome = args["nome"];
            Fornecedor forn = Fornecedor(0,nome);
            result = it->second(forn,nome);
            resp = to_string(result);
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "Exceção: aqui" << e.what() << std::endl;
            result = -1;
            resp = to_string(result);
        } catch (const std::exception& e) {
            std::cerr << "Exceção: ali" << e.what() << std::endl;
            result = -1;
            resp = to_string(result);
        }
    }

    Message message = Message(idr,1,"Fornecedor",method,resp);
    return message.to_json();
}

string skeletonVendas(string arg,string method,int idr){
    json args = json::parse(arg);
    int result;
    string resp;
    Vendas a;
    if (method.compare("RealizaVenda")==0){
        try
        {
            string ids = args["id"];
            string qtds = args["qtd"];
            int id,qtd;
            if((ids.compare("")==0) || (qtds.compare("")==0)){
                id = -1;
                qtd = -1;
            }else{
                id = stoi(ids);
                qtd = stoi(qtds);
            }
            Vendas ven = Vendas(id,"",qtd,"",0.0);
            resp = to_string(ven.RealizaVenda());
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << "Exceção: log" << e.what() << std::endl;
            resp = "-1";
        }


    }else if(method.compare("BuscaEstoque")==0){
        try
        {

            resp = BuscaEstoque(args["nome"]);
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << "Exceção: log" << e.what() << std::endl;
            resp = "-1";
        }
    }else if(method.compare("ListaVenda")==0){
        try{
            vector<Vendas> forn = a.ListaVenda();
            resp = ListaVendasSelialize(forn);
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "Exceção: aqui" << e.what() << std::endl;
            result = -1;
            resp = to_string(result);
        } catch (const std::exception& e) {
            std::cerr << "Exceção: ali" << e.what() << std::endl;
            result = -1;
            resp = to_string(result);
        }
    }

    Message message = Message(idr,1,"Venda",method,resp);
    return message.to_json();
}
