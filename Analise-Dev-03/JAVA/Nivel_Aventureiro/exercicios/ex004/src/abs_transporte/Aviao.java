package abs_transporte;

public class Aviao extends Transporte {
    public Aviao(String modelo) {
        super(modelo);
    }

    @Override
    public void mover() {
        System.out.println("Voando com o avião " + modelo);
    }
}