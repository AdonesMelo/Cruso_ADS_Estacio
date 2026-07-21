from Classes_Animais.Animal import fazer_som, fazer_movimento
from Classes_Animais.Cachorro import Cachorro
from Classes_Animais.Gato import Gato
from Classes_Animais.Vaca import Vaca
from Classes_Animais.Pato import Pato
from Classes_Animais.Jacare import Jacare

def main():
    cachorro = Cachorro('Nala')
    gato = Gato('Toni')
    vaca = Vaca('Mimosa')
    pato = Pato('Donald')
    jacare = Jacare('Brum')

    print(fazer_som(cachorro))
    print(fazer_movimento(cachorro))

    print()

    print(fazer_som(gato))
    print(fazer_movimento(gato))

    print()

    print(fazer_som(vaca))
    print(fazer_movimento(vaca))

    print()

    print(fazer_som(pato))
    print(fazer_movimento(pato))

    print()

    print(fazer_som(jacare))
    print(fazer_movimento(jacare))

if __name__ == '__main__':
    main()