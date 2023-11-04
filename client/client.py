import proxy as px
from menus import menu_inicial,menu_login,menu_stock

def main():

    while True:
        while True:
            menu_login()
            user = input("User >> ")
            password = input("Password >> ")
            login = px.Login(user,password)
            next = login.efetua_login()
            if next == "0":
                break
            elif next == "1":
                print("Senha incorreta\n")
            elif next == "2":
                print("User incorreto\n")
            else:
                print("Verifique os dados e tente novamente!!!")
        menu_inicial()
        opc = input(">> ")
        

    

if __name__ == '__main__':
    main()
