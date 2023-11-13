import proxy as px
import sys
from menus import menu_inicial,menu_login,menu_stock,menu_admin
global user_atual
req = 0
# Função para incrementar o contador global
def incrementar_contador():
    global req
    req += 1
    return req
# Função para obter o valor atual do contador global
def obter_contador():
    return req

def main():
    req = 0
    while True:
        while True:
            menu_login()
            user = input("User >> ")
            user_atual = user
            password = input("Password >> ")
            login = px.Login(user,password)
            next = login.efetua_login(incrementar_contador())
            if next == "0":
                break
            elif next == "1":
                print("Senha incorreta\n")
            else:
                print("Verifique os dados e tente novamente!!!")

        while True:
            menu_inicial(user_atual)
            opc = input(">> ")
            
            if opc == "1":
                menu_admin()
                opc = input(">> ")
                if opc == "1":
                    user = input("User >> ")
                    password = input("Password >> ")
                    px.add_Login(user,password,incrementar_contador())
                elif opc == "2":
                    user = input("User >> ")
                    px.remove_Login(user,incrementar_contador())
            elif opc == "2":
                break
            elif opc == "3":
                break
            elif opc == "4":
                sys.exit()


        

    

if __name__ == '__main__':
    main()
