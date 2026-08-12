package ex010;

public class Base {
    public static void main(String[] args) {
        int controle = 0;
        int contador = 0;
        int vetor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        // while
        while (controle < 10) {
            System.out.println("Contador: " + controle);
            controle++;
        }

        System.out.println();

        // do-while
        do {
            System.out.println("Controle: " + contador);
            contador++;
        } while (contador < 10);

        System.out.println();

        // for
        for (int i = 0; i < 10; i++) {
            System.out.println("Controle: " + i);
        }

        System.out.println();

        // for-each
        for (int numero : vetor) {
            System.out.println("Numero: " + numero);
        }
    }
}
