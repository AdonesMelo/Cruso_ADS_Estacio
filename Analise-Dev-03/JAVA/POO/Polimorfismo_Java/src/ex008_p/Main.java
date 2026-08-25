package ex008_p;

import java.util.ArrayList;
import java.util.List;

// Interface para Intrumento Musical
interface InstrumentoMusical {
    void tocar();
    String getNome();
}


// Classe Violão
class Violao implements InstrumentoMusical {
    @Override
    public void tocar() {
        System.out.println("Tocando a violão");
    }

    @Override
    public String getNome() {
        return "Violao";
    }
}


// Classe Flauta
class Flauta implements InstrumentoMusical {
    @Override
    public void tocar() {
        System.out.println("Tocando a flauta");
    }

    @Override
    public String getNome() {
        return "Flauta";
    }
}


// Classe Main
public class Main {
    public static void main(String[] args) {
        List<InstrumentoMusical> instrumentos = new ArrayList<>();
        instrumentos.add(new Violao());
        instrumentos.add(new Flauta());

        for (InstrumentoMusical instrumento : instrumentos) {
            instrumento.tocar();
        }

        buscarInstrumento(instrumentos, "Violao");
    }

    private static void buscarInstrumento(List<InstrumentoMusical> instrumentos, String nome) {
        for (InstrumentoMusical instrumento : instrumentos) {
            if (instrumento.getNome().equals(nome)) {
                System.out.println("Encontrado: " + instrumento.getNome());
                return;
            }
        }
        System.out.println("Instrumento não encontrado" + nome);
    }
}