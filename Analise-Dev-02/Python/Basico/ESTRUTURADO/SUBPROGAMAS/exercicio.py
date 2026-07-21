# Escreva uma função que busca de forma iterativa o maior elemento em uma lista de números inteiros.
lista_num = [88, 90, 20, 22, 26]

def maior_elemento(lista):
    # Verifica se a lista está vazia
    if not lista:
        return None
    
    maior = lista[0] # começa com o primeiro elemento

    for elemento in lista:
        if elemento > maior:
            maior = elemento

    return maior


resultado = maior_elemento(lista_num)
print(f'O maior numero é: {resultado}')