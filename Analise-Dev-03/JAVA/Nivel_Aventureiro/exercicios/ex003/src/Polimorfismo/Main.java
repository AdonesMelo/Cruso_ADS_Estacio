package Polimorfismo;

public class Main {
    public static void main(String[] args) {
        Animal[] animais = {new Gato(), new Cachorro(), new Cachorro()};

        for (Animal animal : animais) {
            animal.fazerSom();
        }
    }
}
