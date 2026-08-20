package ex003_p;

public class Carro extends Veiculo {
    // Métodos construtor
    public Carro(String marca) {
        super(marca);
    }

    @Override
    public void acelerar() {
        System.out.println(getMarca() + " Carro acelerando");
    }

    @Override
    public void frear() {
        System.out.println(getMarca() + " Carro freando");
    }
}
