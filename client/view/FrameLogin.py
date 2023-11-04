# import customtkinter
# pad = 10
# customtkinter.set_appearance_mode("dark")
# customtkinter.set_default_color_theme("green")
# frame_login = customtkinter.CTk()
# frame_login.geometry("400x250")
# frame_login.resizable(width=False,height=False)
# # frame_login.maxsize(width=400,height=250)
# # frame_login.minsize(width=400,height=250)
# frame_login.title("LOGIN")

# def button_login_click():
#     print("teste do botão login")

# login = customtkinter.CTkEntry(frame_login,placeholder_text="Seu login")
# login.place(x=125, y = 50)

# password = customtkinter.CTkEntry(frame_login,placeholder_text="Sua senha",show="*")
# password.place(x=125, y = 90)

# login_remember = customtkinter.CTkCheckBox(frame_login,text="lembrar login")
# login_remember.place(x=140, y = 130)

# button_login = customtkinter.CTkButton(frame_login,text="Login",command=button_login_click)
# button_login.place(x=125, y = 180)

# frame_login.mainloop()
from client.view.mainaux import button_login

import customtkinter as ctk
from PIL import Image
ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("green")

class Frame_login(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.config_init_window()
        self.tela_login()

    #configurando a janela de login
    def config_init_window(self):
        self.geometry("700x400")
        self.title("LOGIN")
        self.resizable(False,False)
    
    def tela_login(self):
        #inserindo imagem/logo
        self.img = ctk.CTkImage(light_image=Image.open("logo6.png"),
                                  dark_image=Image.open("logo6.png"),
                                  size=(320, 400))
        self.lb_img = ctk.CTkLabel(self, text=None, image=self.img)
        self.lb_img.grid(row=1,column=0, padx=10)

        #inserindo titulo
        # self.title = ctk.CTkLabel(self, text="Faça login",font=("Century Gothic bold",24))
        # self.title.grid(row=0, column=0,pady=10,padx=10)

        #criando frame login
        self.frame_login = ctk.CTkFrame(self,width=350, height=380,corner_radius=15)
        self.frame_login.place(x=350, y=80)

        #criando widgets
        self.lb_title = ctk.CTkLabel(self.frame_login, text="Faça o Login", font=("Century Gothic bold",22))
        self.lb_title.grid(row=0, column=0, padx=10,pady=10)

        #criandos campos Entry
        self.login_entry = ctk.CTkEntry(self.frame_login, width=300, placeholder_text="Seu usuario"
                                        ,font=("Century Gothic bold",15),corner_radius=15,border_color="green")
        self.login_entry.grid(row=1, column=0, padx=10,pady=10)

        self.password_entry = ctk.CTkEntry(self.frame_login, width=300, placeholder_text="Sua senha"
                                           ,font=("Abril Fatface",15),show="*",corner_radius=15,border_color="green")
        self.password_entry.grid(row=2, column=0, padx=10,pady=10)

        self.view_password = ctk.CTkCheckBox(self.frame_login, text="Mostar senha",font=("Abril Fatface",15),corner_radius=15)
        self.view_password.grid(row=3, column=0, padx=10,pady=10)

        self.buttom_login = ctk.CTkButton(self.frame_login,width=300,text="Login".upper(),font=("Abril Fatface",15),corner_radius=15,command=button_login)
        self.buttom_login.grid(row=4, column=0, padx=10,pady=10)

