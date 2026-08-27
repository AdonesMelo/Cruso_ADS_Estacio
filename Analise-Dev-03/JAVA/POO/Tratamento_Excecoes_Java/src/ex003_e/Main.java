package ex003_e;

// Tratamento de exceções explícitas
class TratamentoExcecao {
    public static int getElemento(int indice, int[] vetor) {
        try {
            if (indice < 0 || indice > 3) 
            throw new IllegalArgumentException();
        } catch (Exception e) {
            System.out.println("ERRO: Índice fora dos limites do vetor");
        }
        return vetor[indice];
    }
}
            

public class Main {
    public static void main(String[] args) {
        int[] vetor = {10, 20, 30, 40};
        int x = TratamentoExcecao.getElemento(5, vetor);
        System.out.println("O elemento no indice 5 é: " + x);
    }
}
