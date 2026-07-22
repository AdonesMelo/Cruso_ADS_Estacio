public class Main {
    public static void main(String[] args) {
        Produto p1 = new Produto("Notebook", 3500);
        Produto p2 = new Produto("Teclado", 100);
        Produto p3 = new Produto("Mouse", 70);

        System.out.println("Produtos criados...");
        p1.exibirProduto();
        p2.exibirProduto();
        p3.exibirProduto();

        System.out.println("\nAumentando preços...");
        p1.aumentarPreco(10);
        p2.aumentarPreco(20);
        p3.aumentarPreco(30);

        System.out.println("\nNovo preço dos produtos...");
        p1.exibirProduto();
        p2.exibirProduto();
        p3.exibirProduto();

        System.out.println("\nDiminuindo preços...");
        p1.diminuirPreco(30);
        p2.diminuirPreco(10);
        p3.diminuirPreco(20);

        System.out.println("\nNovo preço dos produtos...");
        p1.exibirProduto();
        p2.exibirProduto();
        p3.exibirProduto();
    }   
}

// roda no terminal: javac Produto.java Main.java
// roda no terminal: java Main
