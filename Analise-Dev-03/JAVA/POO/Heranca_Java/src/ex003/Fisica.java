package ex003;

import java.util.Calendar;

public class Fisica extends Pessoa {
    // atributos
    protected String CPF;

    // Métodos
    public Fisica(String nome, String naturalidade, String nacionalidade, String identificador, Calendar data_nasicamento, String CPF, String endereco) {
        super(nome, naturalidade, nacionalidade, identificador, data_nasicamento, 0, endereco);
        this.CPF = CPF;
    }
}
