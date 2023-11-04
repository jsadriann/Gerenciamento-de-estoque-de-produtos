import customtkinter as ctk
from tkinter import PhotoImage
from PIL import Image
ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("green")

def button_login():
    print("botão login")

class Frame_cadastro_produto(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.config_init_window()
        self.tela_cadastro_produto()

    #configurando a janela de login
    def config_init_window(self):
        self.geometry("700x400")
        self.title("LOGIN")
        self.resizable(False,False)
    
    def tela_cadastro_produto(self):
        #inserindo imagem/logo
        # self.img = ctk.CTkImage(light_image=Image.open("logo6.png"),
        #                           dark_image=Image.open("logo6.png"),
        #                           size=(320, 400))
        # self.lb_img = ctk.CTkLabel(self, text=None, image=self.img)
        # self.lb_img.grid(row=1,column=0, padx=10)