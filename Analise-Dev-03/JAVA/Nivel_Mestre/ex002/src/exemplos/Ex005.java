package exemplos;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Map;

// groupBy() agrupa itens
public class Ex005 {
    public static void main(String[] args) {
        List<String> nomes = Arrays.asList("João", "Maria", "Pedro", "José");
        Map<Character, List<String>> resultado = nomes.stream()
            .collect(Collectors.groupingBy(nome -> nome.charAt(0))); // agrupa por primeiro caractere

        System.out.println(resultado);
    }
}
