from Pessoa import Pessoa

def main():
    pessoa_1 = Pessoa('João', 60)
    print(pessoa_1.nome)
    print(pessoa_1.idade)
    print(Pessoa.maior_idade(pessoa_1.idade))

    print()

    pessoa_2 = Pessoa.dt_nasc('Maria', 2015)
    print(pessoa_2.nome)
    print(pessoa_2.idade)
    print(Pessoa.maior_idade(pessoa_2.idade))
    
if __name__ == '__main__':
    main()