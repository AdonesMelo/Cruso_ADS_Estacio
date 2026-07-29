package hora_de_codar;

public class Veiculo {
    String marca;
    String modelo;

    public Veiculo(String marca, String modelo) {
        this.marca = marca;
        this.modelo = modelo;
    }

    public String descrever() {
        return "Marca: " + marca + ", Modelo: " + modelo;
    }   
}
