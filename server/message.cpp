#include "message.h"

// Definição do construtor
Message::Message() {
    
    objref="";
    operation="";
    args="";
}

Message::Message(string a, string b, string c) {
    objref=a;
    operation=b;
    args=c;
}

string Message::to_json(){
    nlohmann::json jsonresp;
    jsonresp["args"] = this->args;
    jsonresp["operation"] = this->operation;
    jsonresp["objref"] = this->objref;
    
    string resposta = jsonresp.dump();
    return resposta;
}