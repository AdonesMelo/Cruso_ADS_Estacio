'''
Faça um programa em Python que mostre os números entre 1000 e 9999 cuja raiz quadrada seja igual à soma dos números formados pelos dois algarismos menos significativos e pelos dois algarismos mais significativos. Dica: existem três números que atendem a condição.

- Crie um projeto
- Utilize uma estrutura de for para gerar os números a serem testados.
- Gere o número formado pelos algarismos menos significativos.
- Gere o número formado pelos algarismos mais significativos.
- Obtenha a raiz somando os dois números obtidos.
- Eleve a raiz ao quadrado e valide se é igual ao número que está sendo testado.
- Se for igual, exiba o número que está sendo testado, os números dos algarismos mais e menos significativos e a raiz.
- Ao término do loop, informe que terminou e mostre o valor final da variável do for.
'''

for num in range (100,10000):
    menor = num % 100 #obtem o numero dos algarismos menos significativos
    maior = num // 100 #obtem o numero dos algarismos mais significativos
    raiz = menor + maior  #obtem a raiz

    if (raiz * raiz ) == num: #valida se a raiz gera o numero testado
        print(num)
        print(menor)
        print(maior)
        print(raiz)
print('terminou')
print('saiu ', num)

print('##################')
# outa forma
for raiz in range(32, 100):
    num = raiz * raiz
    maior = num // 100
    menor = num % 100

    if (maior + menor) == raiz:
        print(num)
        print(maior)
        print(menor)
        print(raiz)

print('Terminou')
print(f'Saiu {raiz}')