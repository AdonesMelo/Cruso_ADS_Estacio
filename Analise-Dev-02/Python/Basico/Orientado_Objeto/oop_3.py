# Metodos e Classes
# Definir as ações que o objeto pode realizar
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
        self.saldo -= valor

    # terceiro metodo
    def gerar_extrato(self):
        print(f'\n O número da conta: {self.numero} \n O CPF do titular da conta: {self.cpf} \n O nome do Titular: {self.nomeTitular} \n O saldo da conta: {self.saldo} \n')


def main():
    cliente_1 = Conta(1, 12345678910, 'João', 0)
    cliente_1.depositar(300) # chamando o metodo depositar
    cliente_1.gerar_extrato() # chamando o metodo gera extrato para o cliente
    cliente_1. sacar(100) # chamando o metodo sacar
    cliente_1.gerar_extrato() # chamando o metodo gera extrato para o cliente

if __name__ == '__main__':
    main()