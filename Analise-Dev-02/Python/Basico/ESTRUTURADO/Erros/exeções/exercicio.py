'''
Analise o programa. Se em vez de um número, for digitada uma letra, 
o programa gerará uma exceção e irá abortar a execução.

Altere o programa de forma a obrigar que o usuário digite somente números na caixa de entrada.
'''

import tkinter as tk
from tkinter import messagebox
 
def comp_numeros():
 
    try:
        num1=float(entry_num1.get())
        num2 = float(entry_num2.get())
        if num1 > num2 :
            messagebox.showinfo("Resultado", f"O numero {num1} é maior que {num2}")
        elif num1 == num2 :
            messagebox.showinfo("Resultado", f"O numero {num1} é  igual a {num2}")
        else:
            messagebox.showinfo("Resultado", f"O numero {num1} é menor que {num2}")
    except ValueError:
        messagebox.showerror("Erro", "Por favor, insira números válidos.")

def apenas_numeros(texto):
    # Retorna True se o texto for vazio ou apenas dígitos
    return texto.isdigit() or texto == ""
 
# Criando a janela
janela=tk.Tk()
janela.title("Comparando Numeros")

# Registrando a função de validação
validacao = janela.register(apenas_numeros)
 
# Criando os widgets
label_num1=tk.Label(janela, text="Número 1:")
label_num1.grid(row=0, column=0, padx=10, pady=5, sticky="e")
 
entry_num1=tk.Entry(janela, validate='key', validatecommand=(validacao, '%P'))
entry_num1.grid(row=0, column=1, padx=10, pady=5)
 
label_num2=tk.Label(janela, text="Número 2:")
label_num2.grid(row=1, column=0, padx=10, pady=5, sticky="e")
 
entry_num2=tk.Entry(janela, validate='key', validatecommand=(validacao, '%P'))
entry_num2.grid(row=1, column=1, padx=10, pady=5)
 
botao_comp=tk.Button(janela, text="Comparar", command=comp_numeros)
botao_comp.grid(row=2, columnspan=2, padx=10, pady=5)
 
# Rodando o loop principal
janela.mainloop()