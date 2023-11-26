import proxy as px
import vendas_app as vendas
import os
import sys
import time
from menus import menu_stock
from global_counter import cont, increment
def limpar():
    from client import limpar_terminal
    limpar_terminal()

def exec():
    opc = -1
    limpar()
    while opc != "9":
        menu_stock()
        opc = input(">> ")
        if opc == "0":
            limpar()
            px.ListaEstoque(increment())
        elif opc == "1":
            name = input("Nome do produto: ")
            description = input("Descrição: ")
            fornecedor = input("Fornecedor: ")
            datafab = input("Data Fab(a-m-d)(xxxx-xx-xx): ")
            dataval = input("Data Val(a-m-d)(xxxx-xx-xx): ")
            qtd = input("quantidade: ")
            value = input("valor por unidade: ")
            produto = px.Produto(name,description,fornecedor,dataval,datafab,qtd,value)
            produto.AdicionaProduto(increment())
            limpar()
        elif opc == "2":
            break
        elif opc == "3":
            vendas.exec()
            limpar()
        elif opc == "4":
            break
        elif opc == "5":
            nome = input("Nome do Fornecedor: ")
            fornecedor = px.Fornecedor(0,nome)
            ret = fornecedor.AdicionaFornecedor(increment())
            if(ret == "-1"):
                print("Fornecedor já existe")
                time.sleep(3)
            elif (ret == "1"):
                print("Fornecedor adicionado com sucesso")
                time.sleep(2)
            limpar()
        elif opc == "6":
            nome = input("Nome do Fornecedor: ")
            fornecedor = px.Fornecedor(0,nome)
            ret = fornecedor.RemoveFornecedor(increment())
            if(ret == "0"):
                print("Fornecedor Existente")
            elif (ret == "1"):
                print("Fornecedor removido com sucesso")
            time.sleep(2)
            limpar()
        elif opc == "7":
            limpar()
            px.ListaFornecedor(increment())
        elif opc == "8":
            break
        elif opc == "9":
            break
        else:
            print("Opção inválida")
            time.sleep(1)
            limpar()
