def diz_ola():
    print('Olá, mundo!')

diz_ola()

print('\n')

escolha = input('Digite uma opção de função 1 ou 2: ')

if escolha == '1':
    def fun_1(x):
        return x + 1
    
    opcao = fun_1(10)

else:
    def func_2(x):
        return x + 2
    
    opcao = func_2(10)

print(opcao)

