def maior_elemento_recursivo(lista):
    # se a lista tiver apenas um elemento, ele é o maior
    if len(lista) == 1:
        return lista[0]
    
    # Chama recursivamente a função para o restante da lista
    maior_restante = maior_elemento_recursivo(lista[1:])
    
    # Compara o primeiro elemento com o maior do restante
    if lista[0] > maior_restante:
        return lista[0]
    else:
        return maior_restante

lista_num = [88, 90, 20, 22, 26]

resultado = maior_elemento_recursivo(lista_num)
print(f'O maior número é: {resultado}')
