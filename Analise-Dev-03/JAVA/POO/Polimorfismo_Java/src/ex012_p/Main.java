package ex012_p;

/*
Ao tentar compilá-lo, o compilador informou que havia erro. 
Sabendo que o problema está nos trechos código mostrados, 
assinale a única opção que apresenta a solução correta para sanar o problema 
e permitir que o programa seja compilado e funcione como previsto.
*/

import java.util.Random;

class IdUnico extends Random {
    // private Float seed; // Não pode ser privado pois é usado em outra classe
    protected Float seed;   
    public IdUnico ( ) {
        seed = nextFloat ();
    }

    // private interface iCodigo { // Não pode ser privado pois é usado em outra classe
    protected interface iCodigo {
        public void imprimeCod ();
    }
}


class Concreta extends IdUnico {
        public void imprimeCod () {
            System.out.println( seed );
    }
}      
public class Main {
        public static void main(String[] args) {
            Concreta conc = new Concreta ();
        conc.imprimeCod();
    }
}
