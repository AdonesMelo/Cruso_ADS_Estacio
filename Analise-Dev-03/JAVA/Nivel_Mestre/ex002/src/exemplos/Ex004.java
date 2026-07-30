package exemplos;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

// joining() separa lista em string
public class Ex004 {
    public static void main(String[] args) {
        List<String> nomes = Arrays.asList("João", "Maria", "Pedro", "José");
        String resultado = nomes.stream()
            .collect(Collectors.joining(", ")); // separa por vírgula

        System.out.println(resultado);
    }
}
