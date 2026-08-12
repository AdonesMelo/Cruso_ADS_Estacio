package ex001.PctAlfa;

import ex001.PctBravo.*;

class Execucao {
    private String id;
    public Execucao ( ) {
        id="PctAlfa.Execucao";
        System.out.println( "PctAlfa.Execucao instanciada." );
    }
}
public class Principal {
    static Execucao ex;
    static Base bs;
    public static void main(String[] args) {
        ex = new Execucao ();
        bs = new Base ();
        System.out.println ( bs.getId() );
    }
}

/*
Como é mandatório em Java, todas as classes públicas devem estar definidas em um arquivo de mesmo nome. 
No nosso exemplo, são públicas as classes Principal, Base e Estendida. Além disso, para o caso em questão, 
teremos dois pacotes: PctAlfa e PctBravo. Assim, você deve inicialmente criar um projeto em sua IDE e, 
posteriormente, criar ambos os pacotes. Lembre-se de importar em PctAlfa o pacote PctBravo.
*/