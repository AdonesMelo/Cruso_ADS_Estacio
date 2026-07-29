package hora_de_codar;

public class Carro extends Veiculo {
    int qtdPortas;

    public Carro(String marca, String modelo, int qtdPortas) {
        super(marca, modelo);
        this.qtdPortas = qtdPortas;
    }

    @Override
    public String descrever() {
        return "Carro - " + super.descrever() + ", Portas: " + qtdPortas;
    }
}
