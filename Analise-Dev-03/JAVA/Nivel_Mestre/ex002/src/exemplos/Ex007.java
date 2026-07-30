package exemplos;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

// Agrupando alunos por curso

class Aluno {
    private String nome;
    private String curso;

    public Aluno(String nome, String curso) {
        this.nome = nome;
        this.curso = curso;
    }

    public String getNome() { return nome; }
    public String getCurso() { return curso; }
}

public class Ex007 {
    public static void main(String[] args) {
    List<Aluno> alunos = Arrays.asList(
        new Aluno("João", "ADS"),
        new Aluno("Maria", "ADS"),
        new Aluno("Pedro", "Jogos Digitais"),
        new Aluno("Laura", "Redes")
    );

    Map<String, List<Aluno>> agrupadoPorCurso = alunos.stream()
        .collect(Collectors.groupingBy(Aluno::getCurso));

    agrupadoPorCurso.forEach((curso, lista) -> {
        System.out.println("Curso: " + curso);
        lista.forEach(a -> System.out.println(" - " + a.getNome()));
    });
    }
}