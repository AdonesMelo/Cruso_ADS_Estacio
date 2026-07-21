'''
Você foi designado para criar um programa em Python para um caixa de supermercado. O programa deve solicitar ao cliente a quantidade de cada produto adquirido e calcular o total da compra com base nos preços unitários dos itens. Utilize os conceitos de atribuição, entrada e saída de dados para implementar o programa.
'''
produto = input('Digite o nome do produto: ').upper()
qtd_produto = int(input('Digite a quantidade do produto: '))
preco_produto = float(input('Digite o preco do produto: '))

total_compras = qtd_produto * preco_produto
print('\n')
print('############ CAIXA SUPERMERCADO ###########')
print(f'Produto: {produto}')
print(f'Quantidades: {qtd_produto} un.')
print(f'Total da compra: R$ {total_compras:,.2f}')