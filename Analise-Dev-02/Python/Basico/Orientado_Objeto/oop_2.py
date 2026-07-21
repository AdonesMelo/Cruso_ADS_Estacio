# sem o __init__
class Obj():
    def const(self):
        print('Sem o metodo construtor(__init__)')

def main():
    obj_a = Obj() # Objeto sendo instanciado
    obj_a.const()

if __name__ == '__main__':
    main()