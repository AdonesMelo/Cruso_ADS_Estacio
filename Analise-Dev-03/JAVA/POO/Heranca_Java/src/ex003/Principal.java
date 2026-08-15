package ex003;

public class Principal {
    private static Pessoa grupo [];
    public static void main (String args[]) {
        grupo = new Pessoa [2];
        grupo [0] = new Fisica ("Maria" , "da Conceição" , "Brasileira" , "365.586.875-45" , null , "12.12.1990" , "Av. Brasil, 1000");
        grupo [1] = new Pessoa ("Escola Novo Mundo Ltda", "Brasil", "Brasileira", "43.186.666/0026-32", null, 0, "Av. Brasil, 1000");

        for ( int i = 0 ; i < grupo.length ; i++ ) {
            System.out.println ( "grupo [" + i + "]: " + grupo [i].toString() );
        }   
    }
}