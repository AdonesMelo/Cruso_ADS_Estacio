package ex004;

import java.util.Calendar;

public class Principal {
    //Atributos
    private static int I1 , I2 , I3;
    private static String S1 , S2 , S3;
    private static Fisica p1 , p2;
    private static Pessoa p3;
    
    //Métodos
    public static void main (String args[]) {
        I1 = 1;
        I2 = 2;
        I3 = 1;
        S1 = "a";
        S2 = "b";
        S3 = "a";
        Calendar data_nasc = Calendar.getInstance();
        data_nasc.set(1980, 10, 23);
        p1 = new Fisica ( "João", null, "Brasileiro", "123456789", data_nasc, "12.12.1990", "Av. Brasil, 1000" );
        p2 = new Fisica ( "João", null, "Brasileiro", "123456789", data_nasc, "12.12.1990", "Av. Brasil, 1000" );
        p3 = new Pessoa ( "Classe Pessoa", null, "Brasil", null, null, 0, "Rio de Janeiro" );
        compararEquals ( p1 , p2 , p3 );
        compararEquals ( I1, I2, I3 );
        compararEquals ( S1, S2, S3 );

        System.out.println(p1.equals(p2));       // true (se equals comparar nome)
        System.out.println(p1.hashCode() == p2.hashCode()); // true (mesmo nome → mesmo hash)

    if ( p1 instanceof Pessoa )
       System.out.println("p1 é instância do tipo Pessoa.");
    else
       System.out.println("p1 não é instância do tipo Pessoa.");
    if ( p2 instanceof Pessoa )
       System.out.println("p2 é instância do tipo Pessoa.");
    else
       System.out.println("p2 não é instância do tipo Pessoa.");
    if ( p3 instanceof Pessoa )
       System.out.println("p3 é instância do tipo Pessoa.");
    else
       System.out.println("p3 não é instância do tipo Pessoa.");
    if ( p3 instanceof Fisica )
      System.out.println("p3 é instância do tipo Fisica.");
    else
         System.out.println("p3 não é instância do tipo Fisica.");
    }
    
    private static void compararEquals ( Object o1 , Object o2 , Object o3 ){
            System.out.println("Uso de EQUALS para comparar " + o1.getClass().getName());
            if ( o1.equals( o2 ) )
                System.out.println("o1 == o2");
            else
                System.out.println("o1 != o2");
            if ( o1.equals(o3) )
                System.out.println("o1 == o3");
            else
                System.out.println("o1 != o3");
        }
    }