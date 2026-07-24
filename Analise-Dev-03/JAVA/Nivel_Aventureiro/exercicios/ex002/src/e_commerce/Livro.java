package e_commerce;

public class Livro extends Produto {
    private String autor;
    private String isbn;

    public Livro(String nome, double preco, String autor, String isbn) {
        super(nome, preco);
        this.autor = autor;
        this.isbn = isbn;
    }

    public String getDetalhes() {
        return getInfo() + " | Autor: " + autor + " | ISBN: " + isbn;
    }
}
