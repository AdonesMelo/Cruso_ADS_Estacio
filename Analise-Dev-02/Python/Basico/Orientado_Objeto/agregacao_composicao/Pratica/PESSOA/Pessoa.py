'''
Criar uma classe Pessoa que recebe parâmetro para o construtor.

A classe Pessoa dever ter
Nome;
Idade;
Método de classe para receber o ano de nascimento;
Nome da pessoa e calcular sua idade;
Método estático que informe se a pessoa é maior ou menor de idade.
'''
from datetime import date

class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade
    
    # metodo de classe para criar
    # um objeto pessoa apartir do ano de nascimento
    @classmethod
    def dt_nasc(cls, nome, ano):
        return cls(nome, date.today().year - ano)
    
    # metodo estatico para verificar se é maior de idade
    @staticmethod
    def maior_idade(idade):
        return idade >= 18