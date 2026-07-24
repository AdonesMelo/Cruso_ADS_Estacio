package locadora;

public class Carro extends Veiculo {
    private int qtdPortas;

    public Carro(String marca, String modelo, String placa, int qtdPortas) {
        super(marca, modelo, placa);
        this.qtdPortas = qtdPortas;
    }

    // Getter para acessar atributo privado
    public int getQtdPortas() {
        return qtdPortas;
    }
    
}
