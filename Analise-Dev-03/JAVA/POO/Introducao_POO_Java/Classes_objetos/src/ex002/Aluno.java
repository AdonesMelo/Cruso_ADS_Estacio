package ex002;

public class Aluno {
    // Atributos privados (Encapsulamento)
    private String nome;
    private String cpf;
    private String matricula;
    private String email;

    // Construtor completo
    public Aluno(String nome, String cpf, String matricula, String email) {
        this.nome = nome;
        this.cpf = cpf;
        this.matricula = matricula;
        this.email = email;
    }

    // Construtor simplificado (sobrecarga para conveniência)
    public Aluno(String nome, String matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    // Método para exibir informações completas do Aluno
    public void getDados() {
        System.out.println("Matrícula: " + matricula + " | Nome: " + nome + " | CPF: " + cpf);
    }
}