import tkinter as tk
import socket
from tkinter import PhotoImage
from dashboard import Dashboard
from PIL import Image, ImageTk
from classes import CheckLogin

class Login:
    def __init__(self, root):
        self.root = root
        self.frame = tk.Frame(root)
        self.frame.pack()

        # Carrega e exibe uma imagem
        image = Image.open("logo6.png")
        photo = ImageTk.PhotoImage(image)

        image_label = tk.Label(self.frame, image=photo)
        image_label.image = photo
        image_label.pack()

        login_frame = tk.Frame(self.frame)
        login_frame.pack()

        self.label = tk.Label(login_frame, text="Login")
        self.label.pack()

        self.username_label = tk.Label(login_frame, text="Username:")
        self.username_label.pack()

        self.username_entry = tk.Entry(login_frame)
        self.username_entry.pack()

        self.password_label = tk.Label(login_frame, text="Password:")
        self.password_label.pack()

        self.password_entry = tk.Entry(login_frame, show="*")
        self.password_entry.pack()

        self.login_button = tk.Button(login_frame, text="Login", command=self.login)
        self.login_button.pack()

        self.error_label = tk.Label(login_frame, text="", fg="red")
        self.error_label.pack()

    def set_dashboard_callback(self, callback):
        self.show_dashboard = callback

    def login(self):
        username = self.username_entry.get()
        password = self.password_entry.get()
        checkLogin = CheckLogin(username,password)
        a = checkLogin.tojson()
        HOST='127.0.0.1'
        PORT= 5000
        dirt = (HOST, PORT)
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
            s.sendto(a.encode(),dirt)



        if username == "user" and password == "password":
            self.frame.destroy()
            self.show_dashboard()
        else:
            self.error_label.config(text="Login failed. Try again.")
