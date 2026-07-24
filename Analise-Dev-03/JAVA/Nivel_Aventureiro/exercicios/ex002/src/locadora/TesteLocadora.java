package locadora;

public class TesteLocadora {
    public static void main(String[] args) {
        Carro carro = new Carro("Fiat", "Novo Palio", "ABC-1234", 4);
        Moto moto = new Moto("Honda", "POP 110", "XYZ-4321", true);

        System.out.println(carro.getDescricao());
        System.out.println("Portas: " + carro.getQtdPortas() + "\n");

        System.out.println(moto.getDescricao());
        System.out.println("Possui Bau: " + moto.isPossuiBau() + "\n");
    }
}    

