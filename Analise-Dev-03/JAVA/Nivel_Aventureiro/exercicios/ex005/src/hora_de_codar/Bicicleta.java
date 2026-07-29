package hora_de_codar;

public class Bicicleta extends Veiculo {
    int numAro;

    public Bicicleta(String marca, String modelo, int numAro) {
        super(marca, modelo);
        this.numAro = numAro;
    }

    @Override
    public String descrever() {
        return "Bicicleta - " + super.descrever() + ", Aro: " + numAro + '"';
    } 
}
