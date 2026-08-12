package ex007;

public class Main {
    public static void main(String[] args) {
        // Criação de objetos
        Animal gato = new Gato();
        Animal cachorro = new Cachorro();
        Leao leao = new Leao();

        // Invocação de métodos
        // Gato
        gato.emitirSom();
        gato.dormir();

        // Cachorro
        cachorro.emitirSom();
        cachorro.dormir();

        // Leao
        leao.emitirSom();
        leao.tipoDeAnimal();
        leao.dormir();
    }
}
