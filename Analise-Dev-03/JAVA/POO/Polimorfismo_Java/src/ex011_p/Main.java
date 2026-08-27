package ex011_p;

import java.util.ArrayList;
import java.util.List;

interface Animal {
    String getNome();
    String emitirSon();
}


class Gato implements Animal {
    private String nome;

    public Gato(String nome) {
        this.nome = nome;
    }

    @Override
    public String getNome() {
        return nome;
    }

    @Override
    public String emitirSon() {
        return "Miando";
    }
}


class Cachorro implements Animal {
    private String nome;

    public Cachorro(String nome) {
        this.nome = nome;
    }

    @Override
    public String getNome() {
        return nome;
    }

    @Override
    public String emitirSon() {
        return "Latindo";
    }
}


class Pato implements Animal {
    private String nome;

    public Pato(String nome) {
        this.nome = nome;
    }

    @Override
    public String getNome() {
        return nome;
    }

    @Override
    public String emitirSon() {
        return "Quack";
    }
}


public class Main {
    public static void main(String[] args) {
        List<Animal> listaAnimais = new ArrayList<>();

        listaAnimais.add(new Gato("Nina"));
        listaAnimais.add(new Cachorro("Pluto"));
        listaAnimais.add(new Pato("Donald"));

        // Usando programação funcional para filtrar e manipular os animais
        System.out.println("Animais com nomes curtos:");
        listaAnimais.stream()
            .filter(animal -> animal.getNome().length() < 7)
            .forEach(animal -> System.out.println(animal.getNome() + ": " + animal.emitirSon()));

        System.out.println("\nAnimais que emitem sons com 5 letras:");
        listaAnimais.stream()
            .filter(animal -> animal.emitirSon().length() == 5)
            .forEach(animal -> System.out.println(animal.getNome() + ": " + animal.emitirSon()));
    }
}