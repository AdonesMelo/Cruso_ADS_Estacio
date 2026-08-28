package ex005_e;

import java.util.Scanner;

// Exceção personalizada
class SenhaInvalidaExcecao extends Exception {
    public SenhaInvalidaExcecao(String mensagem) {
        super(mensagem);
    }
}


// Clase Main
public class ExemploExcecao {
    public static void main(String[] args) {
        // Cria um objeto Scanner para ler a senha do usuário
        Scanner usuarioSenha = new Scanner(System.in);

        // Loop infinito para ler a senha do usuário
        while (true) {
            System.out.println("Digite sua senha:");
            String senha = usuarioSenha.next();

            try {
                validarSenha(senha);
                System.out.println("Senha válida!");
                break;
            } catch (SenhaInvalidaExcecao e) {
                System.out.println("ERRO: " + e.getMessage());
            }
        }

        // Fecha Scanner
        usuarioSenha.close();
    }

    // Método que valida a senha do usuário
    public static void validarSenha(String senha) throws SenhaInvalidaExcecao {
        if (senha.length() < 5) {
            throw new SenhaInvalidaExcecao("A senha deve ter no mínimo 5 caracteres");
        }
        if (!senha.matches(".*\\d.*")) {
            throw new SenhaInvalidaExcecao("A senha deve conter, no mínimo, 1 dígito");
        }
    }   
}
