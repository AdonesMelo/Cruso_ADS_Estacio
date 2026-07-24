package heranca;

public class Funcionario extends Pessoa {
    private double salario;

    public Funcionario(String nome, String cpf, int idade, double salario) {
        super(nome, cpf, idade);
        this.salario = salario;
    }

    // Getter para acessar atributo privado
    public double getSalario() {
        return salario;
    }

    // Método para acessar atributo privado
    public void mostrarDados() {
        System.out.println("--- Informações do Funcionário ---");
        System.out.println("Nome: " + nome);
        System.out.println("CPF: " + this.getCpf());
        System.out.println("Idade: " + idade);
        System.out.println("Salario: " + this.getSalario());
        System.out.println();
    }
}
