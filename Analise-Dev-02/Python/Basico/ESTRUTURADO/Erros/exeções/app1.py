# passo a passo como erro de exeção
# passo 3
while True:
    # passo 1
    try:
        num = int(input('Digite uma número: '))
        # passo 5
        mult = num * 3
        print(mult)
        resu = 10 / mult
        print(resu)
        #passo 4
        #break
    # passo 2
    except ValueError:
        print('Erro: Entre com um número!')
    # passo 5
    except ZeroDivisionError:
        print('Erro: Não permite dividir por zero!')
    # passo 6
    else:
        print('Entrou no else')
        break
    finally:
        print('Entrou no finally') # uma mensagem que vai sempre ser exibida no final da execução