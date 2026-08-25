package ex006;

public class Main {
    public static void main(String[] args) {
        EstruturaDeDados estrutura = new FilaInt();

        // Inserindo dados na fila
        estrutura.adicionar(1);
        estrutura.adicionar(2);
        estrutura.adicionar(3);

        // Imprimindo dados da fila
        estrutura.imprimir();

        // Removendo dados da fila
        estrutura.remover();

        // Imprimindo dados da fila
        estrutura.imprimir();
    }
}
