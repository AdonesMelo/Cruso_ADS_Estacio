package ex002;

public class Escola {
    // Atributos
    private String nome;
    private String cpf; // Pode ser o CPF do responsável/diretor da escola
    private Endereco endereco;
    private Departamento[] departamentos; // Corrigido para array
    private Aluno[] discentes;            // Corrigida a grafia (discentes)
    private int numDiscentes;             // Padronizado para camelCase
    private int numDepartamentos;

    // Construtor
    public Escola(String nome, String cpf, Endereco endereco) {
        this.nome = nome;
        this.cpf = cpf;
        this.endereco = endereco;
        this.departamentos = new Departamento[10]; // Vetor com capacidade para 10 departamentos
        this.discentes = new Aluno[1000];           // Vetor para 1000 alunos
        this.numDiscentes = 0;
        this.numDepartamentos = 0;
    }

    // Adiciona um departamento existente
    public void adicionarDepartamento(Departamento departamento) {
        if (numDepartamentos < departamentos.length) {
            departamentos[numDepartamentos] = departamento;
            numDepartamentos++;
        } else {
            System.out.println("Erro: Não é possível criar mais de " + departamentos.length + " departamentos.");
        }
    }

    // Sobrecarga: Cria e adiciona um departamento direto pelo nome
    public void criarDepartamento(String nomeDepartamento) {
        if (numDepartamentos < departamentos.length) {
            departamentos[numDepartamentos] = new Departamento(nomeDepartamento);
            numDepartamentos++;
        } else {
            System.out.println("Erro: Não é possível criar mais de " + departamentos.length + " departamentos.");
        }
    }

    // Matricular Aluno com verificação de limite e incremento do contador
    public void matricularAluno(Aluno novoAluno) {
        if (numDiscentes < discentes.length) {
            discentes[numDiscentes] = novoAluno;
            numDiscentes++; // Incremento essencial que faltava
        } else {
            System.out.println("Erro: Limite máximo de " + discentes.length + " alunos atingido.");
        }
    }

    // Imprime os dados da Escola
    public void getDados() {
        System.out.println("====================================");
        System.out.println("ESCOLA: " + nome);
        System.out.println("CPF/CNPJ Responsável: " + cpf);
        
        System.out.println("\n--- ENDEREÇO ---");
        if (endereco != null) {
            endereco.getDados();
        } else {
            System.out.println("Endereço não cadastrado.");
        }

        System.out.println("\n--- DEPARTAMENTOS (" + numDepartamentos + ") ---");
        for (int i = 0; i < numDepartamentos; i++) {
            System.out.print("- ");
            departamentos[i].getDados();
        }

        System.out.println("\n--- ALUNOS MATRICULADOS (" + numDiscentes + ") ---");
        for (int i = 0; i < numDiscentes; i++) {
            System.out.println((i + 1) + ". " + discentes[i].getNome());
        }
        System.out.println("====================================");
    }
}