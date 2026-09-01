package ex007_e;

import java.io.IOException;


class AbrirArquivoExcecao extends Exception {
    public AbrirArquivoExcecao(String mensagem, Throwable causa) {
        super(mensagem, causa);
    }
}

// Encadeamento de exceções
public class Main {
    public static void main(String[] args) {
        try {
            abrirAquivo();
        } catch (AbrirArquivoExcecao e) {
            System.out.println("Um erro ocorreu na tentativa de abrir aquivo: " + e.getMessage());
            System.out.println("Causa raiz do erro: " + e.getCause().getMessage());
        }
    }

    public static void abrirAquivo() throws AbrirArquivoExcecao {
        try {
            // Simula a abertura de um arquivo
            System.out.println("Abrindo aquivo...");
            throw new IOException("impossivel abrir aquivo");
        } catch (IOException e) {
            // Envolvendo a exceção gerada em uma exceção personalizada
            throw new AbrirArquivoExcecao("Ocorreu um erro ao tentar abrir aquivo", e);
        }
    }
}