numero_int = int(input('Digite um número inteiro: '))
print(type(numero_int))

numero_flutuante = float(input('Digite um número de ponto flutuante: '))
print(type(numero_flutuante))

numero_booleano = bool(input('Digite um valor booleano (True ou False): ').lower())
numero_booleano = numero_booleano == True
print(type(numero_booleano))

print('\nValores convertidos:')
print(f'- Número inteiro: {numero_int} (tipo: {type(numero_int).__name__})')
print(f'- Número de ponto flutuante: {numero_flutuante} (tipo: {type(numero_flutuante).__name__})')
print(f'- Valor booleano: {numero_booleano} (tipo: {type(numero_booleano).__name__})')

