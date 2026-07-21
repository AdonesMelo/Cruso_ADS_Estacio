class Conta:
    def __init__(self, numero):
        self.numero = numero
        self._saldo = 0
        
    @property
    def saldo(self):
        return self._saldo
    
    @saldo.setter
    def saldo(self, saldo):
        if saldo < 0:
            print ("saldo inválido")
        else:
            self._saldo = saldo