'''
A solução apresentada inicialmente no vídeo prático é eficaz, mas não é a mais eficiente, já que ela testa todos os números entre 1000 e 9999.

Foi observado no vídeo uma característica especial, que é o fato de a raiz ser obrigatoriamente um número inteiro, já que ela irá resultar da soma de dois números inteiros.

A otimização demonstrada no vídeo foi diminuir o loop para testar apenas as raízes inteiras de 32 a 99, que geram números entre 1000 e 9999.

O valor 32 representa o menor número que tem uma raiz inteira e cujo quadrado está no intervalo de 1000 a 9999. Já o valor 99 representa o maior número que tem uma raiz inteira e cujo quadrado está no intervalo citado.

Altere então o programa apresentado inicialmente no vídeo prático, de modo que os valores 32 e 99 da otimização possam ser obtidos de maneira automática, sem nenhum cálculo anterior à execução do programa.
'''
start = int(1000**0.5) # Aproximação da raiz quadrada de 1000

if start * start < 1000: 
	start += 1 # Ajusta para garantir que o quadrado seja pelo menos 1000 

end = int(9999**0.5) # Aproximação da raiz quadrada de 9999 

for raiz in range (start, end + 1): 
	num = raiz * raiz  #calcula o numero gerado pela raiz
	menor = num % 100  #obtem o numero dos algarismos menos significativos
	maior = num // 100  #obtem o numero dos algarismos mais significativos
 
	if (menor +maior) ==raiz:  #valida se a raiz corresponde a soma
		print(num)
		print(menor)
		print(maior)
		print(raiz)
print('terminou')
print('saiu ', raiz) 
