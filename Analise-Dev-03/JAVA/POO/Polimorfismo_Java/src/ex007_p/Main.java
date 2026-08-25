package ex007_p;

// Interface para Intrumento Musical
interface InstrumentoMusical {
    void tocar();
}


// Classe Violão
class Violao implements InstrumentoMusical {
    public void tocar() {
        System.out.println("Tocando a violão");
    }
}


// Classe Flauta
class Flauta implements InstrumentoMusical {
    public void tocar() {
        System.out.println("Tocando a flauta");
    }
}


// Classe Main
public class Main {
    public static void main(String[] args) {
        InstrumentoMusical violao = new Violao();
        InstrumentoMusical flauta = new Flauta();

        violao.tocar();
        flauta.tocar();
    }
}