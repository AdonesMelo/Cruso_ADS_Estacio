package ex010_p;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

// Interface funcional que define um metodo para realizar uma ação
interface Acao {
    void executar();
}

// Classe que implementa a interface
class AcaoImpressao implements Acao {
    private String mensagem;

    public AcaoImpressao(String mensagem) {
        this.mensagem = mensagem;
    }

    @Override
    public void executar() {
        System.out.println(mensagem);
    }
}    

// Classe Main
public class Main {
    public static void main(String[] args) {
        List<Acao> listaAcoes = new ArrayList<>();

        // Adicionar ações a lista
        listaAcoes.add(new AcaoImpressao("Olá mundo!"));
        listaAcoes.add(new AcaoImpressao("Isso é uma exemplo de programação funcional!"));
        listaAcoes.add(new AcaoImpressao("Este programa é feito em Java!"));

        // Usar programação funcional para executar as ações
        System.out.println("Programação funcional para executar as ações:");
        listaAcoes.forEach(Acao::executar);
        System.out.println();

        // ou usar lambdas
        System.out.println("Lambdas para executar as ações:");
        Consumer<Acao> executor = Acao::executar;
        listaAcoes.forEach(executor);
    }
}
