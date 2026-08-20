package ex001;

public class Fisica extends Pessoa {
    // Atributos
    private String cpf;

    // Métodos construtor
    public Fisica(int identificador, String cpf) {
        super(identificador);
        this.cpf = cpf;
    }

    @Override
    public void atualizarID() {
        identificador += 1;
    }

    // getters
    public String getCpf() {
        return cpf;
    }
}