# Calculo de massa corparal
def calculo_imc(peso, altura):
    resultado = peso * 100 / (altura * 2)
    return resultado

peso = eval(input('Digite o peso(kg): '))
altura = eval(input('Digite a altura(cm): '))

imc = calculo_imc(peso, altura)
print(f'IMC = {imc:.2f}')