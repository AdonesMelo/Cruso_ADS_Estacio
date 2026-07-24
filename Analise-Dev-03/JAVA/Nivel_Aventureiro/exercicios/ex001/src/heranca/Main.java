package heranca;

public class Main {
    public static void main(String[] args) {
        Aluno aluno = new Aluno("João Pedro", "123456789", 38, "123456789");
        Funcionario funcionario = new Funcionario("Maria Aparecida", "987456123", 36, 3800.00);

        aluno.mostrarDados();
        funcionario.mostrarDados();
    }
}
