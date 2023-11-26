import proxy as px
import adm_app as adm
import stock_app as stock
import getpass
import curses
import os
import sys
import time
from menus import menu_inicial,menu_login,menu_stock,menu_admin
from global_counter import cont, increment

global user_atual
def limpar_terminal():
    os.system('clear')

def main():
    req = 0
    while True:
        limpar_terminal()
        while True:
            menu_login()
            user = input("User: ")
            user_atual = user
            password = getpass.getpass("Senha: ")
            login = px.Login(user,password)
            next = login.efetua_login(increment())
            if next == "0":
                break
            elif next == "1":
                print("Senha incorreta\n")
            elif next == "2":
                print("Verifique os dados e tente novamente!!!")
            time.sleep(3)
            limpar_terminal()

        
        while True:
            limpar_terminal()
            menu_inicial(user_atual)
            opc = input(">> ")
            
            if opc == "0":
                adm.exec()
            elif opc == "1":
                stock.exec()
            elif opc == "2":
                break
            elif opc == "3":
                sys.exit()
            else:
                print("Opção inválida")
                time.sleep(1)
                limpar_terminal()


        

    

if __name__ == '__main__':
    main()
