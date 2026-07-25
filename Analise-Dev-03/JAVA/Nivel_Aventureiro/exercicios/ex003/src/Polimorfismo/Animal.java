package Polimorfismo;

public class Animal {
    public void fazerSom() {
        System.out.println("Som genérico do animal");
    }
}

class Gato extends Animal {
    public void fazerSom() {
        System.out.println("Miado!");
    }
}

class Cachorro extends Animal {
    public void fazerSom() {
        System.out.println("Latido!");
    }
}