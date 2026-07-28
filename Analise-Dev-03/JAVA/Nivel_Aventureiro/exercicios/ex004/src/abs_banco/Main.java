package abs_banco;

public class Main {
    public static void main(String[] args) {
        ContaCorrente c1 = new ContaCorrente("Joao", 1000);
        c1.depositar(100);
        c1.sacar(50);
    }
}
