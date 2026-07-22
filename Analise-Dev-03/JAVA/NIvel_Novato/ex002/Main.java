public class Main {
    public static void main(String[] args) {
        Usuario ui = new Usuario();
        ui.nome = "Joao";
        ui.email = "joao@joao.com";
        ui.senha = "123456";
        ui.fazeLogin();
    }
}

// roda no terminal: javac Usuario.java Main.java
// roda no terminal: java Main
