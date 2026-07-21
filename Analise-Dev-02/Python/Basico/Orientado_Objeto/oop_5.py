# Comunicação entre objetos na memoria
# Uma classe pode ter varias intancias (objetos) na memoria, cada uma com seus proprios valores e atributos.
# Para comparar se duas referencias  de memoria  apontam para o memso objeto, usamos os operadores "==" e "!="
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
    cliente_1 = Conta(1, 12345678910, 'João', 0)
    cliente_2 = Conta(2, 11987654321, 'Maria', 0)
    
    if (cliente_1 != cliente_2):
        print('Endereço de memória diferentes!')
    
    print(cliente_1)
    print(cliente_2)

    print(cliente_1.saldo)
    print(cliente_2.saldo)
    cliente_1.depositar(300)
    print(cliente_1.saldo)
    print(cliente_2.saldo)

    cliente_1 = cliente_2

    if (cliente_1 == cliente_2):
        print('Endeços iguais na memória!')
    
    print(cliente_1)
    print(cliente_2)

    print(cliente_1.saldo)
    print(cliente_2.saldo)
    cliente_1.depositar(1000)
    print(cliente_1.saldo)
    print(cliente_2.saldo)

if __name__ == '__main__':
    main()