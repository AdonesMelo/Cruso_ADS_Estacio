package ordenacao_Comparator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        // Ordenação por preco
        Comparator<Produto> porPreco = new Comparator<>() {
            @Override
            public int compare(Produto p1, Produto p2) {
                return Double.compare(p1.getPreco(), p2.getPreco());
            }
        };

        List<Produto> produtos = new ArrayList<>();

        produtos.add(new Produto("Notebook", 3000));
        produtos.add(new Produto("Teclado", 120));
        produtos.add(new Produto("Monitor", 900));

        Collections.sort(produtos, porPreco);
        System.out.println("Produtos ordenados por preco:");
        System.out.println(produtos);
        // [Teclado - R$ 120.0, Monitor - R$ 900.0, Notebook - R$ 3000.0]

        // Ordenação com API de Streams
        // Ordenação por nome
        List<Produto> ordenados = produtos.stream()
        .sorted(Comparator.comparing(Produto::getNome))
        .collect(Collectors.toList());

        System.out.println("\nOrdenados por nome:");
        System.out.println(ordenados);

        // ou por multiplos critérios
        List<Produto> ordenadosPorNomeEPreco = produtos.stream()
            .sorted(Comparator.comparing(Produto::getNome)
                            .thenComparing(Produto::getPreco))
            .collect(Collectors.toList());

        System.out.println("\nOrdenados por nome e preco:");
        System.out.println(ordenadosPorNomeEPreco);
    }
}
