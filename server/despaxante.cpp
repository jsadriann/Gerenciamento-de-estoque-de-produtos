#include "despaxante.h"

using json = nlohmann::json;

std::string do_operation(std::string pacote,int idr){
    Message message;
    std::cout << pacote << std::endl;
    json received_json = json::parse(pacote);
    std::string a = received_json["args"];
    json args = json::parse(a);
    std::string objref = received_json["objref"];
    std::string operation = received_json["operation"];
    string packet;

    if(objref.compare("Login") == 0){
        std::string user = args["user"];
        std::string password = args["password"];
        Login login = Login(user,password);
        if(operation.compare("check_login") == 0){
            int req = login.verificaLogin();
            std::string resp = to_string(req);
            message = Message(idr,1,"Login","check_login",resp);
            packet = message.to_json();
        }else if(operation.compare("add_login") == 0){
            int req = add_login(user,password);
            std::string resp = to_string(req);
            message = Message(idr,1,"Login","add_login",resp);
            packet = message.to_json();
        }else if(operation.compare("remove_login") == 0){
            int req = remove_login(user);
            std::string resp = to_string(req);
            message = Message(idr,1,"Login","remove_login",resp);
            packet = message.to_json();
        }
        
    }
    std::cout << packet << std::endl;
    return packet;


    // Acesse os campos do JSON
        // if (received_json.find("objref") != received_json.end()) {
        //     std::string obj = received_json["objref"];
        //     std::string oper = received_json["operation"];
        //     std::string user = args["user"];
        //     std::string passw = args["password"];
        //     std::cout << "objeto recebido: " << obj << std::endl;
        //     std::cout << "operação recebido: " << oper << std::endl;
        //     std::cout << "user recebido: " << user << std::endl;
        //     std::cout << "senha recebido: " << passw << std::endl;
        // }

}