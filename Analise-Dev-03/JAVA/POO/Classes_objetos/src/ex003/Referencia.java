package ex003;

public class Referencia {
    // Atributos
    private Aluno a1, a2;

    // Metodos
    public Referencia () {
        a1 = new Aluno ("João", 20);
        a2 = new Aluno ("Maria", 21);

        System.out.println ("Aluno 1: " + a1.recuperaNome());
        System.out.println ("Aluno 2: " + a2.recuperaNome());

        a2 = a1;
        a2.definirNome ("Ana");
        System.out.println ("Aluno 1: " + a1.recuperaNome());

        manipulaAluno (a1);
        System.out.println ("Aluno 1: " + a1.recuperaNome());
    }

    public void manipulaAluno (Aluno a) {
        a.definirNome ("Pedro");
    }

    public static void main (String[] args) {
        new Referencia();
        System.out.println ("Programa finalizado com sucesso!");
    }  
}
