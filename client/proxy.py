import socket
import json
i = 0
def from_json(json_string):
    message_dict = json.loads(json_string)
    return message_dict
    
def do_operation(req,objref,operation,args):
    message = Message.create_message(req,0,objref,operation,args)
    packet = message.to_json()
    a =""
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as proxy_socket:
        port = 8080
        server = 'localhost'
        proxy_socket.sendto(packet.encode(),(server,port))
        a, server_response_address = proxy_socket.recvfrom(1024)

    return a

class Message:
    def __init__(self,a,status, objref, operation, args):
        self.id = a
        self.status = status
        self.objref = objref
        self.operation = operation
        self.args = args

    @classmethod
    def create_message(cls,id,status, objref, operation, args):
        return cls(id,status,objref, operation, args)

    def to_json(self):
        message_dict = {
            "id": self.id,
            "status": self.status,
            "objref": self.objref,
            "operation": self.operation,
            "args": json.dumps(self.args)
        }
        return json.dumps(message_dict)
    


class Login:
    def __init__(self,user,password):
        self.user = user
        self.password = password
    
    def efetua_login(self,req):
        packet = do_operation(req,"Login","check_login",self.__dict__)
        a = from_json(packet)

        return a['args']

def remove_Login(usuario,req):
    pack = Login(usuario,"")
    packet = do_operation(req,"Login","remove_login",pack.__dict__)
    a = from_json(packet)
    if a['args'] == "-1":
        print("Verifique o nome do usuario e tente novamente\n")
    else:
        print("usuario removido com sucesso\n")

def add_Login(usuario,senha,req):
    pack = Login(usuario,senha)
    packet = do_operation(req,"Login","add_login",pack.__dict__)
    a = from_json(packet)
    if a['args'] == "-1":
        print("usuario existente\n")
    else:
        print("usuario cadastrado com sucesso\n")



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
