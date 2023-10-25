import customtkinter
pad = 10
customtkinter.set_appearance_mode("dark")
customtkinter.set_default_color_theme("green")
frame_login = customtkinter.CTk()
frame_login.geometry("400x250")

def button_login_click():
    print("teste do botão login")

texto = customtkinter.CTkLabel(frame_login,text="Login")
texto.pack(padx=pad, pady=pad)

login = customtkinter.CTkEntry(frame_login,placeholder_text="Seu login")
login.pack(padx=pad, pady=pad)

password = customtkinter.CTkEntry(frame_login,placeholder_text="Sua senha",show="*")
password.pack(padx=pad, pady=pad)

login_remember = customtkinter.CTkCheckBox(frame_login,)

button_login = customtkinter.CTkButton(frame_login,text="Login",command=button_login_click)
button_login.pack(padx=pad, pady=pad)
frame_login.mainloop()