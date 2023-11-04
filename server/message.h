#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

class Message {
public:
    Message();  // Construtor
    Message(string,string,string);
    string to_json();
    string from_json();

private:
    string objref;
    string operation;
    string args;
};

#endif