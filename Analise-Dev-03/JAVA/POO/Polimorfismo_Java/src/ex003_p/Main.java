package ex003_p;

public class Main {
    public static void main(String[] args) {
        // Instanciação de objetos
        Veiculo v1 = new Carro("Fiat");
        Veiculo v2 = new Moto("Honda");

        // Métodos de acesso aos atributos
        v1.acelerar();
        v1.frear();

        v2.acelerar();
        v2.frear();
    }
}
