package ex005_p;

public class AnalistaDeDados implements CienciaDeDados {
    @Override
    public void analisarDados() {
        System.out.println("O Analista de dados está analisando dados");
    }

    @Override
    public void visualizarDados() {
        System.out.println("O Analista de dados está visualizando dados");
    }
}
