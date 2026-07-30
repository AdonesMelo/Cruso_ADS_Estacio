package exemplos;
import java.util.List;
import java.util.Arrays;

public class Ex001 {
    public static void main(String[] args) {
        List<String> nomes = Arrays.asList("João", "Maria", "Pedro", "José", "João"); // cria lista
        nomes.stream() // cria stream
            .distinct() // remove repetições
            .sorted() // ordena
            .forEach(System.out::println); // imprime
    }
}