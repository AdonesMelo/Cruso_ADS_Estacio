package ex001.PctBravo;

class Externa {
    private String id;
    public Externa ( ) {
        id = "PctBravo.Externa";
        System.out.println( "PctBravo.Externa instanciada." );
    }
    public String getId () {
       return id;
    }
    class Interna {  
        public Interna ( ) {
        id = "PctBravo.Externa.Interna";
        System.out.println( "PctBravo.Externa.Interna instanciada." );
        }
        public String getId () {
            return id;
        }
    }
}
public class Base extends Externa.Interna {
    private String id;
    public Base ( ) {
        new Externa().super();
        id="PctBravo.Base";
        System.out.println( "PctBravo.Base instanciada." );
    }
}