import customtkinter as ctk
from PIL import Image
from CTkToolTip import *

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("green")


def button_produto():
    print("button produto")

def button_admin():
    print("button admin")
 
class Frame_menu_estoque(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.config_init_window()
        self.tela_menu_estoque()
    
    #configurando a janela de login
    def config_init_window(self):
        self.geometry("1000x700")
        self.title("Estoque")
        self.resizable(False,False)
    
    def tela_menu_estoque(self):

        # self.title = ctk.CTkLabel(self, text="Faça login",font=("Century Gothic bold",24))
        # self.title.grid(row=0, column=0,pady=10,padx=10)
        #importando icones dos botôes
        # img_produto=ctk.CTkImage(light_image=Image.open("img_produto.png"),
        #                           dark_image=Image.open("img_produto.png"),
        #                           size=(120, 120))
        
        # img_adm=ctk.CTkImage(light_image=Image.open("img_adm.png"),
        #                           dark_image=Image.open("img_adm.png"),
        #                           size=(120, 120))
        #criandos campos Entry
        self.pesquisa_entry = ctk.CTkEntry(self, width=300, placeholder_text="product_name..."
                                        ,font=("Century Gothic bold",15),corner_radius=15,border_color="green")
        self.pesquisa_entry.grid(row=0,column=0)
        #criando os botoes
        self.buttom_list = ctk.CTkButton(self,corner_radius=12, text=None,font=("Abril Fatface",15),command=button_produto)
        self.buttom_list.grid(row=0, column=1)

        self.buttom_delete = ctk.CTkButton(self,corner_radius=12, text=None,command=button_admin)
        self.buttom_delete.grid(row=1, column=0)

        self.buttom_edit = ctk.CTkButton(self,corner_radius=12, text=None,command=button_admin)
        self.buttom_edit.grid(row=1, column=1)

        self.buttom_show = ctk.CTkButton(self,corner_radius=12, text=None,command=button_admin)
        self.buttom_show.grid(row=1, column=2)

        #adicionando balão de texto aos botôes
        tooltip_delete_produto = CTkToolTip(self.buttom_delete, delay=0.2, message="deletar")
        tooltip_edit_produto = CTkToolTip(self.buttom_edit, delay=0.2, message="editar")
        tooltip_show_produto = CTkToolTip(self.buttom_show, delay=0.2, message="mostrar")
        tooltip_list_produto = CTkToolTip(self.buttom_list, delay=0.2, message="listar")


        # self.frame_login = ctk.CTkFrame(self,width=350, height=380,corner_radius=15)
        # self.frame_login.place(x=350, y=80)

        #criando widgets
        # self.lb_title = ctk.CTkLabel(self.frame_login, text="Faça o Login", font=("Century Gothic bold",22))
        # self.lb_title.grid(row=0, column=0, padx=10,pady=10)

        # #criandos campos Entry
        # self.login_entry = ctk.CTkEntry(self.frame_login, width=300, placeholder_text="Seu usuario"
        #                                 ,font=("Century Gothic bold",15),corner_radius=15,border_color="green")
        # self.login_entry.grid(row=1, column=0, padx=10,pady=10)

        # self.password_entry = ctk.CTkEntry(self.frame_login, width=300, placeholder_text="Sua senha"
        #                                    ,font=("Abril Fatface",15),show="*",corner_radius=15,border_color="green")
        # self.password_entry.grid(row=2, column=0, padx=10,pady=10)

        # self.view_password = ctk.CTkCheckBox(self.frame_login, text="Mostar senha",font=("Abril Fatface",15),corner_radius=15)
        # self.view_password.grid(row=3, column=0, padx=10,pady=10)

        #self.buttom_login = ctk.CTkButton(self.frame_login,width=300,text="Login".upper(),font=("Abril Fatface",15),corner_radius=15,command=button_login)
        #self.buttom_login.grid(row=4, column=0, padx=10,pady=10)
