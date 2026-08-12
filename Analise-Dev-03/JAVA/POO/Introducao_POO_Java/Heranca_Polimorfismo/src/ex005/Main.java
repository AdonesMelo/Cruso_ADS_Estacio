package ex005;

public class Main {
    public static void main(String[] args) {
        Data dataEmpregado = new Data(9, 9, 1988);
        Empregado empregado = new Empregado("João", dataEmpregado.toCalendar(), 123456789L, null);
        empregado.gerarMatricula();

        Data dataDiretor = new Data(4, 5, 1988);
        Diretor diretor = new Diretor("José", dataDiretor.toCalendar(), 98765432100L, null);
        diretor.gerarMatricula();

        System.out.println("A matricula do diretor é: " + diretor.recuperarMatricula());
        System.out.println("A matricula do empregado é: " + empregado.recuperarMatricula());
    }
}

