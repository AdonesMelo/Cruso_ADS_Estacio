package ex002_e;

// Tratamento de exceções explícitas
public class Main {
    public static void main(String[] args) {
        int quociente, dividendo =10, divisor = 2;
        try {
            if (divisor == 0) {
                throw new ArithmeticException("O divisor é zero");
            }
            quociente = dividendo / divisor;
            System.out.println("Quociente: " + quociente);
        } catch (ArithmeticException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
