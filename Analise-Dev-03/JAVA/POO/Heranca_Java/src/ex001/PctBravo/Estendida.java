package ex001.PctBravo;

public class Estendida extends Externa.Interna {
    private String id;
    public Estendida ( ) {
        new Externa().super();
        id="PctBravo.Estendida";
        System.out.println( "PctBravo.Estendida instanciada." );
    }
} 