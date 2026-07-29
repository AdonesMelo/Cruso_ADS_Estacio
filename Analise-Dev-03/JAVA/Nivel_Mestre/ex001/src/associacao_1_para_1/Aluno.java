package associacao_1_para_1;

public class Aluno {
    private String nome;
    private Curso curso; // Associação um-para-um

    public Aluno(String nome, Curso curso) {
        this.nome = nome;
        this.curso = curso;
    }

    public String getDados() {
        return nome + " - Curso: " + curso.getNome();
    }
}
