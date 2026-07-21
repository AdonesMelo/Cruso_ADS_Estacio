from Classes_Veiculos.Carrro import Carro
from Classes_Veiculos.Bicicleta import Bicicleta
from Classes_Veiculos.Aviao import Aviao

def main():
    # Testando as implementações
    carro = Carro()
    bicicleta = Bicicleta()
    

    print(carro.mover())
    print(carro.ligar())

    print()

    print(bicicleta.mover())
    print(bicicleta.ligar())

    print()

    # Testa a implementação da classe Aviao
    aviao = Aviao()
    print(aviao.mover())
    print(aviao.ligar())

if __name__ == '__main__':
    main()