package hora_de_codar;

public class Main {
    public static void main(String[] args) {
        Veiculo vgenerico = new Veiculo("Ford", "Ranger-Raptor");
        System.out.println(vgenerico.descrever());

        Veiculo v1 = new Moto("Honda", "POP", 110);
        System.out.println(v1.descrever());

        Veiculo v2 = new Carro("Fiat", "Palio", 4);
        System.out.println(v2.descrever());

        Veiculo v3 = new Bicicleta("Caloi", "Vulcan", 26);
        System.out.println(v3.descrever());

        Veiculo[] veiculos = new Veiculo[3];
        veiculos[0] = new Moto("Yamaha", "MT-07", 700);
        veiculos[1] = new Carro("Ford", "Mustang", 4);
        veiculos[2] = new Bicicleta("Absolute", "Nero", 29);

        System.out.println("\n===Polimorfismo===");
        for (Veiculo v : veiculos) {
            System.out.println(v.descrever());
        }
    }
}
