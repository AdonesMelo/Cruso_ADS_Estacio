# Entrada usuario das notas
n1 = float(input('Digite sua primeira nota: '))
n2 = float(input('Digite sua segunda nota: '))
n3 = float(input('Digite sua treceira nota: '))
n4 = float(input('Digite sua quarta nota: '))

# lista de notas
notas = [n1, n2, n3, n4]

def calcular_media(notas):
    media = sum(notas) / len(notas)
    
    return media

# Calcula e mostra o resultado
resultado = calcular_media(notas)
print(f'A media do aluno: {resultado}')