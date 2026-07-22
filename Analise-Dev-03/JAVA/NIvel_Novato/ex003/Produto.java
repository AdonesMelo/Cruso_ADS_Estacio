public class Produto {
    String nome;
    double preco;

    // Construtor
    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }
    
    // Método para aumentar o preço do produto
    public void aumentarPreco(double percentual) {
    preco = preco + (preco * percentual / 100);
    }

    // Método para diminuir o preço do produto
    public void diminuirPreco(double percentual) {
        preco = preco - (preco * percentual / 100);
    }

    // Método para exibir as informações do produto
    public void exibirProduto() {
        System.out.println("Produto: " + nome + " | Preço: " + preco);
    }
}