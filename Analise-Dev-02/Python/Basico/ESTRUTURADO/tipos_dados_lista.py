# Criando uma lista
lista = [10, 20, 30, 40, 50]

# acessando os elementos individuais da lista
primeiro_elemento = lista[0]
sengundo_elemento = lista[1]

# Imprimindo os elementos acessandos
print(f'O primeiro elemento da lista é: {primeiro_elemento}')
print(f'O sengundo elemento da lista é: {sengundo_elemento}')

# Adicionando um elemento ao final da lista
numero = 60
lista.append(numero)
print(f'Imprimir a lista apos adicionado o numero "{numero}": {lista}')

# inserindo um elemento na lista em uma posição especifica
lista.insert(2, 25) # index e object
print(f'Lista apos o inserir o numero 25: {lista}')

# remover  um elemento de uma lista
numero = 40
lista.remove(numero) # remove o primeiro valor encontrado com o numero
print(f'Lista após remover "{numero}": {lista}')

# removendo o ultimo elemento da lista
ultimo_elemento = lista.pop()
print(f'Elemento removido: {ultimo_elemento}')
print(f'Lista após o ultimo elemento removido: {lista}')

# acessando um subgrupo da lista(fatiamento)
sub_lista = lista[1:4]
print(f'Sub_lista(elemento de indice 1 a 3): {sub_lista}')

# ordenando a lista
lista.sort()
print(f'Lista ordenada: {lista}')

# iterando sobre os elementos da lista
print('Interando sobre a lista:')
for numero in lista:
    print(numero)