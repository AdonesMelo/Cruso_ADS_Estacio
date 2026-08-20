package ex001_p;

// Classe abstrata
public abstract class Pessoa {
    // atributos
    protected int identificador;

    // Métodos construtor
    public Pessoa(int identificador) {
        this.identificador = identificador;
    }

    // Métodos abstratos
    public abstract void atualizarID();

    // Métodos concretos
    public int recuperarID() {
        return identificador;
    }
}
