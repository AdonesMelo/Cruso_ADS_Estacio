'''
Modifique a classe Televisão criada a partir do roteiro de prática de forma que, 
se pedirmos para mudar o canal para baixo, além do mínimo, 
ela vá para o canal máximo. Se mudarmos para cima, além do canal máximo, que volte ao canal mínimo.
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
        if self.canal  - 1 >= self.c_min:
            self.canal -= 1
        else:
            self.canal = self.c_max

    def canal_para_cima(self):
        if self.canal + 1 <= self.c_max:
            self.canal += 1
        else:
            self.canal = self.c_min

def main():
    print()
    tv_1 = Televisao(9, 2, 10)
    print(tv_1.canal)
    for x in range(1, 5):
        tv_1.canal_para_cima()
        print(tv_1.canal)

    print()
    tv_2 = Televisao(3, 2, 10)
    print(tv_2.canal)
    for x in range(1, 5):
        tv_2.canal_para_baixo()
        print(tv_2.canal)

if __name__ == '__main__':
    main()