package ex007;

/*
 Agora, o nosso desafio é implementar a classe “Leao” que também vai herdar da classe “Animal”, mas, além disso, ela deve ter um método “tipoDeAnimal” que imprima a mensagem: “É um animal selvagem”.
*/

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

class Leao extends Animal {

    @Override
    public void emitirSom() {
        System.out.println("Grrrrr...");
    }

    public void tipoDeAnimal() {
        System.out.println("É um animal selvagem");
    }

    @Override
    public void dormir() {
        System.out.println("Zzzzzzzz...");
    }
}