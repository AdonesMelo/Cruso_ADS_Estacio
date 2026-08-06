package ex007;

// Classe abstrata
abstract class Animal {

    // Método abstrato
    public abstract void emitirSom();

    public void dormir() {
        System.out.println("Zzzzzz...");
    }
}


// Subclasse concreta
class Gato extends Animal {

    @Override
    public void emitirSom() {
        System.out.println("Miau!");
    }
}

class Cachorro extends Animal {

    @Override
    public void emitirSom() {
        System.out.println("Au! Au!");
    }
}