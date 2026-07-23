package Produto;

public class Main {
    public static void main(String[] args) {
        Produto p1 = new Produto("Notebook", 3500, 10);
        Produto p2 = new Produto("Mouse", 75, 100);

        p1.exibirInformacoes();
        p2.exibirInformacoes();
    }
}
