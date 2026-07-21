# include <stdio.h>

int main(){
    int a = 10;
    int b = 5;

    // Operadores aritméticos
    int soma = a + b;
    int subtracao = a - b;
    int mutiplicacao = a * b;
    int divisao = a / b;

    // Operadores de atribuição
    a += 2; // "a" séra igual 12
    b *= 3; // "b" séra igual 15

    // Operadores de incremento e descremento
    a ++; // "a" séra igual 13
    b --; // "b" séra igual 14

    // Exibir os resultados
    printf("Soma: %d\n", soma);
    printf("Subtração: %d\n", subtracao);
    printf("Multiplicação: %d\n", mutiplicacao);
    printf("Divisão: %d\n", divisao);
    printf("Incremento de 'a'(após += 2 e ++): %d\n", a);
    printf("Descremento de 'b'(após *= 3 e --): %d\n", b);

    return 0;
}