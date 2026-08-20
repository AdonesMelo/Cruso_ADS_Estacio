package ex006;

public class Pessoa {
    // atributos
    protected String nome;
    protected String identificador;


    public Pessoa(String nome, String identificador) {
        this.nome = nome;
        this.identificador = identificador;
    }

    // Métodos
    @Override
    public boolean equals(Object obj) {
        if (this.identificador == ((Pessoa)obj).identificador) {
            return true;
        }
        else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return this.identificador.hashCode();
    }
}