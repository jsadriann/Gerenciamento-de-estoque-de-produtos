import proxy as px
import os
import sys
import time
from menus import menu_vendas
from global_counter import cont, increment
def limpar():
    from client import limpar_terminal
    limpar_terminal()

def exec():
    opc = -1
    limpar()
    while opc != "2":
        menu_vendas()
        opc = input(">> ")
        if opc == "0":
            limpar()
            px.RealizarVenda(increment())
            time.sleep(3) 
            limpar()           
        elif opc == "1":
            limpar()
            px.ListaVenda(increment())
        elif opc == "2":
            break
        else:
            print("Opção inválida")
            time.sleep(2)
            limpar()