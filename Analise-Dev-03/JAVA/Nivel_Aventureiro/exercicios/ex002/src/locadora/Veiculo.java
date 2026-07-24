package locadora;

public class Veiculo {
    protected String marca;
    protected String modelo;
    private String placa;

    public Veiculo(String marca, String modelo, String placa) {
        this.marca = marca;
        this.modelo = modelo;
        this.placa = placa;
    }

    // Getter para acessar atributo privado
    public String getDescricao() {
        return marca + " " + modelo + " - Placa: " + placa;
    }
}
