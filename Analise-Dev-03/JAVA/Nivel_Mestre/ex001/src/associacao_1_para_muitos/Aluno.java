package associacao_1_para_muitos;

public class Aluno {
    private String nome;

    // Construtor
    public Aluno(String nome) {
        this.nome = nome;
    }

    // Método para retornar os dados do aluno
    public String getDados() {
        return "Nome: " + nome;
    }

    // Getters (se precisar acessar individualmente)
    public String getNome() {
        return nome;
    }
}