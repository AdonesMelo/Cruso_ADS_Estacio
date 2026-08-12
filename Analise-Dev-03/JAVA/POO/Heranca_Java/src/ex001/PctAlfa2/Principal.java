package ex001.PctAlfa2;

import ex001.PctBravo2.*;

class Execucao extends Externa {
    private String id;
    Externa.Interna exint;
    public Execucao ( ) {
        exint = new Externa().new Interna();      
        id="PctAlfa.Execucao";
        System.out.println( "PctAlfa.Execucao instanciada." );
    }
}
public class Principal {
    static Execucao ex;
    public static void main(String[] args) {
        ex = new Execucao ();
        System.out.println ( ex.getId() );
    }
}

/*
Vamos fazer mais uma alteração. Você deve tornar a classe Externa pública. 
Isso significa movê-la para um arquivo de mesmo nome, dentro do pacote PctBravo
*/