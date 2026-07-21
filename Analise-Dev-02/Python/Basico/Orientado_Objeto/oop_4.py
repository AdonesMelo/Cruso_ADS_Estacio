# Metodo com retorno
# Serve para valida o estado do objeto
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

def main():
    cliente_1 = Conta(1, 12345678910, 'João', 1000)
    cliente_1_saque = 200
    cliente_1_extrato = cliente_1.sacar(cliente_1_saque)
    
    # Validar o retorno para verificar se o saque foi realizado
    if cliente_1_extrato:
        print(f'Saque de R$ {cliente_1_saque:,.2f} realisado com sucesso!')
        print(f'Saldo atual: R$ {cliente_1.saldo:,.2f}')
    else:
        print('Saldo insuficiente.')

if __name__ == '__main__':
    main()