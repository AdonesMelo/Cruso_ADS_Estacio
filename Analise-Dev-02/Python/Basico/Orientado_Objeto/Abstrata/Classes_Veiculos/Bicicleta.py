from .Veiculo import Veiculo

# Subclasse Carro
class Bicicleta(Veiculo):
    def mover(self):
        return 'A bicicleta está se movendo.'
    
    def ligar(self):
        return 'A bicicleta não pode ser ligada.'