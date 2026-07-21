#include <stdio.h>

int main(){
    int idade;

    printf("Digite a sua idade: \n");
    scanf("%d", &idade);

    // criança menor que 12
    // adolecente 12 a 17
    // adulto 18 a 59
    // idoso maior que 60

    if (idade < 12) {
        printf("Você é uma criança!\n");
    } else if (idade >= 12 && idade < 18) {
        printf("Você é um adolescente!\n");
    } else if (idade >= 18 && idade < 60) {
        printf("Você é um adulto!\n");
    } else {
        printf("Você é um idoso!\n");
    }

    printf("\n############################\n");
    
    if (idade >= 60) {
        printf("\nVocê é um idoso!\n");
    } else if (idade < 60 && idade >=18) {
        printf("\nVocê é um adulto!\n");
    } else if (idade < 18 && idade >= 12) {
        printf("\nVocê é um adolescente!\n");
    } else {
        printf("\nVocê é uma criança\n");
    }

    return 0;
}