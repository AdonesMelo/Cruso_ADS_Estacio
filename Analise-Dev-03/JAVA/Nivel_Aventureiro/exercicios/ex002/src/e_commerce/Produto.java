package e_commerce;

public class Produto {
    protected String nome;
    protected double preco;

    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }

    public String getInfo() {
        return nome + " - R$ " + preco;
    } 
}
