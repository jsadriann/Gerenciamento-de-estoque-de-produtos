import socket
import json
i = 0
def imprimir_fornecedor(objeto):
    if isinstance(objeto, str):
        objeto = json.loads(objeto)
    print("ID:", objeto["id"])
    print("Nome:", objeto["nome"])
    print("----------------------------------------")

def imprimir_produto(objeto):
    if isinstance(objeto, str):
        objeto = json.loads(objeto)
    print("ID:", objeto["id"])
    print("Nome:", objeto["name"])
    print("Descrição:", objeto["description"])
    print("Fornecedor:", objeto["fornecedor"])
    print("Data de Validade:", objeto["dataval"])
    print("Data de Fabricação:", objeto["datafab"])
    print("Quantidade:", objeto["qtd"])
    print("Valor:", objeto["value"])
    print("----------------------------------------")

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
        timeout_segundos = 1
        proxy_socket.settimeout(timeout_segundos)
        cont = 0
        while cont < 5:
            try:
                a, server_response_address = proxy_socket.recvfrom(1024)
                break
            except socket.timeout:
                cont+=1
        if cont == 5:
            return -1
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
        packet = do_operation(req,"Login","verificaLogin",self.__dict__)
        if packet == -1:
            print("SERVIDOR FORA DO AR")
            return -1
        a = from_json(packet)

        return a['args']

def remove_Login(usuario,req):
    pack = Login(usuario,"")
    packet = do_operation(req,"Login","remove_login",pack.__dict__)
    if packet == -1:
        print("SERVIDOR FORA DO AR")
        return -1
    a = from_json(packet)
    if a['args'] == "-1":
        print("Verifique o nome do usuario e tente novamente\n")
    else:
        print("usuario removido com sucesso\n")

def add_Login(usuario,senha,req):
    pack = Login(usuario,senha)
    packet = do_operation(req,"Login","add_login",pack.__dict__)
    if packet == -1:
        print("SERVIDOR FORA DO AR!!!")
        return -1
    a = from_json(packet)
    if a['args'] == "-1":
        print("usuario existente\n")
    else:
        print("usuario cadastrado com sucesso\n")

class Produto:
    def __init__(self, name, description, fornecedor, dataval, datafab, qtd,value):
        self.id = 0
        self.name = name
        self.description = description
        self.fornecedor = fornecedor
        self.dataval = dataval
        self.datafab = datafab
        self.qtd = qtd
        self.value = value
    
    def AdicionaProduto(self,req):
        packet = do_operation(req,"Estoque","AdicionaProduto",self.__dict__)
        if packet == -1:
            print("SERVIDOR FORA DO AR")
            return -1
        
        a = from_json(packet)
        print(a)
        if a['args'] == "-1":
            print("Não foi possível encontrar esse\nfornecedor")

        return a['args']
    
def ListaEstoque(req):
    packet = do_operation(req,"Estoque","ListaEstoque","")
    if packet == -1:
        print("SERVIDOR FORA DO AR")
    else:
        a = from_json(packet)
        if a['args'] == "-1":
            print("Sentimos muito, mas Houve um problema \ncom o servidor, tente novamente")
        elif a['args'] == "null":
            print("Nenhum produto no estoque")
        else:
            lista = json.loads(a['args'])
            for objeto in lista:
                imprimir_produto(objeto)

class Fornecedor:
    def __init__(self,id,nome):
        self.id = 0
        self.nome = nome
    
    def AdicionaFornecedor(self,req):
        packet = do_operation(req,"Fornecedor","AdicionaFornecedor",self.__dict__)
        if packet == -1:
            print("SERVIDOR FORA DO AR")
            return -1
        print(packet)
        a = from_json(packet)

    def RemoveFornecedor(self,req):
        packet = do_operation(req,"Fornecedor","RemoveFornecedor",self.__dict__)
        if packet == -1:
            print("SERVIDOR FORA DO AR")
            return -1
        a = from_json(packet)

        return a['args']

def ListaFornecedor(req):
    packet = do_operation(req,"Fornecedor","ListaFornecedor","")
    if packet == -1:
        print("SERVIDOR FORA DO AR")
    else:
        a = from_json(packet)
        if a['args'] == "-1":
            print("Sentimos muito, mas Houve um problema \ncom o servidor, tente novamente")
        elif a['args'] == "null":
            print("Nenhum fornecedor encontrado")
        else:
            lista = json.loads(a['args'])
            for objeto in lista:
                imprimir_fornecedor(objeto)
