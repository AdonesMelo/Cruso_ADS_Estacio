#include <stdio.h>

int main(){
    int idade;
    float renda;

    /*
    O progama verifica se a pessoa está qualificada para receber um desconto especial com base na sua idade na sua renda.
    A pessoa deve ter mais de 60 anos ou menos de 18 anos e ter uma renda mensal abaixo de 2000.
    */

    printf("Digite a sua idade: \n");
    scanf("%d", &idade);
    printf("Digite sua renda mensal: \n");
    scanf("%f", &renda);

    if ( idade <= 18 || idade >= 60) {
        if (renda < 2000) {
            printf("Você tem direito ao desconto!\n");
        } else {
            printf("Você não tem direito ao desconto, devido a sua renda!\n");
        }
    } else {
        printf("Você não atende os critérios com relação à idade!\n");
    }

    return 0;
}