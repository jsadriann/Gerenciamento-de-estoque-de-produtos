import proxy as px
import adm_app as adm
import stock_app as stock
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
            user = input("User >> ")
            user_atual = user
            password = input("Password >> ")
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
            
            if opc == "1":
                adm.exec()
                # limpar_terminal()
                # menu_admin()
                # opc = input(">> ")
                # if opc == "1":
                #     user = input("User >> ")
                #     password = input("Password >> ")
                #     px.add_Login(user,password,incrementar_contador())
                # elif opc == "2":
                #     user = input("User >> ")
                #     px.remove_Login(user,incrementar_contador())
            elif opc == "2":
                stock.exec()
            elif opc == "3":
                break
            elif opc == "4":
                sys.exit()


        

    

if __name__ == '__main__':
    main()
