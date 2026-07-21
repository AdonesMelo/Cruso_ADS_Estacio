# include <stdio.h>

int main(){
    /*
    Soma(+)
    Subtração(-)
    Multiplicação(*)
    Divisão(/)
    */
    int num_1, num_2;
    int soma, subtracao, multiplicacao, divisao;

    printf("Entre como número 1: \n");
    scanf("%d", &num_1);
    printf("Entre como número 2: \n");
    scanf("%d", &num_2);

    // Operação soma
    soma = num_1 + num_2;

    // Operação subtração
    subtracao = num_1 - num_2;

    // Operação multiplicação
    multiplicacao = num_1 * num_2;

    // Operação divisão
    divisao = num_1 / num_2;

    printf("A soma é: %d\n", soma);
    printf("A subtração é: %d\n", subtracao);
    printf("A multiplicação é: %d\n", multiplicacao);
    printf("A divisão é: %d\n", divisao);

}