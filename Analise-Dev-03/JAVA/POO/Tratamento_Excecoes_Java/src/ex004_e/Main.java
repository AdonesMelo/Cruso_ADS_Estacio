package ex004_e;

// Exceções Personalizadas
class ExcecaoPersonalizadaDivisaPorZero extends Exception {
    public ExcecaoPersonalizadaDivisaPorZero(String mensagem) {
        super(mensagem);
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            int resultado = divisao(10, 0);
            System.out.println("Resultado: " + resultado);
        } catch (ExcecaoPersonalizadaDivisaPorZero e) {
            System.out.println("ERRO: " + e.getMessage());
        }
    }

    // Método que lança exceção personalizada
    public static int divisao(int dividendo, int divisor) throws ExcecaoPersonalizadaDivisaPorZero {
        if (divisor == 0) {
            throw new ExcecaoPersonalizadaDivisaPorZero("Divisor não pode ser zero");
        }
        return dividendo / divisor;
    }
}
