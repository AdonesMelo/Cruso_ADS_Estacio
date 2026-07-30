package colecoes;

import java.util.ArrayList;
import java.util.List;
import java.util.Iterator; // para iterador com a lista

public class TesteArrayList {
    public static void main(String[] args) {
        List<String> linguagens = new ArrayList<>();
        linguagens.add("Java");
        linguagens.add("Python");
        linguagens.add("Java"); //Permite repetição

        System.out.println(linguagens);

        // Interando com lista
        // for tradicional
        System.out.println("\nFor tradicional, linguagens:");
        for (int i = 0; i < linguagens.size(); i++) {
            System.out.println(linguagens.get(i));
        }

        // forEach
        System.out.println("\nForEach, linguagens:");
        for (String linguagem : linguagens) {
            System.out.println(linguagem);
        }

        //lambda com forEach
        System.out.println("\nLambda com forEach, linguagens:");
        linguagens.forEach(linguagem -> System.out.println(linguagem));

        // Iterador
        System.out.println("\nIterador, linguagens:");
        Iterator<String> it = linguagens.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }

        // Integração com Stream
        System.out.println("\nIntegração com Stream, linguagens:");
        linguagens.stream()
            .forEach(System.out::println);
    }
}
