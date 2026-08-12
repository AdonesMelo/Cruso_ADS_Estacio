package ex001.PctBravo2;

public class Externa {
    private String id;
    public Externa ( ) {
        id = "PctBravo.Externa";
        System.out.println( "PctBravo.Externa instanciada." );
    }
    public String getId () {
       return id;
    }
    protected class Interna {  
        public Interna ( ) {
            id = "PctBravo.Externa.Interna";
            System.out.println( "PctBravo.Externa.Interna instanciada." );
        }
        public String getId () {
            return id;
        }
    }
}