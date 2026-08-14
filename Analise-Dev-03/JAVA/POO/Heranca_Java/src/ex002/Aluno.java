package ex002;

public class Aluno extends PessoaFisica {
    String matricula;

    public Aluno(String nome, String CPF, String matricula) {
        super(nome, CPF);
        this.matricula = matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getMatricula() {
        return matricula;
    }

    @Override
    public String toString() {
        return String.format("ObjID: %s => Nome: %s | CPF: %s | Matricula: %s\n",
        Integer.toHexString(hashCode()), nome, CPF, matricula);
    }
}
