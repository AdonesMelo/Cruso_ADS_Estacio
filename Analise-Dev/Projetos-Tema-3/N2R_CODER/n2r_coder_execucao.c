#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int escolhar_jogador, escolhar_pc;
    srand(time(0)); //Para gerar os números aleatorios

    printf("### Jogo Jokenpô ###\n");
    printf("Escolhar uma opção:\n");
    printf("1: Pedra\n");
    printf("2: papel\n");
    printf("3: Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &escolhar_jogador);

    escolhar_pc = rand() % 3 + 1;

    // Escolha do jogador
    switch (escolhar_jogador)
    {
    case 1:
        printf("Jogador: Pedra - ");
        break;
    case 2:
        printf("Jogador: Papel - ");
        break;
    case 3:
        printf("Jogador: Tesoura - ");
        break;
    
    default:
        printf("Opção inválida!\n");
        break;
    }

    // Escolha do pc 
    switch (escolhar_pc)
    {
    case 1:
        printf("PC: Pedra\n");
        break;
    case 2:
        printf("PC: Papel\n");
        break;
    case 3:
        printf("PC: Tesoura\n");
        break;
    }

    if (escolhar_pc == escolhar_jogador) {
        printf("### Jogo Empatou ###\n");
    } else if ((escolhar_jogador == 1) && (escolhar_pc == 3) || (escolhar_jogador == 2) && (escolhar_pc == 1) || (escolhar_jogador == 3) && (escolhar_pc == 2)) {
        printf("### Parabéns você venceu! ###\n");
    } else {
        printf("### Você perdeu! ###\n");
    }

    return 0;
}