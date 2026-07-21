# Entadas de dados estaticas
nome = 'João'
idade = 30

# Entradas de dados dinamicas
peso = float(input('Digite o peso: '))
altura = float(input('Digite a altura: '))

# calculo do IMC
imc = peso / (altura ** 2)

# Saida dos dados
print(f'Nome: {nome}')
print(f'Idade: {idade}')
print(f'Peso: {peso}kg')
print(f'Altura: {altura}m')
print(f'IMC: {imc}')

# Saida formatada
print(f'O {nome} tem {idade} anos, pesa {peso:.1f}kg e tem uma altura {altura:.2f}m. A sua massa corporal(IMC) é de {imc:.2f}!')