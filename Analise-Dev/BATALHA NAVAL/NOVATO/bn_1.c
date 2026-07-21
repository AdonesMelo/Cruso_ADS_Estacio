#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};
    int linha = 3; 
    int coluna = 8; 

    // Posiciona o número 3 na linha 3 (índice 2) nas colunas D, E, F (índices 3, 4, 5)
    // Posição horizontal
    for (int i = 3; i <= 5; i++)
        tabuleiro[linha - 1][i] = 3;

    // Posiciona o número 3 na coluna H (índice 7) nas linhas 6, 7, 8 (índices 5, 6, 7)
    // Pocição vertical
    for (int j = 5; j <= 7; j++)
        tabuleiro[j][coluna - 1] = 3;

    printf("##### Jogo de Batalha Naval #####\n");
    printf("\n");

    // Imprime cabeçalho com letras
    printf("   "); // Espaço para alinhar com os números da coluna
    for (int i = 0; i < 10; i++){
        printf(" %c ", 'A' + i);
    }

    printf("\n");

    // imprime cada linha com número e os valores da matriz
    for (int j = 0; j < 10; j++) {
        printf("%2d ", 1 + j); // Imprime número da linha
        for (int i = 0; i < 10; i++) {
            printf(" %d ",tabuleiro[j][i] == 0 ? 0 : tabuleiro[j][i]); // Operador ternário
        }
        printf("\n");
    }
    return 0;
}
