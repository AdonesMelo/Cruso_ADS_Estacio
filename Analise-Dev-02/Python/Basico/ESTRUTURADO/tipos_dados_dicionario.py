# criando um dicionario com alguns pares de chave-valor
dicionario = {
    'nome': 'Alice',
    'idade': 25,
    'cidade': 'São Paulo'
}

# acessando e imprimindo valores individuais usando as chaves
nome = dicionario['nome']
idade = dicionario['idade']
cidade = dicionario['cidade']

print(f'Nome: {nome}')
print(f'Idade: {idade}')
print(f'Cidade: {cidade}')

# adicionado o novo par de chave-valor ao dicionario
dicionario['profissão'] = 'Engenheira'
print(f'Dicionário após adicionar a profissão: {dicionario}')

# modificar o valor associado a uma chave existente
dicionario['idade'] = 26
print(f'Dicionário após modificar o valor da idade: {dicionario}')

# remover um par chave-valor  do dicionario
del dicionario['cidade']
print(f'Dicionário após remover chave-valor cidade: {dicionario}')

# acessando todas chaves e valores do dicionário
chaves = dicionario.keys()
valores = dicionario.values()

print(f'Chaves: {list(chaves)}')
print(f'Valores: {list(valores)}')

# iterendo sobre os pares de chave-valor do dicionario
print('Iterendo sobre o dicionário')
for chave, valor in dicionario.items():
    print(f'{chave}: {valor}')

# verificando se uma chave existe no dicionário
if 'nome' in dicionario:
    print(f'O nome no dicionário é: {dicionario["nome"]}')
else:
    print('A chave "nome" não está no dicionário')

# usando o metodo get() para acessar valores de modo seguro
profissao = dicionario.get('profissão', 'Desconhecido')
print(f'Profissão: {profissao}')

# limpando todos elemento do dicionário
dicionario.clear()
print(f'Dicionário após limpar todos elementos: {dicionario}')