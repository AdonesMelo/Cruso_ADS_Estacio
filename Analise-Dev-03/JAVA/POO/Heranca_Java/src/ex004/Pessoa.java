package ex004;

import java.util.Calendar;

public class Pessoa {
    // atributos
    protected String nome, naturalidade, nacionalidade, identificador;
    private Calendar data_inicio_existencia;
    private int idade;
    private String endereco;

    // Métodos
    public Pessoa(String nome, String naturalidade, String nacionalidade, String identificador, Calendar data_inicio_existencia, int idade, String endereco) {
        this.nome = nome;
        this.naturalidade = naturalidade;
        this.nacionalidade = nacionalidade;
        this.identificador = identificador;
        this.data_inicio_existencia = data_inicio_existencia;
        this.idade = idade;
        this.endereco = endereco;
    }

    // Método toString
    @Override
    public String toString() {
        return "Objeto:" + 
        "\n\t- Classe: " + getClass().getName() + 
        "\n\t- Hast: " + Integer.toHexString(hashCode()) + 
        "\n\t- Nomme: " + nome + "\n\t- Indentificador: " + identificador;
    }

    // Método getters e setters
    public Calendar getData_inicio_existencia() {
        return data_inicio_existencia;
    }

    public void setData_inicio_existencia(Calendar data_inicio_existencia) {
        this.data_inicio_existencia = data_inicio_existencia;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    
    @Override
    public int hashCode() {
        // Se tiver nome definido, usa o hash do nome
        if (this.nome != null) {
            return this.nome.hashCode();
        }
        // Caso contrário, usa o hash padrão da classe Object
        return super.hashCode();
    }
    
}