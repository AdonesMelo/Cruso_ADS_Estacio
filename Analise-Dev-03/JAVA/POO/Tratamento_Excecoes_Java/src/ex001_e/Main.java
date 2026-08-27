package ex001_e;

class TratamentoExcecao {
    public static int divisao(int a, int b) {
        return a / b;
    }
}


public class Main {
    public static void main(String[] args) {
        try {
            int resultado = TratamentoExcecao.divisao(10, 0);
            System.out.println("Resultado: " + resultado);
        } catch (ArithmeticException e) {
            System.out.println("Erro: Divisão por zero");
        }
    }
}
