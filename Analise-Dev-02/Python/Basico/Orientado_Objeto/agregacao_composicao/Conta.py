class Conta:
    def __init__(self, clientes, numero, saldo):
        self.clientes = clientes
        self.numero = numero
        self.saldo = saldo

    def depositar(self, valor):
        self.saldo += valor
    
    def sacar(self, valor):
        if self.saldo < valor: # Validação se existe saldo ou não
            return False
        else:
            self.saldo -= valor
            return True
    
    def transferir_valor(self, conta_destino, valor):
        if self.saldo < valor:
            return('Saldo insuficiente!')
        else:
            conta_destino.depositar(valor)
            self.saldo -= valor
            return('Transferencia realizada!')
        
    def gerar_saldo(self):
        print(f'\nNúmero da Conta: {self.numero} \nSaldo: {self.saldo}\n')