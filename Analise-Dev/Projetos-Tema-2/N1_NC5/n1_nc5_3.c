#include <stdio.h>

int main(){
    int idade;
    float altura;
    char opçao;
    char nome[20];

    //scanf(''formato'', &variavel);

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("A idade é: %d\n", idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("A altura é: %.2f\n", altura);

    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("O nome é: %s\n", nome);

    printf("Digite a opção: ");
    scanf(" %c", &opçao);
    printf("A opção é: %c", opçao);
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