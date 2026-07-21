import math

def calcular_raiz(x):
    resultado = math.sqrt(x)

    return resultado

numero = eval(input('Digite uma número: '))
resultado = calcular_raiz(numero)
print(f'A raiz quadrada de {numero} é {resultado}')