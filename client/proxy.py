import socket
import json

# class Produto:
#     def __init__(self,id,name,qtd,value,description,distribut):
#         self.id = id
#         self.name = name
#         self.qtd = qtd
#         self.value = value
#         self.description = description
#         self.distribut = distribut
    
#     def Vende_Produto(self,qtd):
#         algo
#     def Compra_Produto(self,qtd):
#         algo
#     def Print_produto(self):
#         algo
#     def Altera_Distribut(self):
#         algo
def from_json(json_string):
    message_dict = json.loads(json_string)
    return message_dict
    
def do_operation(objref,operation,args):
    message = Message.create_message(objref,operation,args)
    packet = message.to_json()
    a =""
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as proxy_socket:
        port = 8080
        server = 'localhost'
        proxy_socket.sendto(packet.encode(),(server,port))
        a, server_response_address = proxy_socket.recvfrom(1024)

    return a

class Message:
    def __init__(self, objref, operation, args):
        self.objref = objref
        self.operation = operation
        self.args = args

    @classmethod
    def create_message(cls, objref, operation, args):
        return cls(objref, operation, args)

    def to_json(self):
        message_dict = {
            "objref": self.objref,
            "operation": self.operation,
            "args": json.dumps(self.args)
        }
        return json.dumps(message_dict)
    


class Login:
    def __init__(self,user,password):
        self.user = user
        self.password = password
    
    def efetua_login(self):
        packet = do_operation("Login","check_login",self.__dict__)
        a = from_json(packet)
        print(a)

        return a['args']





# def envia(data, server_address):


#         response = proxy_socket.recv(1024).decode()
#         return response

# server_address = ('127.0.0.1', 12345)
#     data = {
#         "operacao": "somar",
#         "valores": [5, 3]
#     }

#     with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
#         client_socket.connect(server_address)
#         json_data = json.dumps(data)
#         client_socket.send(json_data.encode())

#         response = client_socket.recv(1024).decode()
#         print("Response from server:", response)
