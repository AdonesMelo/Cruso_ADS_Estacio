package ex005;

import java.util.Calendar;
import java.util.UUID;

public class Diretor extends Empregado {
    // Construtor
    public Diretor(String nome, Calendar data_nascimento, long CPF, Endereco endereco) {
        super(nome, data_nascimento, CPF, endereco);
        gerarMatricula(); // já gera a matrícula ao criar o diretor
    }

    // Sobrescrevendo método para gerar matrícula exclusiva
    @Override
    protected String gerarMatricula() {
        this.matricula = "E-" + UUID.randomUUID().toString();
        return this.matricula;
    }

    protected void alterarMatricula(){
            gerarMatricula();
    }
    protected void alterarMatricula(String matricula){
            this.matricula = matricula;
    }
}

