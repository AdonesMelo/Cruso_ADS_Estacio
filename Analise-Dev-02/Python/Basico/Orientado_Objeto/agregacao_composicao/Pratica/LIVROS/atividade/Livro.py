'''
Criar um sistema simples de gerenciamento de uma biblioteca que contém 
vários livros usando o conceito de agregação. Você deve criar duas classes: Livro e Biblioteca.

Siga as orientações a seguir.

A classe Livro deve ter os seguintes atributos:
título (str);
autor (str);
isbn (str).
A classe Biblioteca deve ter:
Um nome (str);
Uma lista de livros.
A classe Biblioteca deve ter métodos para:
Adicionar um livro à biblioteca;
Remover um livro da biblioteca;
Listar todos os livros na biblioteca.
'''
# A partir da solução disponibilizada para o cenário 1, adicione um método na classe Biblioteca para buscar um livro pelo título e retornar as informações do livro.
class Livro:
    def __init__(self, titulo, autor, isbn):
        self.titulo = titulo
        self.autor = autor
        self.isbn = isbn

class Biblioteca:
    def __init__(self, nome):
        self.nome = nome
        self.livros = [] # Uma lista de livros

    def add_livro(self, livro):
        self.livros.append(livro)
        print(f'O livro "{livro.titulo}" foi adicionado na biblioteca "{self.nome}".')

    def del_livro(self, isbn):
        for livro in self.livros:
            if livro.isbn == isbn:
                self.livros.remove(livro)
                print(f'\nO livro "{livro.titulo}" foi removido da biblioteca "{self.nome}".')
                return
        print(f'O livro com ISBN {isbn} não encontrado na biblioteca "{self.nome}".')

    def listar_livros(self):
        if not self.livros:
            print(f'A biblioteca "{self.nome}" não tem livros.')
        else:
            print(f'\nLivros da biblioteca "{self.nome}":')
            for livro in self.livros:
                print(f'- {livro.titulo} por {livro.autor} (ISBN: {livro.isbn})')
    
    def busca_livro(self, titulo):
        for livro in self.livros:
            if livro.titulo.lower() == titulo.lower():
                print(f'\nLivro encontrado:')
                print(f'Título: {livro.titulo}')
                print(f'Autor: {livro.autor}')
                print(f'ISBN: {livro.isbn}')
                return livro
        print(f'\nO livro "{titulo}" não foi encontrado na biblioteca "{self.nome}".')
        return None
