package exemplos;
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;

// toList() converte o stream para lista
public class Ex002 {
    public static void main(String[] args) {
        List<String> nomes = Arrays.asList("João", "Maria", "Pedro", "José"); // cria lista
        List<String> resultado = nomes.stream()
            .filter(nome -> nome.startsWith("J")) // filtra nomes que começam com J
            .collect(Collectors.toList()); // converte para lista

        System.out.println(resultado);
    }
}
