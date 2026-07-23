public class ContaBancaria {
    private double saldo; // Atributo privado

    // construtor com saldo inicial
    public ContaBancaria(double saldoInicial) {
        if (saldoInicial >= 0) {
            this.saldo = saldoInicial;
        }
    }

    // getter
    public double getSaldo() {
        return saldo;
    }

    // setter
    public void setDepositar(double valor) {
        System.out.println("Depositando...");
        if (valor > 0) {
            saldo += valor;
        }

        System.out.println("Depositado: R$" + valor);
        System.out.println("Saldo atual: R$" + saldo);
    }

    // setter
    public void setSacar(double valor) {
        System.out.println("Sacando...");
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
        }

        System.out.println("Sacado: R$" + valor);
        System.out.println("Saldo atual: R$" + saldo);
    }
}