package ex005_p;

public class CientistaDeDados implements CienciaDeDados {
    @Override
    public void analisarDados() {
        System.out.println("O Cientista de dados está analisando dados");
    }

    @Override
    public void visualizarDados() {
        System.out.println("O Cientista de dados está visualizando dados");
    }
}
