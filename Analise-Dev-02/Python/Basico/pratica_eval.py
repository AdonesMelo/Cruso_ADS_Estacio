def calcular_expressao():
    # Entrada da expressão
    expressao = input('Digite uma expressão matemática: ') # ex: 2 + 3 * (4 - 1)

    try:
        # Avaliar a expressão
        resultado = eval(expressao)
        print(f'O resultado da expressão é: {resultado}')
    except Exception as e:
        print(f'Erro na expressão: {e}')

# chamada da função
calcular_expressao()