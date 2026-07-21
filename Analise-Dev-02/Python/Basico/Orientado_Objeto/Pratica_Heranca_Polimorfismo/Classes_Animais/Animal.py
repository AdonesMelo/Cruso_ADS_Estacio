class Animal:
    def __init__(self, nome):
        self.nome = nome

    def falar(self):
        pass
    def mover(self):
        pass

# Função que usa polimorfismo para chamar o método falar
def fazer_som(animal):
    return animal.falar()

# Função que usa polimorfismo para chamar o método mover
def fazer_movimento(animal):
    return animal.mover()