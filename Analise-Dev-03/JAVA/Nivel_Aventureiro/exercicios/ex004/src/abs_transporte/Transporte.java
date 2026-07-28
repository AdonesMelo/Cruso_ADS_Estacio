package abs_transporte;

public abstract class Transporte {
    protected String modelo;

    public Transporte(String modelo) {
        this.modelo = modelo;
    }

    public abstract void mover();
}