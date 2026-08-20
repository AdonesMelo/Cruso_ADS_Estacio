package ex001;

public class Juridica extends Pessoa {
    // Atributos
    private String cnpj;

    // Métodos construtor
    public Juridica(int identificador, String cnpj) {
        super(identificador);
        this.cnpj = cnpj;
    }

    // Métodos abstratos
    @Override
    public void atualizarID() {
        identificador += 2;
    }

    // getters
    public String getCnpj() {
        return cnpj;
    }  
}
