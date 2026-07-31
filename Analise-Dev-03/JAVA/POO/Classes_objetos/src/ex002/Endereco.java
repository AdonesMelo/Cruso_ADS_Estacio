package ex002;

public class Endereco {
    // Atributos
    private String logradouro; // Ex: Rua, Avenida
    private String numero;
    private String bairro;
    private String cidade;
    private String uf;        // Estado (Ex: SP, RJ, MG)
    private String cep;

    // Construtor completo
    public Endereco(String logradouro, String numero, String bairro, String cidade, String uf, String cep) {
        this.logradouro = logradouro;
        this.numero = numero;
        this.bairro = bairro;
        this.cidade = cidade;
        this.uf = uf;
        this.cep = cep;
    }

    // Getters e Setters
    public String getLogradouro() {
        return logradouro;
    }

    public void setLogradouro(String logradouro) {
        this.logradouro = logradouro;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getUf() {
        return uf;
    }

    public void setUf(String uf) {
        this.uf = uf;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    // Método de impressão chamado pela classe Escola
    public void getDados() {
        System.out.println(logradouro + ", Nº " + numero + " - " + bairro);
        System.out.println("Cidade: " + cidade + "/" + uf + " - CEP: " + cep);
    }
}