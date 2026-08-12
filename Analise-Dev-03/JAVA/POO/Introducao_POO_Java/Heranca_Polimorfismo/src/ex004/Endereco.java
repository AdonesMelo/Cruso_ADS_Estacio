package ex004;

public class Endereco {
    private String pais, uf, cidade, rua, numero, cep, complemento;

    public void definirPais(String pais) { this.pais = pais; }
    public void definirUF(String uf) { this.uf = uf; }
    public void definirCidade(String cidade) { this.cidade = cidade; }
    public void definirRua(String rua) { this.rua = rua; }
    public void definirNumero(String numero) { this.numero = numero; }
    public void definirCEP(String cep) { this.cep = cep; }
    public void definirComplemento(String complemento) { this.complemento = complemento; }

    public void getDados() {
        System.out.println("Rua: " + rua + ", Nº: " + numero + ", " + complemento);
        System.out.println("Cidade: " + cidade + " - " + uf + ", CEP: " + cep);
        System.out.println("País: " + pais);
    }
}
