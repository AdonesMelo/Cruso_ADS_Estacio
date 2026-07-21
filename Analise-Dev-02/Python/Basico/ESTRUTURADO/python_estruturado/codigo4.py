nomes = ['Laura', 'Lis', 'Guilherme', 'Enzo', 'Arthur', 'Adones']
for nome in nomes:
    print(nome)

print('\n')
numeros = [0, 1, 2 , 3, 4, 5, 6, 7, 8, 9]
for numero in numeros:
    quadrado = numero ** 2
    print(f'O quadrado de {numero} = {quadrado}')

print('\n')
numeros = [0, 1, 2 , 3, 4, 5, 6, 7, 8, 9]
soma = 0
for numero in numeros:
    soma += numero

print(f'A soma de todos números é {soma}')

print('\n')
texto ='Programação'
contar_letra = 'r'

contador = 0

for letra in texto:
    if letra == contar_letra:
        contador += 1

print(f'Na palavra {texto} contem {contador} "{contar_letra}"!')

