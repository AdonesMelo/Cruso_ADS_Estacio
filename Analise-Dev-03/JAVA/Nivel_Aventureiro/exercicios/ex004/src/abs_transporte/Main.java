package abs_transporte;

public class Main {
    public static void main(String[] args) {
        // Criação de objetos
        Transporte t1 = new Bicicleta("Caloi");
        Transporte t2 = new Aviao("Airbus");
        Transporte t3 = new Carro("Mercedes");

        // Chama os métodos
        t1.mover();
        t2.mover();
        t3.mover();
    }
}