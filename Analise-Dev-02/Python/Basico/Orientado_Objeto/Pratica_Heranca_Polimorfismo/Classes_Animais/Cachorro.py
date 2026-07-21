from .Animal import Animal
class Cachorro(Animal):
    def falar(self):
        return f'{self.nome}, Auau'
    
    def mover(self):
        return f'{self.nome} está andando.'