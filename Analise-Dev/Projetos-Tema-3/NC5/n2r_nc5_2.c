#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int opcao, numero_secreto, palpite, regras;

    printf("\nMenu Principal\n");
    printf("1: Iniciar Jogo\n");
    printf("2: Ver Regras\n");
    printf("3: Sair\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        srand(time(0));
        numero_secreto = rand() % 11;
        printf("Digite uma número 0 a 10: \n");
        scanf("%d", &palpite);
        if (numero_secreto == palpite) {
            printf("Você acertou!\n");
        } else {
            printf("Você errou!\n");
            printf("Número Secreto: %d\n", numero_secreto);
        }
        break;
    case 2:
        printf("As regras são...\n");
        printf("Digite as opções relacionadas as regras\n");
        scanf("%d", &regras);

        switch (regras)
        {
        case 1:
            printf("Regra 1\n");
            break;
        case 2:
            printf("Regra 2\n");
            break;
        case 3:
            printf("Regra 3\n");
            break;
        default:
            printf("Opção de regras inválida!\n");
            break;
        }
        
        break;
    case 3:
        printf("Saindo do jogo...\n");
        break;          
    default:
        printf("Opção inválido!");
        break;
    }
    
    return 0;
}