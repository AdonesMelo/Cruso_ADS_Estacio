package ex002;

import java.util.SortedSet;
import java.util.TreeSet;

public class Principal {
    //Atributos
    private static SortedSet<Aluno> cj_ordenado;
    public static void main(String[] args) {
        cj_ordenado = new TreeSet<Aluno>(new ComparaPessoa());
        cj_ordenado.add(new Aluno("Pedro", "12345678912", "M1"));
        cj_ordenado.add(new Aluno("Maria", "12345678912", "M2"));
        cj_ordenado.add(new Aluno("João", "32165498721", "M3"));
        cj_ordenado.add(new Aluno("José", "78945612332", "M4"));
        System.out.println(cj_ordenado);
    }
}