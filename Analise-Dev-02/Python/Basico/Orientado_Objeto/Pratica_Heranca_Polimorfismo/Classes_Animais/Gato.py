from .Animal import Animal
class Gato(Animal):
    def falar(self):
        return f'{self.nome}, Miau'
    
    def mover(self):
        return f'{self.nome} está andando.'