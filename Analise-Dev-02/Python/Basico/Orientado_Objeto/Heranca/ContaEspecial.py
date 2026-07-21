from Conta import Conta
import datetime

# "ContaEspecail" é filha da classe "Conta" 
class ContaEspecial(Conta):
    def __init__(self, clientes, numero, saldo, limite):
        super().__init__(clientes, numero, saldo) # Vai herdar da classe Conta os atributos
        self.limite = limite # Atributo exclusivo da classe "ContaEspecail"

    # O metoto "sacar" é proprio da classe "ContaEspecail"
    # É um metodo polimorfico, fuciona diferente.
    def sacar(self, valor):
        if (self.saldo + self.limite) < valor:
            print(f"Não existe saldo suficiente conta numero {self.numero} cliente {self.clientes.cpf}")
            return False
        else:
            self.saldo -= valor
            if (self.saldo < 0):
                self.limite += self.saldo
            self.extrato.transacoes.append(["SAQUE", valor, datetime.datetime.today()])
            return True
    
    # metodo depositar precisa ser reescrito para "ContaEspecial"
    def depositar(self, valor):
        pass