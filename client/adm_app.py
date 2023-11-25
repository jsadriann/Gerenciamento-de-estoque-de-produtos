import proxy as px
from client import limpar_terminal
import os
import sys
import time
from menus import menu_admin
from global_counter import cont, increment

def exec():
    opc = -1
    while opc != "3":
        limpar_terminal()
        menu_admin()
        opc = input(">> ")
        if opc == "1":
            user = input("User >> ")
            password = input("Password >> ")
            px.add_Login(user,password,increment())
        elif opc == "2":
            user = input("User >> ")
            px.remove_Login(user,increment())
        elif opc == "3":
            break
        time.sleep(3)

