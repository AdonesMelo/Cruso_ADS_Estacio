package e_commerce;

public class TesteEcommerce {
    public static void main(String[] args) {
        Livro livro = new Livro("Programação Java", 95.90, "Adones Melo", "123456789012");
        Eletronico notebook = new Eletronico("IdeaPad i5", 3499.99, "Lenovo", 12);

        System.out.println(livro.getDetalhes());
        System.out.println(notebook.getDetalhes());
    }
}