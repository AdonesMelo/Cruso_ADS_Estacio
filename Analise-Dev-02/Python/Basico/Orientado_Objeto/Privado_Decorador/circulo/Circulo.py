class Circulo():

    total_circulos = 0  # Atributo de classe

    def __init__(self, pontox, pontoy, raio):
        self.pontox = pontox
        self.pontoy = pontoy
        self.raio = raio
        Circulo.total_circulos += 1  # Incrementando o atributo de classe