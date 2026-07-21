from abc import ABC, abstractmethod

# Classe abstrata veiculo
class Veiculo(ABC):

    @abstractmethod
    def mover(self):
        pass

    @abstractmethod
    def ligar(self):
        pass