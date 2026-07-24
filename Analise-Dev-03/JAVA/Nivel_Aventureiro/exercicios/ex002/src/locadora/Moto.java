package locadora;

public class Moto extends Veiculo {
    private boolean possuiBau;

    public Moto(String marca, String modelo, String placa, boolean possuiBau) {
        super(marca, modelo, placa);
        this.possuiBau = possuiBau;
    }

    // Getter para acessar atributo privado
    public boolean isPossuiBau() {
        return possuiBau;
    }
}
