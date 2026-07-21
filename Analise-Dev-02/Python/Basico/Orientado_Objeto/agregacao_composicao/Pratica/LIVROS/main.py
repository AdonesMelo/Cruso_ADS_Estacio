from Livro import Livro, Biblioteca

def main():
    # criando livros
    livro_1 = Livro('O Senhor dos Anéis', 'J.R.R Tolkien', '1234567890')
    livro_2 = Livro('1984', 'George Orwell', '0987654321')
    livro_3 = Livro('O A panhador no Campo de Centeio', 'J.D Salinger', '1452369870')

    # criando uma biblioteca
    biblioteca = Biblioteca('Biblioteca Central')

    # adicionando livros na biblioteca
    print()
    biblioteca.add_livro(livro_1)
    biblioteca.add_livro(livro_2)
    biblioteca.add_livro(livro_3)
    
    # listando todos os livros
    biblioteca.listar_livros()

    # remover um livro da biblioteca (usando o isbn)
    biblioteca.del_livro('0987654321')

    # listando todos os livros após a remoção
    biblioteca.listar_livros()

if __name__ == '__main__':
    main()