class Extrato:
    def __init__(self):
        self.transacoes = []

    def extrato(self, numero_conta):
        print(f'Extrato: {numero_conta}\n')
        for transacao in self.transacoes:
            print(f'{transacao[0]:15s} {transacao[1]:10.2f} {transacao[2]:10s} {transacao[3].strftime('%d/%b/%y')}')