package Agregacao;

public class Main {
    public static void main(String[] args) {
        Departamento d1 = new Departamento("Departamento de Tecnologia");
        
        Funcionario f1 = new Funcionario("João");
        Funcionario f2 = new Funcionario("Maria");
        Funcionario f3 = new Funcionario("Pedro");

        d1.adicionarFuncionario(f1);
        d1.adicionarFuncionario(f2);
        d1.adicionarFuncionario(f3);

        d1.getDados();
    }  
}
