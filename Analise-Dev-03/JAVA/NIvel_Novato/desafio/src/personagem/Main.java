package personagem;

public class Main {
    public static void main(String[] args) {
        Personagem p1 = new Personagem("Thor", "Guerreiro", 5, 80, 12.5);
        Personagem p2 = new Personagem("Merlin", "Mago", 4, 90, 10.5);
        Personagem p3 = new Personagem("Legolas", "Arqueiro", 3, 100, 14.5);

        p1.exibirStatus();
        p2.exibirStatus();
        p3.exibirStatus();
    }
}
