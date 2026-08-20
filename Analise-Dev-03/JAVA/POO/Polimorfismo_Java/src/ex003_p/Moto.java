package ex003_p;

public class Moto extends Veiculo {
    // Métodos construtor
    public Moto(String marca) {
        super(marca);
    }

    @Override
    public void acelerar() {
        System.out.println(getMarca() + " Moto acelerando");
    }

    @Override
    public void frear() {
        System.out.println(getMarca() + " Moto freando");
    }
}
