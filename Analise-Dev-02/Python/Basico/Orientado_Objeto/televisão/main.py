# Crie dois objetos de televisão e teste a subida e a descida dos canais.
from oop_tv import Televisao
def main():
    print()
    tv_1 = Televisao(2, 2, 10)
    print(tv_1.canal)
    for x in range(1, 20):
        tv_1.canal_para_cima()
        print(tv_1.canal)

    print()
    tv_2 = Televisao(10, 2, 10)
    print(tv_2.canal)
    for x in range(1, 20):
        tv_2.canal_para_baixo()
        print(tv_2.canal)

if __name__ == '__main__':
    main()