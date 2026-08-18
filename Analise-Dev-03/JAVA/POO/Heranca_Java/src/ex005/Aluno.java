package ex005;

public class Aluno extends PessoaFisica {
    // atributos
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
    public boolean equals(Object obj) {
        if ((this.CPF == ((Aluno)obj).CPF) && (this.matricula == ((Aluno)obj).matricula))
            return true;
        else 
            return false;
    }

    @Override
    public int hashCode() {
        return (this.CPF + this.matricula).hashCode();
    }

    @Override
    public String toString() {
        return String.format("Classe: <%s> | hasCode: <%s> | Aluno", 
        getClass().getName(),
        Integer.toHexString(this.hashCode()).toUpperCase());
    }
}
