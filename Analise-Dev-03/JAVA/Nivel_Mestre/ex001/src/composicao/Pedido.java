package composicao;
import java.util.ArrayList;
import java.util.List;

public class Pedido {
    private List<ItemPedido> itens;

    public Pedido() {
        this.itens = new ArrayList<>();
    }

    public void adicionarItem(String produto, int quantidade) {
        ItemPedido item = new ItemPedido(produto, quantidade);
        itens.add(item);
    }

    public void exibirPedido() {
        for (ItemPedido item : itens) {
            System.out.println(item.getDescricao());
        }
    }
}
