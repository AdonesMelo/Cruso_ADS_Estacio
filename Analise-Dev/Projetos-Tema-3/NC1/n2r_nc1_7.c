#include <stdio.h>

int main(){
    int idade;
    float renda;
    int dependentes;

    // Primeira condição se a idade está entre 18 e 65 anos
    // Segunda condição se a renda é menor que 3000
    //Terceira condição se quantidade de dependentes é maior que 2

    printf("Digite a sua idade: \n");
    scanf("%d", &idade);
    printf("Digite a sua renda: \n");
    scanf("%f", &renda);
    printf("Digite a quantidade de dependentes: \n");
    scanf("%d", &dependentes);

    if (idade >= 18 && idade <= 65) {
        if (renda < 3000) {
            if (dependentes > 2 ) {
                printf("Você atende a todos os critérios!\n");
            } else {
                printf("Você não atende ao critério dependentes!\n");
            }
        } else {
            printf("Você não atende ao critério renda!\n");
        }

    } else {
        printf("Você não atende ao critério idade!\n");
    }
    
    return 0;
}