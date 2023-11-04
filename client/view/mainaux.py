import tkinter as tk
from login import Login
from dashboard import Dashboard

class MainApp:
    def __init__(self, root):
        self.root = root
        self.login = None
        self.dashboard = None

        self.show_login()

    def show_login(self):
        if self.dashboard:
            self.dashboard.frame.destroy()
        if self.login:
            self.login.frame.destroy()
        self.login = Login(self.root)
        self.login.set_dashboard_callback(self.show_dashboard)

    def show_dashboard(self):
        if self.login:
            self.login.frame.destroy()
        self.dashboard = Dashboard(self.root, self.show_estoque, self.show_admin)

    def show_estoque(self):
        # Implemente a lógica para exibir a tela de Estoque aqui
        pass

    def show_admin(self):
        # Implemente a lógica para exibir a tela de Administrador aqui
        pass

if __name__ == "__main__":
    root = tk.Tk()
    app = MainApp(root)
    root.mainloop()
