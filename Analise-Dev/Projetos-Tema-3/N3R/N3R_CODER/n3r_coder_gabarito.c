#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num_jogador, num_cp, resultado;
    char tipo_comparacao;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    num_cp = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100

    // Inicializa o jogo
    printf("Bem-vindo ao jogo de maior, menor ou igual!\n");
    printf("Você deve escolher um número e o tipo de comparação.\n");
    printf("M: Maior\n");
    printf("N: menor\n");
    printf("I: Igual\n");

    printf("Escolha a comparação (M/N/I): ");
    scanf(" %c", &tipo_comparacao);

    printf("Digite um número entre 1 e 100: ");
    scanf("%d", &num_jogador);

    // Exibe o número do computador
    // printf("O número do computador é: %d\n", num_cp);

    switch (tipo_comparacao)
    {
    case 'M':
    case 'm':
        printf("Você escolheu a opcão Maior.\n");
        // Operador ternário para verificar se o número do jogador é maior que o do computador
        resultado = num_jogador > num_cp ? 1 : 0;
        break;
    case 'N':
    case 'n':
        printf("Você escolheu a opção Menor.\n");
        // Operador ternário para verificar se o número do jogador é menor que o do computador
        resultado = num_jogador < num_cp ? 1 : 0;
        break;
    case 'I':
    case 'i':
        printf("Você escolheu a opção Igual.\n");
        // Operador ternário para verificar se o número do jogador é igual ao do computador
        resultado = num_jogador == num_cp ? 1 : 0;
        break;
    
    default:
        printf("Opção inválida! Por favor, escolha M, N ou I.\n");

        break;
    }

    printf("O número do computador é: (%d) e o do jogador é: (%d)\n", num_cp, num_jogador);

    // Exibe o resultado da comparação
    if (resultado == 1) {
        printf("Parabéns! Você ganhou!\n");
    } else {
        printf("Você perdeu! Tente novamente.\n");
    }

    return 0;
}