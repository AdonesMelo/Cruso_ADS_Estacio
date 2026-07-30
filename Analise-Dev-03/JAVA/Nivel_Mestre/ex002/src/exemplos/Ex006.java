package exemplos;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

// partitioningBy() separa itens em lista de booleanos (true/false)
public class Ex006 {
    public static void main(String[] args) {
        List<Integer> numeros = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

        Map<Boolean, List<Integer>> resultado = numeros.stream()
            .collect(Collectors.partitioningBy(numero -> numero % 2 == 0));

        System.out.println(resultado);
    }
}
