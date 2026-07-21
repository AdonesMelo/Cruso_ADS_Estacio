# criar função de soma
def soma_numericas(a, b):
    try:
        resultado = a + b
        return resultado
    
    except TypeError:
        print('Erro: Entrada inválida')
    except Exception as e:
        print(f'Erro inesperado: {e}')
    return None

# Números válidos
print(soma_numericas(5, 2))

# Números inválidos
print(soma_numericas('a', 2))

# Outro tipo de dados
print(soma_numericas(True, 2))

# Outro tipo de dados
print(soma_numericas(False, 2))

# Com uma lista
print(soma_numericas([5, 1], 2))
