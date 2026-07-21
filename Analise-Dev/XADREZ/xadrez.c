# include <stdio.h>

int main() {
    int torre = 1;
    int bispo = 1;
    int rainha = 1;
    int cavalo = 2;

    printf("Movimentos das peças de xadrez:\n");
    printf("\n");

    // Movimento da torre
    for (torre; torre <= 5; torre++) {
        printf("Direita\n");
    }
    // o numero de quantas vezes a torre se moveu
    printf("A torre moveu-se %d casas à direita\n", torre - 1);

    printf("\n#######################################\n");
    printf("\n");

    // Movimento do bispo
    while (bispo <= 5) {
        printf("Cima, Direita\n", bispo);
        bispo++;
    }
    printf("O bispo moveu-se %d casas na diagonal(Cima, Direita).\n", bispo - 1);

    printf("\n#######################################\n");
    printf("\n");

    // Movimento da rainha
    do {
        printf("Esquerda\n");
        rainha++;
    } while (rainha <= 8);
    printf("A rainha moveu-se %d casas para esquerda\n", rainha - 1);

    printf("\n#######################################\n");
    printf("\n");

    // Movimento do cavalo
    printf("O movimento do cavalo é em L:\n");
    while (cavalo == 2) {
        
         for (int cima = 0; cima < cavalo; cima++) {
            printf("Baixo\n");   
        }
        printf("Esquerda\n");
        cavalo++;
    }
    

    return 0;
}