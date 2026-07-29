package associacao_1_para_muitos;

public class Main {
    public static void main(String[] args) {
        Curso c1 = new Curso("Curso de Java");
        Curso c2 = new Curso("Curso de C#");
        Curso c3 = new Curso("Curso de Python");
        
        Aluno a1 = new Aluno("João");
        Aluno a2 = new Aluno("Maria");
        Aluno a3 = new Aluno("Pedro");

        c1.adicionarAluno(a1);
        c1.adicionarAluno(a2);
        c1.adicionarAluno(a3);

        c2.adicionarAluno(a1);
        c2.adicionarAluno(a2);

        c3.adicionarAluno(a3);
        c3.adicionarAluno(a1);

        System.out.println("Alunos do curso " + c1.getNome() + ":");
        c1.listarAlunos();

        System.out.println("\nAlunos do curso " + c2.getNome() + ":");
        c2.listarAlunos();
        
        System.out.println("\nAlunos do curso " + c3.getNome() + ":");
        c3.listarAlunos();
    }
}
