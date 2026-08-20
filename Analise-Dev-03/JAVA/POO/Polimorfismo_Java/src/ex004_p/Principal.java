/*
Um estudante, desejando aprofundar seu conhecimento sobre polimorfismo, escreveu os códigos a seguir:
*/

package ex004_p;

class Base {
    public String imprimir ( ) {
        return "Base";
    }
}


class Derivada1 extends Base{
    public String imprimir ( ) {
        return "Derivada1";
    }
}


class Derivada2 extends Derivada1 {
    public String imprimir ( ) {
        return "Derivada2";
    }
}


public class Principal {
    public static void main ( String args [ ] ) {
        //____ [] ref = new ____ [3];
        Base ref [ ] = new Base [ 3 ];
        ref [ 0 ] = new Base ();
        ref [ 1 ] = new Derivada1 ();
        ref [ 2 ] = new Derivada2 ();
        for ( int i = 0 ; i <= 2 ; i++ )
            System.out.println ( ref[i].imprimir() );
    }
}

/*
Ele deseja que a saída seja a mostrada a seguir:
Base
Derivada1
Derivada2
*/

/*
Para que o programa exiba o comportamento polimórfico que o estudante espera, 
os espaços da linha 30 do código da classe Principal devem ser, respectivamente
*/
// Base ref [ ] = new Base [ 3 ];
