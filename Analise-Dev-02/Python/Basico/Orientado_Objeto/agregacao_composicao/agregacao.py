from Conta import Conta
from Cliente import Cliente


cliente_1 = Cliente(123, 'João', 'Rua 1')
cliente_2 = Cliente(456, 'Maria', 'Rua 2')

# criando um conta com  dois clientes , fazendo uma agregação com a lista
conta_1 = Conta([cliente_1, cliente_2], 1, 0)

conta_1.gerar_saldo()
conta_1.depositar(1500)
conta_1.sacar(500)
conta_1.gerar_saldo()