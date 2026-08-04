package ex004;

import java.util.Calendar;

public class Empregado extends Pessoa {
    private String matricula;
    private Calendar dataAdmissao, dataDemissao;

    public Empregado(String nome, Calendar dataNascimento, long cpf, Endereco endereco) {
        super(nome, dataNascimento, cpf, endereco);
        this.matricula = gerarMatricula();
        this.dataAdmissao = Calendar.getInstance();
    }

    public void demitirEmpregado() {
        dataDemissao = Calendar.getInstance();
    }

    protected String gerarMatricula() {
        return "MAT-" + System.currentTimeMillis();
    }

    protected String recuperarMatricula() {
        return this.matricula;
    }

    public void setDataAdmissao(Calendar dataAdmissao) {
        this.dataAdmissao = dataAdmissao;
    }

    public void setDataDemissao(Calendar dataDemissao) {
        this.dataDemissao = dataDemissao;
    }

    public Calendar getDataAdmissao() {
        return dataAdmissao;
    }

    public Calendar getDataDemissao() {
        return dataDemissao;
    }
}
