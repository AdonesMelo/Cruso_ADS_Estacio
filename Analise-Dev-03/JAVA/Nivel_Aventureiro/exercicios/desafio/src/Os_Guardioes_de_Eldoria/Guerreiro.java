package Os_Guardioes_de_Eldoria;

public class Guerreiro extends Personagem {
    double força;

    public Guerreiro(String nome, int nivel, int pontosDeVida, Double poderBase, double força) {
        super(nome, "Guerreiro", nivel, pontosDeVida, poderBase);
        this.força = força;
    }

    @Override
    public void  exibirStatus() {
        super.exibirStatus();
        System.out.println("Força: " + força);
        System.out.println("----------------------------\n");
    }

    @Override
    public void usarHabilidadeEspecial() {
        System.out.println("Guerreiro " + nome + " ataca com Espada Flamejante!");
    }
}
