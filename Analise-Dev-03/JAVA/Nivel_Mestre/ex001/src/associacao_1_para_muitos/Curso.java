package associacao_1_para_muitos;
import java.util.ArrayList;
import java.util.List;

public class Curso {
    private String nome;
    private List<Aluno> alunos; // Associação um-para-muitos

    public Curso(String nome) {
        this.nome = nome;
        this.alunos = new ArrayList<>(); // Criando uma lista vazia
    }

    // Método para adicionar um aluno
    public void adicionarAluno(Aluno aluno) {
        alunos.add(aluno);
    }

    // Método para listar os alunos
    public void listarAlunos() {
        for (Aluno a : alunos) {
            System.out.println(a.getDados());
        }
    }

    // Getters (se precisar acessar individualmente)
    public String getNome() {
        return nome;
    }
}
