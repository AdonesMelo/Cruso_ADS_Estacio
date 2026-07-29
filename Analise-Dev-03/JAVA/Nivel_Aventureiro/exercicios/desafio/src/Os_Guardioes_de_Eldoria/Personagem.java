package Os_Guardioes_de_Eldoria;

//Classe abstrata que define atributos comuns a todos os personagens
public abstract class Personagem {
    String nome;
    String classe;
    int nivel;
    int pontosDeVida;
    Double poderBase;

    public Personagem(String nome, String classe, int nivel, int pontosDeVida, Double poderBase) {
        this.nome = nome;
        this.classe = classe;
        this.nivel = nivel;
        this.pontosDeVida = pontosDeVida;
        this.poderBase = poderBase;
    }

    public void exibirStatus() {
        System.out.println("--- Status do Personagem ---");
        System.out.println("Nome: " + nome);
        System.out.println("Classe: " + classe);
        System.out.println("Nivel: " + nivel);
        System.out.println("Pontos de Vida: " + pontosDeVida);
        System.out.println("Poder Base: " + poderBase);
    }

    // Método abstrato
    public abstract void usarHabilidadeEspecial();
}

