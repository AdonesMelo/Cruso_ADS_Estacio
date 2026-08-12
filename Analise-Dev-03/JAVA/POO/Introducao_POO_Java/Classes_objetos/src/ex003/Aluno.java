package ex003;

class Aluno {
    // Atributos
    private String nome;
    private int idade;

    // Metodos
    public Aluno (String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    public void definirNome (String nome) {
        this.nome = nome;
    }

    public void definirIdade (int idade) {
        this.idade = idade;
    }

    public String recuperaNome () {
        return this.nome;
    }

    public int recuperaIdade () {
        return this.idade;
    }
}