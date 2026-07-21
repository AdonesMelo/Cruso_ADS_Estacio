# Transferencia entre contas
# Criar um metodo para transferencias de valores
class Conta:
    def __init__(self, numero, cpf, nomeTitular, saldo):
        self.numero = numero
        self.cpf = cpf
        self.nomeTitular = nomeTitular
        self.saldo = saldo

    # Primeiro metodo
    def depositar(self, valor):
        self.saldo += valor
    
    # segundo metodo
    def sacar(self, valor):
        if self.saldo < valor: # Validação se existe saldo ou não
            return False
        else:
            self.saldo -= valor
            return True

    # terceiro metodo
    def gerar_extrato(self):
        print(f'\n O número da conta: {self.numero} \n O CPF do titular da conta: {self.cpf} \n O nome do Titular: {self.nomeTitular} \n O saldo da conta: {self.saldo} \n')
    
    def transferir_valor(self, conta_destino, valor):
        if self.saldo < valor:
            return('Saldo insuficiente!')
        else:
            conta_destino.depositar(valor)
            self.saldo -= valor
            return('Transferencia realizada!')
        
def main():
    cliente_1 = Conta(1, 12345678910, 'João', 1000)
    cliente_2 = Conta(2, 11987654321, 'Maria', 500)

    print('\nSaldo antes da transferência')
    print(f'Saldo do cliente 1: {cliente_1.saldo}')
    print(f'Saldo do cliente 2: {cliente_2.saldo}')

    print('\nSaldo depois da transferência')
    cliente_1.transferir_valor(cliente_2, 300)
    print(f'Saldo do cliente 1: {cliente_1.saldo}')
    print(f'Saldo do cliente 2: {cliente_2.saldo}')

if __name__ == '__main__':
    main()