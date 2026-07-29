package composicao;

public class ItemPedido {
    private String produto;
    private int quantidade;

    public ItemPedido(String produto, int quantidade) {
        this.produto = produto;
        this.quantidade = quantidade;
    }

    public String getDescricao() {
        return quantidade + "x " + produto;
    }
}