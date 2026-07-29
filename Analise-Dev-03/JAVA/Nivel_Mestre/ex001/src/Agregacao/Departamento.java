package Agregacao;
import java.util.ArrayList;
import java.util.List;

public class Departamento {
    private String nome;
    private List<Funcionario> funcionarios;

    public Departamento(String nome) {
        this.nome = nome;
        this.funcionarios = new ArrayList<>();
    }

    public void adicionarFuncionario(Funcionario f) {
        funcionarios.add(f);
    }

    public void getDados() {
        System.out.println(nome + ":");
        for (Funcionario f : funcionarios) {
            System.out.println(f.getNome());
        }
    }
}
