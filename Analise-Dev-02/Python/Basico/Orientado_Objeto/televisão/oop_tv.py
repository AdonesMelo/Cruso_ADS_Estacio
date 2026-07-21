'''
Crie a classe Televisão.
Crie o método construtor.
Estabeleça os parâmetros do método construtor.
Crie os atributos canal, canal mínimo e canal máximo.
Defina os métodos para ir para o canal superior e para o canal inferior.
Crie dois objetos de televisão e teste a subida e a descida dos canais.
'''
# Crie a classe Televisão.
class Televisao:
    # Crie o método construtor
    # Estabeleça os parâmetros do método construtor.
    # Crie os atributos canal, canal mínimo e canal máximo.
    def __init__(self, pcanal, max, min):
        self.canal = pcanal
        self.c_max = max
        self.c_min = min
    
    # Defina os métodos para ir para o canal superior e para o canal inferior.
    def canal_para_baixo(self):
        self.canal -= 1
        

    def canal_para_cima(self):
        self.canal += 1

# Crie dois objetos de televisão e teste a subida e a descida dos canais.
# chamada está no arquivo main.py