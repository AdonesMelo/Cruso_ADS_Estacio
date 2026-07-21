from .Animal import Animal
from .Nadador import Nadador
class Jacare(Animal, Nadador):
    def falar(self):
        return f'{self.nome}, nhac '
    
    def mover(self):
        return f'{self.nome} {self.andar()} e {self.nadar()}.'
    
    def andar(self):
        return 'está andando'