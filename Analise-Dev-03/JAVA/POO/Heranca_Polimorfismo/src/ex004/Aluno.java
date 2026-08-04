package ex004;

import java.util.Calendar;

public class Aluno extends Pessoa {
    private String matricula;

    public Aluno(String nome, Calendar dataNascimento, long cpf, Endereco endereco) {
        super(nome, dataNascimento, cpf, endereco);
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getMatricula() {
        return matricula;
    }
}
