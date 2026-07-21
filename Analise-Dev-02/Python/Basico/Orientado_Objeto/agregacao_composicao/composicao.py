from Cliente import Cliente
from ContaClienteExtrato import Conta
# Realizar a composição

cliente_1 = Cliente(123, 'João', 'Rua 1')
cliente_2 = Cliente(456, 'Maria', 'Rua 2')

# criando um conta com  dois clientes , fazendo uma agregação com a lista
conta_1 = Conta([cliente_1, cliente_2], 1, 2000)

conta_1.depositar(1000)
conta_1.sacar(1500)
conta_1.extrato.extrato(conta_1.numero)