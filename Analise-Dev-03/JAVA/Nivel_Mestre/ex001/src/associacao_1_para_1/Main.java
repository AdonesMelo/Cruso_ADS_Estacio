package associacao_1_para_1;

public class Main {
    public static void main(String[] args) {
        Curso c1 = new Curso("Curso de Java");
        Curso c2 = new Curso("Curso de C#");
        Curso c3 = new Curso("Curso de Python");

        Aluno a1 = new Aluno("João", c1);
        Aluno a2 = new Aluno("Maria", c2);
        Aluno a3 = new Aluno("Pedro", c3);

        System.out.println(a1.getDados());
        System.out.println(a2.getDados());
        System.out.println(a3.getDados());
    }   
}
