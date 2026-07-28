package abs_banco;

public class ContaCorrente extends ContaBancaria {

    public ContaCorrente(String titular, double saldo) {
        super(titular, saldo);
    }

    @Override
    public void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
            System.out.println("Sacado: R$" + valor + " na conta " + titular);
        } else {
            System.out.println("Saldo insuficiente");
        }
    }
}
