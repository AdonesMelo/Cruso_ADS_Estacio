from Conta import Conta
from Poupanca import Poupanca

class ContaRemuneradaPoupanca(Conta, Poupanca):
    def __init__(self, taxa_remuneracao, clientes, numero, saldo):
        Conta.__init__(self, clientes, numero, saldo) # herdando da classe "Conta"
        Poupanca.__init__(self, taxa_remuneracao) # herdando da classe "Poupanca"

   
    def remuneraConta(self):
        self.saldo += self.saldo * (self.taxaremuneracaoMes / 30)  # Diferente da "Poupanca" aqui o rendimento é diario, por é dividido por 30