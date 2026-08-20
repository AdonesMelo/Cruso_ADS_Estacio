package ex003_p;

public abstract class Veiculo {
    // Atributos
    private String marca;

    // Métodos construtor
    public Veiculo(String marca) {
        this.marca = marca;
    }

    // Métodos abstratos
    public abstract void acelerar();
    public abstract void frear();

    // Métodos getters
    public String getMarca() {
        return marca;
    } 
}
