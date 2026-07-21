# Tarifa do taximetro
def taximetro(distancia, multiplicador=1):
    largura = 3
    km_rodado = 2
    valor = (largura + distancia * km_rodado) * multiplicador

    return valor

pagamento = taximetro(3.5, 2)
print(f'A corrida custou R$ {pagamento:,.2f}') 