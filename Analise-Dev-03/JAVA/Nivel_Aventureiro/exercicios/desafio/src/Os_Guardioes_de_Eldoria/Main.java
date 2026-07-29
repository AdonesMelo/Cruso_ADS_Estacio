package Os_Guardioes_de_Eldoria;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Criando uma instância de Guerreiro e Mago
        Guerreiro thor = new Guerreiro("Thor", 5, 80, 12.5, 10);
        Mago merlin = new Mago("Merlin", 4, 90, 10.5, 10.5);

        // exibindo status
        thor.exibirStatus();
        merlin.exibirStatus();

        // Usando habilidade especial
        thor.usarHabilidadeEspecial();
        merlin.usarHabilidadeEspecial();


        System.out.println("\n=== Polimorfismo ===");
        // Criando uma lista de personagens
        List<Personagem> herois = new ArrayList<>();
        herois.add(thor);
        herois.add(merlin);

        // Criando outros personagens
        herois.add(new Guerreiro("Loki", 5, 90, 14.5, 9.5));
        herois.add(new Mago("Dr. Strange", 4, 95, 13.5, 9.8));

        // Exibindo status de todos os personagens
        for (Personagem p : herois) {
            p.exibirStatus();
            p.usarHabilidadeEspecial();
            System.out.println("----------------------------\n");
        }
    }  
}
