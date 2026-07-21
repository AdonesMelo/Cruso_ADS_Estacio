# criando uma string
texto = 'Olá, mundo!'

# acessado caracteres individuas
primeiro_caractere = texto[0]
ultimo_caractere = texto[-1]

print(f'Primerio caractere: {primeiro_caractere}')
print(f'Ultimo caractere: {ultimo_caractere}')

# fatiando uma string
sub_texto = texto[5:10]
print(f'Substring (indices 5 à 9): {sub_texto}')

# concatenando string
nome = 'Alice'
saudacao = 'Olá'
frase = saudacao + ', ' + nome + '!'
print(frase)

# dividindo uma string em uma lista
lista_palavra = texto.split()
print(f'Lista de palavra: {lista_palavra}')

# substituindo partes de uma string
texto_modificado = texto.replace('mundo', 'python')
print(f'Texto modificado: {texto_modificado}')

# convertendo para maiusculas e minusculas
texto_maiuscula = texto.upper()
texto_minuscula = texto.lower()

print(f'Texto em maiúsculas: {texto_maiuscula}')
print(f'Texto em minúsculas: {texto_minuscula}')

# removendo espaços em branco
texto_com_espacos = '  Olá, mundo!  '
texto_sem_espacos = texto_com_espacos.strip()
print(f'Texto com espaços extras: {texto_com_espacos}')
print(f'Texto sem espaços extras: {texto_sem_espacos}')

# verificar se a string esta presente no texto
if 'mundo' in texto:
    print(f'A palavra "mundo" está no texto.')
else:
    print('A palavra "mundo" não está no texto')

# formatação de string
idade = 30
cidade = 'São Paulo'
frase_formatada = f'Meu nome é {nome}, tenho {idade} anos e moro na cidade de {cidade}.'
print(frase_formatada)


# exercicio
frase = 'CONSIDERANDO O TEXTO, ANALISE AS ALTERNATIVAS E ASSINALE A OPÇÃO CORRETA:'
frase_1 = frase.split()
print(frase_1)