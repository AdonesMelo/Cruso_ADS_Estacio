package ex005_p;

public class Main {
    public static void main(String[] args) {
        CienciaDeDados profissional01 = new AnalistaDeDados();
        CienciaDeDados profissional02 = new CientistaDeDados();

        profissional01.analisarDados();
        profissional01.visualizarDados();
        
        profissional02.analisarDados();
        profissional02.visualizarDados();
    }
}
