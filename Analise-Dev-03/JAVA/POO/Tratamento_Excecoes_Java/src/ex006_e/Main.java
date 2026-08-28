package ex006_e;

import java.util.Scanner;
//import java.io.IOException;

class Fibonacci {
    // Atributos
    private static int conta_chamada = 0; // Contador de chamadas recursivas

    public double calcularFibonacci(double numero) {
        // Incrementa contador de chamadas recursivas
        conta_chamada++;

        System.out.println("Chamada recursiva nr: " + conta_chamada);

        if (numero != 2 && numero != 1) {
            return calcularFibonacci(numero - 1) + calcularFibonacci(numero - 2);
        } else {
            return 1;
        }
    }
}


public class Main {
    private static Fibonacci fib;
    private static Scanner entrada;

    public static void main(String[] args) {
        double numero = 0;
        entrada = new Scanner(System.in);
        fib = new Fibonacci();

        do {
            System.out.println("Entre com um número não negativo ou -1 para sair:");
            numero = entrada.nextDouble();
            if (numero == -1) {
                System.exit(0);
            }
            System.out.println("O " + numero + "-ésimo termo de fibonacci é: " + fib.calcularFibonacci(numero));
        } while (numero >= 0);

        // Fecha Scanner
        entrada.close();
    }
}
