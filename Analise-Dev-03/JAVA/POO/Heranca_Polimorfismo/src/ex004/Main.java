package ex004;

public class Main {
    private static Aluno aluno;
    private static Endereco endereco;
    private static Data data;

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

        // Exibindo dados
        System.out.println("Aluno: " + aluno.recuperarNome());
        System.out.println("Idade: " + aluno.recuperarIdade());
        System.out.println("CPF: " + aluno.recuperarCPF());
        System.out.println("Data de Nascimento: " + data.getDataFormatada());
        System.out.println("Endereço:");
        aluno.recuperarEndereco().getDados();
    }
}
