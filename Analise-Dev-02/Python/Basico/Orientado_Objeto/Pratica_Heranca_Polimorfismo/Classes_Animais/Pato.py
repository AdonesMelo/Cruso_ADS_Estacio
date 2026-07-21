from .Animal import Animal
from .Nadador import Nadador
from .Voador import Voador
class Pato(Animal, Nadador, Voador):
    def falar(self):
        return f'{self.nome}, Quá-quá '
    
    def mover(self):
        return f'{self.nome} {self.andar()}, {self.nadar()} e {self.voar()}.'
    
    def andar(self):
        return 'está andando'