package colecoes;

import java.util.HashMap;
import java.util.Map;

public class TesteHashMap {
    public static void main(String[] args) {
        Map<String, String> capital = new HashMap<>();
        capital.put("Brasil", "Rio de Janeiro");
        capital.put("Argentina", "Buenos Aires");
        capital.put("Canada", "Ottawa");

        System.out.println(capital);
        System.out.println();

        capital.put("Brasil", "Brasilia"); // Chave repetida

        // Como a chave é repetida, troca somente o valor
        System.out.println(capital);
        System.out.println();
        System.out.println("Valor da chave Brasil: " + capital.get("Brasil"));
    }
}
