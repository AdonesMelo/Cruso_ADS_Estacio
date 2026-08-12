package ex004;

import java.util.Calendar;

public class Pessoa {
    private String nome;
    private int idade;
    private Calendar dataNascimento;
    private long cpf;
    private Endereco endereco;

    public Pessoa(String nome, Calendar dataNascimento, long cpf, Endereco endereco) {
        this.nome = nome;
        this.dataNascimento = dataNascimento;
        this.cpf = cpf;
        this.endereco = endereco;
        atualizarIdade();
    }

    protected void atualizarNome(String nome) {
        this.nome = nome;
    }

    protected String recuperarNome() {
        return this.nome;
    }

    protected void atualizarIdade() {
        this.idade = calcularIdade();
    }

    protected int recuperarIdade() {
        return this.idade;
    }

    protected void atualizarCPF(long cpf) {
        this.cpf = cpf;
    }

    protected long recuperarCPF() {
        return this.cpf;
    }

    protected void atualizarEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    protected Endereco recuperarEndereco() {
        return this.endereco;
    }

    private int calcularIdade() {
        Calendar hoje = Calendar.getInstance();
        int lapso = hoje.get(Calendar.YEAR) - dataNascimento.get(Calendar.YEAR);

        if (dataNascimento.get(Calendar.MONTH) > hoje.get(Calendar.MONTH) ||
            (dataNascimento.get(Calendar.MONTH) == hoje.get(Calendar.MONTH) &&
             dataNascimento.get(Calendar.DAY_OF_MONTH) > hoje.get(Calendar.DAY_OF_MONTH))) {
            lapso--;
        }
        return lapso;
    }
}
