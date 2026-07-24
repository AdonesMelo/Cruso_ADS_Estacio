package heranca;

public class Aluno extends Pessoa {
    private String matricula;

    public Aluno(String nome, String cpf, int idade, String matricula) {
        super(nome, cpf, idade);
        this.matricula = matricula;
    }

    // Getter para acessar atributo privado
    public String getMatricula() {
        return matricula;
    }

    // Método para acessar atributo privado
    public void mostrarDados() {
        System.out.println("--- Informações do Aluno ---");
        System.out.println("Nome: " + nome);             // public → acessível
        System.out.println("CPF: " + this.getCpf());     // private → só via getter
        System.out.println("Idade: " + idade);           // protected → acessível
        System.out.println("Matricula: " + this.getMatricula());
        System.out.println();
    }
}
