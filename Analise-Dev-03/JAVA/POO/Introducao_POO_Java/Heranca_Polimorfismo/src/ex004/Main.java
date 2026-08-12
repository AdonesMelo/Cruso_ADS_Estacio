package ex004;

public class Main {
    private static Aluno aluno;
    private static Endereco endereco;
    private static Data data;

    private static Aluno aluno2;
    private static Endereco endereco2;
    private static Data data2;

    public static void main(String[] args) {
        // Criando uma data de nascimento
        data = new Data(9, 9, 1988); // 1 de Julho de 1988

        // Criando endereço
        endereco = new Endereco();
        endereco.definirPais("Brasil");
        endereco.definirUF("RJ");
        endereco.definirCidade("Rio de Janeiro");
        endereco.definirRua("Fluminense");
        endereco.definirNumero("100");
        endereco.definirCEP("12345678");
        endereco.definirComplemento("Sala 1");

        // Criando aluno
        aluno = new Aluno("João", data.toCalendar(), 123456789L, endereco);
        aluno.atualizarIdade();

        // Criando outro aluno
        data2 = new Data(4, 5, 1988);
        endereco2 = new Endereco();
        endereco2.definirPais("Brasil");
        endereco2.definirUF("SP");
        endereco2.definirCidade("São Paulo");
        endereco2.definirRua("Rua do Rio");
        endereco2.definirNumero("100");
        endereco2.definirCEP("12345678");
        endereco2.definirComplemento("Sala 1");

        aluno2 = new Aluno("Maria", data2.toCalendar(), 223456789L, endereco2);
        aluno2.atualizarIdade();

        // Exibindo dados
        System.out.println("Aluno: " + aluno.recuperarNome());
        System.out.println("Idade: " + aluno.recuperarIdade());
        System.out.println("CPF: " + aluno.recuperarCPF());
        System.out.println("Data de Nascimento: " + data.getDataFormatada());
        System.out.println("Endereço:");
        aluno.recuperarEndereco().getDados();

        System.out.println("\nAluno2: " + aluno2.recuperarNome());
        System.out.println("Idade: " + aluno2.recuperarIdade());
        System.out.println("CPF: " + aluno2.recuperarCPF());
        System.out.println("Data de Nascimento: " + data2.getDataFormatada());
        System.out.println("Endereço:");
        aluno2.recuperarEndereco().getDados();
    }
}
