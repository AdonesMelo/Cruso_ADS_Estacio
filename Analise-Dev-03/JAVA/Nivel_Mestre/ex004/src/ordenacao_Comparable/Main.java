package ordenacao_Comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Livro> livros = new ArrayList<>();

        livros.add(new Livro("Java Básico"));
        livros.add(new Livro("Algoritmos"));
        livros.add(new Livro("Orientação a Objetos"));

        Collections.sort(livros);

        System.out.println(livros); // [Algoritmos, Java Básico, Orientação a Objetos]
    } 
}
