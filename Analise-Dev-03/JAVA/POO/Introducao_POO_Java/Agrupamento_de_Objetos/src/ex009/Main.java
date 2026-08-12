package ex009;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> lista_numeros = new ArrayList<>();

        // Adicionando elementos
        lista_numeros.add(10);
        lista_numeros.add(20);
        lista_numeros.add(30);
        lista_numeros.add(40);
        lista_numeros.add(50);

        // acessar elementos da lista
        System.out.println("Lista de numeros:");
        for (int i = 0; i < lista_numeros.size(); i++) {
            System.out.println("Lista[" + i + "] = " + lista_numeros.get(i));
        }

        // for-each
        // for(int numero : lista_numeros) {
        //     int indice = lista_numeros.indexOf(numero);
        //     System.out.println("Lista[" + indice + "] = " + numero);
        // }

        // remover elementos da lista específico
        System.out.println("\nRemovendo elemento da lista...");
        lista_numeros.remove(1); // Remove o elemento da posição 2 ArrayList

        // Alterando um elemento da lista
        int x = 57;
        System.out.println("\nAlterando elemento da lista...");
        lista_numeros.set(0, x); // Colocando o 57 no indice 0

        // Verificando se o ArrayList contem um numero específico
        int y = 100;
        String contem_elemento = lista_numeros.contains(y) ? "Sim" : "Não";
        System.out.println("\nContem o numero " + y + " na lista? " + contem_elemento);

        // Alterando a lista com um laço for-each
        int z = 0;
        System.out.println("\nOs elementos da lista são:");
        for (int numero : lista_numeros) {
            System.out.println("Lista[" + z + "] = " + numero);
            z++;
        }

        // Limpando o ArrayList de todos os elementos
        System.out.println("\nLimpando a lista...");
        lista_numeros.clear();


        // Verificando se a lista está vazia
        String vazia = lista_numeros.isEmpty() ? "Sim" : "Não";
        System.out.println("\nLista esta vazia? " + vazia);
    }
}
