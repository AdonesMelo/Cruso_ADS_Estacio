from circulo.Circulo import Circulo

circ1 = Circulo(1, 1, 10)
print(circ1.total_circulos)  # Isso agora imprimirá 1

circ2 = Circulo(2, 2, 20)
print(circ1.total_circulos)  # Isso agora imprimirá 2
print(circ2.total_circulos)  # Isso também imprimirá 2

print(Circulo.total_circulos)  # Isso imprimirá 2, já que é o valor compartilhado por todas as instâncias