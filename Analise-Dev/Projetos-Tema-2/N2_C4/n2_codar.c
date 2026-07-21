#include <stdio.h>

int main(){
    float nota1, nota2, nota3;
    float media;

    printf("\n*** Progama de cálculo de Média ***\n");
    printf("\n");

    printf("Digite a sua primenra nota: \n");
    scanf("%f", &nota1);

    printf("\nDigite a sua segunda nota: \n");
    scanf("%f", &nota2);

    printf("\nDigite a sua terceira nota: \n");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;
    printf("\nA sua média é: %.1f\n", media);

    return 0;
}