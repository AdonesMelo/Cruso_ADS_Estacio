package ex009_e;

import java.util.ArrayList;
import java.util.List;


class nomeInvalidoExcecao extends Exception {
    public nomeInvalidoExcecao(String mensagem, Throwable causa) {
        super(mensagem, causa);
    }
}


public class ExemploEncadementoExcecao {
    public static void main(String[] args) {
        try {
            List<String> listaNomes = new ArrayList<>();
            addNome(listaNomes, null);
        } catch (nomeInvalidoExcecao e) {
            System.out.println("Um erro ocorreu: " + e.getMessage());
            System.out.println("Causa raiz: " + e.getCause().getMessage());
        }
    }

    public static void addNome(List<String> listaNomes, String nome) throws nomeInvalidoExcecao {
        try {
            if (nome == null || nome.isBlank()) {
                    throw new IllegalArgumentException("O nome não pode ser nulo ou vazio");
                }
                listaNomes.add(nome);
            } catch (IllegalArgumentException e) {
                throw new nomeInvalidoExcecao("Foi detectado um nome vazio ou nulo", e);
            }
        }
}