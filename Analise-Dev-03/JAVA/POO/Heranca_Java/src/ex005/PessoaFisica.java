package ex005;

public class PessoaFisica {
    // atributos
    protected String nome;
    protected String CPF;

    // Métodos
    public PessoaFisica(String nome, String CPF) {
        this.nome = nome;
        setCPF(CPF);
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setCPF(String CPF) {
        if (validateCPF(CPF)) {
            this.CPF = CPF;
        }
        else {
            System.out.println("CPF inválido");
        }
    }

    public String getCPF() {
        return CPF;
    }

    @Override
    public boolean equals(Object obj) {
        if (this.CPF == ((PessoaFisica)obj).CPF)
            return true;
        else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return this.CPF.hashCode();
    }

    @Override
    public String toString() {
        return String.format("Classe: <%s> | hasCode: <%s> | PessoaFisica", 
        getClass().getName(),
        Integer.toHexString(this.hashCode()).toUpperCase());
    }

    private boolean validateCPF(String CPF) {
        // Verifica sequencia de digitos são iguais e tamanho(11 digitos)
        if (! (CPF.chars().allMatch(Character::isDigit))) {
            System.out.println("CPF possui carecteres não numéricos");
            return false;
        }
        else if ((CPF.length() != 11) || CPF.matches("[0]{11}|[1]{11}|[2]{11}|[3]{11}|[4]{11}|[5]{11}|[6]{11}|[7]{11}|[8]{11}|[9]{11}"))
            return false;
        return true;
    }
}
