package personagem;

public class Personagem {
    String nome;
    String classe;
    Integer nivel;
    Integer pontosDeVida;
    Double PordeBase;

    public Personagem(String nome, String classe, Integer nivel, Integer pontosDeVida, Double PordeBase) {
        this.nome = nome;
        this.classe = classe;
        this.nivel = nivel;
        this.pontosDeVida = pontosDeVida;
        this.PordeBase = PordeBase;
    }

    public void exibirStatus() {
        System.out.println("---Status do Personagem---");
        System.out.println("Nome: " + nome);
        System.out.println("Classe: " + classe);
        System.out.println("Nivel: " + nivel);
        System.out.println("Pontos de Vida: " + pontosDeVida);
        System.out.println("Porde Base: " + PordeBase);
        System.out.println("----------------------------\n");
    }
}
