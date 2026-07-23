public class Main {
    public static void main(String[] args) {
        // cria uma conta bancaria com saldo inicial
        ContaBancaria conta = new ContaBancaria(1000);
        System.out.println("Saldo atual: " + conta.getSaldo());

        conta.setDepositar(150);
        conta.setSacar(350);
    }
}

// No terminal: javac ContaBancaria.java Main.java
// No terminal: java Main
