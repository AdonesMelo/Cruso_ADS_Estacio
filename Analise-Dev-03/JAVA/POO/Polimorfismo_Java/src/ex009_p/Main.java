package ex009_p;

// Interface externa
interface Veiculo {
    void acelerar();

    // Interface interna
    interface Motor {
        void ligar();
        void desligar();
    }
}


// Classe que implementa a interface externa
class Carro implements Veiculo {
    @Override
    public void acelerar() {
        System.out.println("Carro acelerando");
    }

    // Classe que implementa a interface interna
    class MotorCarro implements Veiculo.Motor {
        @Override
        public void ligar() {
            System.out.println("Motor de carro ligado");
        }

        @Override
        public void desligar() {
            System.out.println("Motor de carro desligado");
        }
    }
}


public class Main {
    public static void main(String[] args) {
        Carro carro = new Carro();
        carro.acelerar();

        // Criando um objeto da classe interna
        Carro.Motor motorCarro = carro.new MotorCarro();
        motorCarro.ligar();
        motorCarro.desligar();
    }
}

