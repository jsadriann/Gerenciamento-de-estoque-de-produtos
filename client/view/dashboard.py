import tkinter as tk

class Dashboard:
    def __init__(self, root, show_estoque, show_admin):
        self.root = root
        self.show_estoque = show_estoque
        self.show_admin = show_admin

        self.frame = tk.Frame(root)
        self.frame.pack()

        # Botão para a tela de estoque
        estoque_button = tk.Button(self.frame, text="Estoque", command=self.show_estoque, height=5, width=15)
        estoque_button.pack(side=tk.LEFT, padx=10)

        # Botão para a tela de administrador
        admin_button = tk.Button(self.frame, text="Admin", command=self.show_admin, height=5, width=15)
        admin_button.pack(side=tk.RIGHT, padx=10)
