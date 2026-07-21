#include <stdio.h>

int main(){
    int idade = 37;
    float altura = 1.75;
    char opcao = 'A';
    char nome[20] = "Adones Melo";

    printf("A idade do %s é: %d\n", nome, idade);
    printf("A idade é: %d\n", idade);
    printf("O nome é: %s\n", nome);
    printf("A altura é: %.2f\n", altura);
    printf("A opção é: %c\n", opcao);
}

/*
printf(“%formato1 %formato2”, variável1, variável2);

%d: Imprime um inteiro no formato decimal.
 
%i: Equivalente a %d.
 
%f: Imprime um número de ponto flutuante no formato padrão.
 
%e: Imprime um número de ponto flutuante na notação científica.
 
%c: Imprime um único caractere.
 
%s: Imprime uma cadeia (string) de caracteres.
*/