#include "message.h"

// Definição do construtor
Message::Message() {
    id = 0;
    status = 0;
    objref="";
    operation="";
    args="";
}

Message::Message(int id, int status,string a, string b, string c) {
    this->id = id;
    this->status = status;
    objref=a;
    operation=b;
    args=c;
}

string Message::to_json(){
    nlohmann::json jsonresp;
    jsonresp["args"] = this->args;
    jsonresp["operation"] = this->operation;
    jsonresp["objref"] = this->objref;
    jsonresp["status"] = this->status;
    jsonresp["id"] = this->id;
    
    string resposta = jsonresp.dump();
    return resposta;
}