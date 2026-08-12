package ex006;

/*
Implemente uma classe chamada de Principal que possua dois métodos que utilize obrigatoriamente a propriedade de polimorfismo para obter o maior elemento de dois números e o maior elemento de três números.
*/

public class Principal {
    public  int maiorElemento(int a, int b) {
        int maior = a;
        if (b > maior) {
            maior = b;
        }
        return maior;
    }

    public int maiorElemento(int a, int b, int c) {
        int maior = maiorElemento(a, b);
        if (c > maior) {
            maior = c;
        }
        return maior;
    }

    public void main(String[] args) {
        Principal obj = new Principal();
        int a = 10;
        int b = 55;
        int c = 15;

        System.out.println("O maior número entre " + a + ", " + b + " é " + obj.maiorElemento(a, b));
        System.out.println("O maior número entre " + a + ", " + c + " é " + obj.maiorElemento(a, c));
        System.out.println("O maior número entre " + a + ", " + b + ", " + c + " é " + obj.maiorElemento(a, b, c)); 
    }
    
}
