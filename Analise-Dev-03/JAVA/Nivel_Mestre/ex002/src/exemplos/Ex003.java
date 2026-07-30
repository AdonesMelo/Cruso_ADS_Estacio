package exemplos;

import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

// toSet() converte o stream para set
public class Ex003 {
    public static void main(String[] args) {
        List<String> nomes = Arrays.asList("João", "Maria", "Pedro", "José", "João");
        Set<String> resultado = nomes.stream()
            .collect(Collectors.toSet()); // converte para set, remove repetições

        System.out.println(resultado);
    }  
}
