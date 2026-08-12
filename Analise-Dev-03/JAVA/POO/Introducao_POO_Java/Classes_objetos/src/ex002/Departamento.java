package ex002;

public class Departamento {
    // Atributos
    private String nome;
    private String codigo;

    // Construtor principal (recebe o nome do departamento)
    public Departamento(String nome) {
        this.nome = nome;
        this.codigo = "DEP-IND"; // Código padrão caso não seja fornecido
    }

    // Construtor com código/sigla
    public Departamento(String nome, String codigo) {
        this.nome = nome;
        this.codigo = codigo;
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    // Método de impressão chamado pela classe Escola
    public void getDados() {
        System.out.println("Departamento: " + nome + " (Código: " + codigo + ")");
    }
}