package exemplos;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

// Média por departamento

class Funcionario {
    private String nome;
    private String departamento;
    private double salario;

    public Funcionario(String nome, String departamento, double salario) {
        this.nome = nome;
        this.departamento = departamento;
        this.salario = salario;
    }
    public String getNome() { return nome; }
    public String getDepartamento() { return departamento; }
    public double getSalario() { return salario; }
}

public class Ex009 {
    public static void main(String[] args) {
        List<Funcionario> funcionarios = Arrays.asList(
        new Funcionario("Ana", "TI", 5000),
        new Funcionario("Bruno", "TI", 6000),
        new Funcionario("Carlos", "RH", 4000)
        );

    Map<String, Double> mediaPorDepartamento = funcionarios.stream()
        .collect(Collectors.groupingBy(
            Funcionario::getDepartamento,
            Collectors.averagingDouble(Funcionario::getSalario)
        ));

    mediaPorDepartamento.forEach((dep, media) ->
        System.out.println(dep + ": R$" + media));
    }
}
