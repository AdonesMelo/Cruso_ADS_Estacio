package ex006;

public class Main {
    public static void main(String[] args) {
        // cria objetos
        Pessoa P1 = new Pessoa ( "Paulo" , "2345" );
        Fisica A1 = new Fisica ( "Carlos" , "2345" );
        System.out.println ( P1.equals(A1) );
        System.out.println ( A1.equals(P1) );
    }
}

/*
Um programador define a classe Pessoa e a classe Fisica que a estende. 
Parte do código de Pessoa é exibido a seguir, junto de parte do código de Fisica. 
Sabe-se que Fisica não sobrescreve o método “equals”.
*/

/*
O método “equals” da classe Pessoa não é sobrescrito por Fisica, assim ela o herda como está em Pessoa. 
Esse método estabelece a comparação de objetos com base no atributo “identificador”. 
Como Fisica é subtipo de Pessoa e passa, no seu construtor, os valores para a superclasse, 
a comparação é possível e resulta e true e true.
*/
