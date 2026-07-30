package ordenacao_Comparable;

public class Livro implements Comparable<Livro> {
    private String titulo;

    public Livro(String titulo) {
        this.titulo = titulo;
    }

    public String getTitulo() {
        return titulo;
    }

    @Override
    public int compareTo(Livro outro) {
        return this.titulo.compareTo(outro.getTitulo());
    }

    @Override
    public String toString() {
        return titulo;
    }
}