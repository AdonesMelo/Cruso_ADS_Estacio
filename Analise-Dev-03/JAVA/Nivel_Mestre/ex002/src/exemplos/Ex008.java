package exemplos;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

// Contando elementos por categoria

class Tarefa {
    private String descricao;
    private String prioridade;

    public Tarefa(String descricao, String prioridade) {
        this.descricao = descricao;
        this.prioridade = prioridade;
    }

    public String getDescricao() {
        return descricao;
    }

    public String getPrioridade() {
        return prioridade;
    }
}


public class Ex008 {
    public static void main(String[] args) {

    List<Tarefa> tarefas = Arrays.asList(
        new Tarefa("Implementar login", "Alta"),
        new Tarefa("Criar banco de dados", "Média"),
        new Tarefa("Testar API", "Alta"),
        new Tarefa("Documentar código", "Baixa")
    );

    // contagem por prioridade
    Map<String, Long> contagemPorPrioridade = tarefas.stream()
        .collect(Collectors.groupingBy(
            Tarefa::getPrioridade,
            Collectors.counting()
        ));
    
    contagemPorPrioridade.forEach((prioridade, total) ->
        System.out.println(prioridade + ": " + total));
    }
}
