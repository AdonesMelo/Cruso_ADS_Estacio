package ex007;

public class Main {
    public static void main(String[] args) {
        Animal gato = new Gato();
        Animal cachorro = new Cachorro();

        gato.emitirSom();
        gato.dormir();

        cachorro.emitirSom();
        cachorro.dormir();
    }
}
