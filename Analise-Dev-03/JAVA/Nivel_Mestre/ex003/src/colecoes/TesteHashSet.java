package colecoes;

import java.util.Set;
import java.util.HashSet;


public class TesteHashSet {
    public static void main(String[] args) {
        Set<String> emails = new HashSet<>();
        emails.add("joao@gmail.com");
        emails.add("maria@gmail.com");
        emails.add("joao@gmail.com"); // Não permite repetição

        System.out.println(emails);
    }
}
