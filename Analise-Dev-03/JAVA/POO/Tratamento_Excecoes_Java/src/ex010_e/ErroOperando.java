package ex010_e;

public class ErroOperando extends RuntimeException { 
    ErroOperando(String msg_erro) { 
        super(msg_erro); 
    }     

    ErroOperando(Throwable causa) { 
        super(causa); 
    }         

    @Override 
    public String toString() { 
        return "Operando inválido: " + this.getMessage(); 
    } 
}