from .Animal import Animal
class Vaca(Animal):
    def falar(self):
        return f'{self.nome}, Muu'
    
    def mover(self):
        return f'{self.nome} está andando.'