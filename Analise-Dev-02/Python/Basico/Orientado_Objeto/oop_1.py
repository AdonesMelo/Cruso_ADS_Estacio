# Criando uma classe
# Construtores e Metodos init e self
# self é uma forma da classe referir a ela mesma
# __init__ é o metodo construtor que criar o objeto da classe
class Conta:
    def __init__(self, numero, cpf, nomeTitular, salario):
        self.numero = numero
        self.cpf = cpf
        self.nomeTitular = nomeTitular
        self.salario = salario

# instancia  um objeto Conta
# observe os parametro passados na criação do objeto
def main():
    cliente_1 = Conta(1, 12345678910, 'João', 1000)
    print(f'O número da conta: {cliente_1.numero}')
    print(f'O nome do titular: {cliente_1.nomeTitular}')
    print(f'O CPF do titular: {cliente_1.cpf}')
    print(f'O saldo da conta: {cliente_1.salario}')

if __name__ == '__main__':
    main()