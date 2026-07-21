from .Veiculo import Veiculo

# Subclasse Carro
class Aviao(Veiculo):
    def mover(self):
        return 'O avião está se movendo.'
    
    def ligar(self):
        return 'O avião está ligado.'