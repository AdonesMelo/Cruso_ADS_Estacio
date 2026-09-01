package ex008_e;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


// Exemplo de tratamento de exceção
public class Main {
    public static void main (String [] args) {
        BufferedReader leitor = null;

        try {
            // Abrir arquivo
            leitor = new BufferedReader(new FileReader("entrada.txt"));

            // Leitura do conteudo do arquivo
            String linha;
            while ((linha = leitor.readLine()) != null) {
                // Processar cada linha do leitor
                System.out.println(linha);
            }
        } catch (IOException e) {
            // Tratar uma exceção IO
            System.out.println("Ocorreu uma erro durante a leitura do arquivo: " + e.getMessage());
        } finally {
            // Fechar o arquivo no bloco finally
            try {
                if (leitor != null) {
                    leitor.close();
                }
            } catch (IOException e) {
                System.out.println("Erro ao fechar o arquivo: " + e.getMessage());
            }
        }
    }
}
