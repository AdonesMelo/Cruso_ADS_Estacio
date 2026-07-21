'''
Elabore um programa em Python para criar uma função simples em Python que recebe dois argumentos – um número e uma string – e imprime esses valores, destacando o conceito de binding.
'''
# função que imprimer o nome e ano que o time foi campeão
def campeao(time, ano):
    print(f'O {time} foi campeão em {ano}.')

# dados fornecidos
nome_time = 'Fluminense'
ano_titulo = '2023'

# chamada da função com as variaveis com os dados fornecidos
campeao(nome_time, ano_titulo)