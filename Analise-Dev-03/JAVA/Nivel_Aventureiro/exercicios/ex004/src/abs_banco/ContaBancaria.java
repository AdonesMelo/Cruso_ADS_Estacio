package abs_banco;

// Classe abstrata
public abstract class ContaBancaria {
    // atributos
    protected String titular;
    protected double saldo;

    // construtor
    public ContaBancaria(String titular, double saldo) {
        this.titular = titular;
        this.saldo = saldo;
    }

    // Metodos
    public void depositar(double valor) {
        saldo += valor;
        System.out.println("Depositado: R$" + valor + " na conta " + titular);
    }

    // Metodos abstratos
    public abstract void sacar(double valor);
}
