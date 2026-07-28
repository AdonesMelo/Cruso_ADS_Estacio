package abs_transporte;

public class Bicicleta extends Transporte {
    public Bicicleta(String modelo) {
        super(modelo);
    }

    @Override
    public void mover() {
        System.out.println("Pedalando a bicicleta " + modelo);
    }
}