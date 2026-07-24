package e_commerce;

public class Eletronico extends Produto {
    private String fabricante;
    private int garantiaMeses;

    public Eletronico(String nome, double preco, String fabricante, int garantiaMeses) {
        super(nome, preco);
        this.fabricante = fabricante;
        this.garantiaMeses = garantiaMeses;
    }

    public String getDetalhes() {
        return getInfo() + " | Fabricante: " + fabricante + " | Garantia: " + garantiaMeses + " meses";
    }
}
