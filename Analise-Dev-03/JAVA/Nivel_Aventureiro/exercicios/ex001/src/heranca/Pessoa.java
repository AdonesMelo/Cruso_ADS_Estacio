package heranca;

public class Pessoa {
    public String nome; // qualquer classe pode acessar
    private String cpf; // só a própria classe acessa
    protected int idade; // subclasses e mesmo pacote acessam

    public Pessoa(String nome, String cpf, int idade) {
        this.nome = nome;
        this.cpf = cpf;
        this.idade = idade;
    }
    
    // Getter para acessar atributo privado
    public String getCpf() {
        return cpf;
    }
}