package abs_transporte;

public class Carro extends Transporte {
    public Carro(String modelo) {
        super(modelo);
    }

    @Override
    public void mover() {
        System.out.println("Dirigindo o carro " + modelo);
    }
}