package composicao;

public class Main {
    public static void main(String[] args) {
        Pedido pedido = new Pedido();
        pedido.adicionarItem("Notebook", 1);
        pedido.adicionarItem("Mouse", 2);
        pedido.adicionarItem("Mouse", 3);

        pedido.exibirPedido();
    }
}
