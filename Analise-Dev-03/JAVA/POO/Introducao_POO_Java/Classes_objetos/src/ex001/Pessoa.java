package ex001;

import java.util.Random;

class Pessoa {
    // Atributos
    private  String nome;
    private double codigo_identificador;
    private Random aleatorio;

    // Métodos
    public Pessoa (String nome) {
        aleatorio = new Random();
        this.nome = nome;
        this.codigo_identificador = aleatorio.nextDouble();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getCodigo_identificador() {
        return codigo_identificador;
    }

    //
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("João");
        System.out.println("[Pessoa 1] Nome: " + p1.getNome() + ", Código Identificador: " + p1.getCodigo_identificador());

        Pessoa p2 = new Pessoa("Maria");
        System.out.println("[Pessoa 2] Nome: " + p2.getNome() + ", Código Identificador: " + p2.getCodigo_identificador());
    }
}