package colecoes;

import java.util.List;
import java.util.LinkedList;

public class TesteLinkedList {
    public static void main(String[] args) {
        List<String> linguagens = new LinkedList<>();
        linguagens.add("Java");
        linguagens.add("Python");
        linguagens.add("Java"); //Permite repetição

        System.out.println(linguagens);
    }   
}
