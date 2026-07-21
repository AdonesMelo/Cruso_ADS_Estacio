class Calculadora:
    def adicao(self, x, y):
        try:
            return x + y
        except TypeError:
            return 'Erro: Tipo de dados inválidos para adição.'
        
    def subtracao(self, x, y):
        try:
            return x - y
        except TypeError:
            return 'Erro: Tipo de dados inválidos para subtração.'
        
    def multiplicacao(self, x, y):
        if not (isinstance(x, (int, float)) and isinstance(y, (int, float))):
            return 'Erro: Tipo de dados inválidos para multiplicação.'
        try:
            return x * y
        except TypeError:
            return 'Erro: Tipo de dados inválidos para Multiplicação.'
        
    def divisao(self, x, y):
        try:
            return x / y
        except TypeError:
            return 'Erro: Tipo de dados inválidos para Divisão.'
        except ZeroDivisionError:
            return 'Erro: Não pode dividir por zero!'