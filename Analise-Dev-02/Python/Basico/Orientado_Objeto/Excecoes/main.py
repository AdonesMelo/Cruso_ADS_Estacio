from Classes_Calculadora.Calculadora import Calculadora

def main():
    calculadora = Calculadora()
    # Testando as implementações
    print(calculadora.adicao(5, 3))
    print(calculadora.subtracao(5, 3))
    print(calculadora.multiplicacao(5, 'a'))
    print(calculadora.divisao(5, 0))

if __name__ == '__main__':
    main()