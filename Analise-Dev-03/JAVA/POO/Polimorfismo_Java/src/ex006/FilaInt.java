package ex006;

import java.util.LinkedList;
import java.util.Queue;

public class FilaInt implements EstruturaDeDados {
    private Queue<Integer> fila  = new LinkedList<>();

    @Override
    public void adicionar(int valor) {
        fila.offer(valor);
    }

    @Override
    public void remover() {
        if (!fila.isEmpty()) {
            fila.poll();
        } else {
            System.out.println("Fila vazia");
        }
    }

    @Override
    public void imprimir() {
        System.out.println("Conteúdo da fila: " + fila);
    }
}
