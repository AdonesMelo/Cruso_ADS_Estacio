package Os_Guardioes_de_Eldoria;

public class Mago extends Personagem {
    double inteligencia;

    public Mago(String nome, int nivel, int pontosDeVida, Double poderBase, double inteligencia) {
        super(nome, "Mago", nivel, pontosDeVida, poderBase);
        this.inteligencia = inteligencia;
    }

    @Override
    public void  exibirStatus() {
        super.exibirStatus();
        System.out.println("Inteligencia: " + inteligencia);
        System.out.println("----------------------------\n");
    }

    @Override
    public void usarHabilidadeEspecial() {
        System.out.println("Mago " + nome + " lança Bola de Fogo!"); 
    }
}
