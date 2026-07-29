package hora_de_codar;

public class Moto extends Veiculo {
    int cilindrada;

    public Moto(String marca, String modelo, int cilindrada) {
        super(marca, modelo);
        this.cilindrada = cilindrada;
    }

    @Override
    public String descrever() {
        return "Moto - " + super.descrever() + ", Cilindrada: " + cilindrada + "cc";
    }
}
