package ex001_p;

public class Main {
    public static void main(String[] args) {
        // cria objetos
        Pessoa P1 = new Fisica(100, "123.456.789-00");
        Pessoa P2 = new Juridica(200, "12.345.678/0001-00");

        // atualiza identificadores
        P1.atualizarID();
        P2.atualizarID();

        // recupera identificadores
        int idFisica = P1.recuperarID();
        int idJuridica = P2.recuperarID();

        // imprime identificadores
        System.out.println("Novo ID para Pessoa Fisica: " + idFisica);
        System.out.println("Novo ID para Pessoa Juridica: " + idJuridica);
    }
}
